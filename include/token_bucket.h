#ifndef TOKEN_BUCKET_H
#define TOKEN_BUCKET_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  double capacity;
  double tokens;
  uint64_t last_refill;
  double fill_rate;
} TokenBucket;

void initBucket(TokenBucket *bucket, double capacity, double fill_rate);

void refillBucket(TokenBucket *bucket);

// triggers refillBucket + packet -> queue
bool hasEnoughTokens(TokenBucket *bucket, double required_tokens);

bool consumeTokens(TokenBucket *bucket, double required_tokens);

#endif
