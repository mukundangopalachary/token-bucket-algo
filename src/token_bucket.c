#include "token_bucket.h"
#include "timer.h"

void initBucket(TokenBucket *bucket, double capacity, double fill_rate) {
  bucket->capacity = capacity;
  bucket->fill_rate = fill_rate;
  bucket->tokens = bucket->capacity;
  bucket->last_refill = currentMillis();
}

void refillBucket(TokenBucket *bucket) {
  uint64_t now = currentMillis();
  uint64_t elapsed_time = now - bucket->last_refill;
  double tokens_to_add = (bucket->fill_rate / 1000) * elapsed_time;

  bucket->tokens += tokens_to_add;

  if (bucket->tokens > bucket->capacity) {
    bucket->tokens = bucket->capacity;
  }

  bucket->last_refill = now;
}

bool hasEnoughTokens(TokenBucket *bucket, double required_tokens) {
  return bucket->tokens >= required_tokens;
}

bool consumeTokens(TokenBucket *bucket, double required_tokens) {
  refillBucket(bucket);

  if (hasEnoughTokens(bucket, required_tokens)) {
    bucket->tokens -= required_tokens;
    return true;
  }

  return false;
}
