#include "timer.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  uint64_t t1 = currentMillis();

#ifdef _WIN32
  Sleep(1000);
#else
  sleep(1);
#endif

  uint64_t t2 = currentMillis();

  printf("Elapsed: %llu ms\n", (unsigned long long)(t2 - t1));

  return 0;
}
