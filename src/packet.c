#include "packet.h"
#include "timer.h"

static uint32_t next_packet_id = 1;

static bool isValidPacketSize(size_t size) {
  return size >= MIN_PACKET_SIZE && size <= MAX_PACKET_SIZE;
}

bool createPacket(Packet *packet, uint32_t source_id, size_t size) {
  if (!isValidPacketSize(size))
    return false;

  packet->id = next_packet_id++;
  packet->source_id = source_id;
  packet->size = size;
  packet->arrival_time = currentMillis();

  return true;
}
