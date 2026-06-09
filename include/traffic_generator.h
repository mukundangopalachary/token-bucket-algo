#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include "packet.h"
#include <stdint.h>

typedef enum { TRAFFIC_NORMAL, TRAFFIC_BURST, TRAFFIC_DDOS } TrafficMode;

void initTrafficGenerator(void);

size_t generatePacketSize(void);

uint32_t generateSourceId(TrafficMode mode);

bool generatePacket(Packet *packet, TrafficMode mode);

#endif
