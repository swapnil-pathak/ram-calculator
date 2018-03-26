#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER 100

int flag = 0;
float ideal_time = 0;

int main() {
  int pgsize = 0;
  int notif_flag = 0;
  unsigned long long ram = 0;
  clock_t start, time_taken;
  unsigned long long iter = 0;
  if ((pgsize = sysconf(_SC_PAGESIZE)) == -1) {
    pgsize = 4096; //Pagesize
  }
  FILE *fd = fopen("memory_calculation","w");
  int r = rand();
  while (flag != 1) {
    ++iter;
    start = clock();
    void *mem = malloc(100 * pgsize);
    memset(mem, r, 100 * pgsize);
    time_taken = clock() - start;

    if (ideal_time == 0) {
      ideal_time = time_taken;
    }

    if ((time_taken / ideal_time) >= 2) {
      ++notif_flag;
    }

    if (notif_flag >= BUFFER) {
      flag = 1;
    }

    fprintf(fd, "%llu MB\n", ram);
    ram = ((iter * pgsize * 100)/1000000);
  }
  printf("Ram size is %llu MB\n",ram);
  fflush(stdout);
  return 0;
}
