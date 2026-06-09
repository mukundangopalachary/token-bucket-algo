#include "packet.h"
#include "queue.h"
#include "stats.h"
#include "token_bucket.h"
#include "traffic_generator.h"

#define SIMULATION_PACKETS 10000
#define QUEUE_CAPACITY 1000

int main() {

  PacketQueue queue;
  Statistics stats;
  TokenBucket bucket;

  initQueue(&queue, QUEUE_CAPACITY);

  initStats(&stats);

  initBucket(&bucket,
             10000, // bucket capacity (bytes)
             5000   // refill rate (bytes/sec)
  );

  initTrafficGenerator();

  for (int i = 0; i < SIMULATION_PACKETS; i++) {

    Packet packet;

    if (!generatePacket(&packet, TRAFFIC_DDOS))
      continue;

    stats.packets_generated++;
    stats.bytes_generated += packet.size;

    if (!enqueue(&queue, packet)) {

      stats.packets_dropped++;
      stats.queue_overflow_drops++;
      stats.bytes_dropped += packet.size;

      continue;
    }

    stats.packets_queued++;

    Packet front_packet;

    if (peek(&queue, &front_packet)) {

      if (consumeTokens(&bucket, front_packet.size)) {

        dequeue(&queue, &front_packet);

        stats.packets_transmitted++;
        stats.bytes_transmitted += front_packet.size;
      }
    }
  }

  Packet remaining_packet;

  while (peek(&queue, &remaining_packet)) {

    if (consumeTokens(&bucket, remaining_packet.size)) {

      dequeue(&queue, &remaining_packet);

      stats.packets_transmitted++;
      stats.bytes_transmitted += remaining_packet.size;
    } else {

      stats.packets_dropped++;
      stats.token_bucket_drops++;
      stats.bytes_dropped += remaining_packet.size;

      dequeue(&queue, &remaining_packet);
    }
  }

  printStats(&stats);

  destroyQueue(&queue);

  return 0;
}
