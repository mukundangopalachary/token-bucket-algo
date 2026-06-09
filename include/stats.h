#ifndef STATS_H
#define STATS_H
#include <stdint.h>
typedef struct {
  uint64_t packets_generated;
  uint64_t packets_queued;
  uint64_t packets_transmitted;
  uint64_t packets_dropped;
  uint64_t queue_overflow_drops;
  uint64_t token_bucket_drops;
  uint64_t bytes_generated;
  uint64_t bytes_transmitted;
  uint64_t bytes_dropped;
} Statistics;

void initStats(Statistics *stats);

void printStats(const Statistics *stats);

#endif
