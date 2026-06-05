#ifndef PACKET_H
#define PACKET_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MIN_PACKET_SIZE 64
#define MAX_PACKET_SIZE 1500

typedef struct {

  uint32_t id;
  uint32_t source_id;
  size_t size;
  uint64_t arrival_time;

} Packet;

bool createPacket(Packet *packet, uint32_t source_id, size_t size);

#endif
