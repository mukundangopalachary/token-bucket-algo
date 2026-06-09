#include "stats.h"
#include <stdio.h>

void initStats(Statistics *stats) {
  stats->packets_generated = 0;
  stats->packets_queued = 0;
  stats->packets_transmitted = 0;
  stats->packets_dropped = 0;
  stats->queue_overflow_drops = 0;
  stats->token_bucket_drops = 0;
  stats->bytes_generated = 0;
  stats->bytes_transmitted = 0;
  stats->bytes_dropped = 0;
}

void printStats(const Statistics *stats) {
  printf("\n========== Simulation Statistics ==========\n");

  printf("Packets Generated   : %llu\n",
         (unsigned long long)stats->packets_generated);

  printf("Packets Queued      : %llu\n",
         (unsigned long long)stats->packets_queued);

  printf("Packets Transmitted : %llu\n",
         (unsigned long long)stats->packets_transmitted);

  printf("Packets Dropped     : %llu\n",
         (unsigned long long)stats->packets_dropped);

  printf("\n");

  printf("Queue Overflow Drops : %llu\n",
         (unsigned long long)stats->queue_overflow_drops);

  printf("Token Bucket Drops   : %llu\n",
         (unsigned long long)stats->token_bucket_drops);

  printf("\n");

  printf("Bytes Generated     : %llu\n",
         (unsigned long long)stats->bytes_generated);

  printf("Bytes Transmitted   : %llu\n",
         (unsigned long long)stats->bytes_transmitted);

  printf("Bytes Dropped       : %llu\n",
         (unsigned long long)stats->bytes_dropped);

  printf("\n===========================================\n");
}
