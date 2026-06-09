#include "traffic_generator.h"

#include <stdlib.h>
#include <time.h>

void initTrafficGenerator(void) { srand((unsigned int)time(NULL)); }

size_t generatePacketSize(void) {
  return (rand() % (MAX_PACKET_SIZE - MIN_PACKET_SIZE + 1)) + MIN_PACKET_SIZE;
}

uint32_t generateSourceId(TrafficMode mode) {

  switch (mode) {

  case TRAFFIC_NORMAL:
    return 1;

  case TRAFFIC_BURST:
    return (rand() % 10) + 1;

  case TRAFFIC_DDOS:
    return (rand() % 1000) + 1;

  default:
    return 1;
  }
}

bool generatePacket(Packet *packet, TrafficMode mode) {

  uint32_t source_id = generateSourceId(mode);

  size_t packet_size = generatePacketSize();

  return createPacket(packet, source_id, packet_size);
}
