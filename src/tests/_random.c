#include <stdlib.h>

int my_random_int(int min, int max) {
  if (min < 0) {
    min = 0;
  }

  if (max < 0) {
    max = -max;
  }

  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
