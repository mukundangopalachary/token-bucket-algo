#define _POSIX_C_SOURCE 200809L
#include "timer.h"

#ifdef _WIN32

#include <windows.h>

uint64_t currentMillis() { return GetTickCount64(); }

#else
#include <time.h>

uint64_t currentMillis() {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);

  return ((uint64_t)ts.tv_sec * 1000ULL) + ((uint64_t)ts.tv_nsec / 1000000ULL);
}

#endif
