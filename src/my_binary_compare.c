#include "my_decimal.h"

int my_binary_equal_zero_int128(my_decimal decimal) {
  return decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0 &&
         decimal.bits[3] == 0;
}

int my_binary_compare_int128(my_decimal d1, my_decimal d2) {
  int result = 0;

  for (int i = MAX_BITS - 1; i >= 0; i--) {
    int b1 = my_decimal_is_set_bit(d1, i);
    int b2 = my_decimal_is_set_bit(d2, i);

    if (b1 == 0 && b2 != 0) {
      result = -1;
    }

    if (b1 != 0 && b2 == 0) {
      result = 1;
    }

    if (result != 0) {
      break;
    }
  }

  return result;
}

int my_binary_compare_int256(my_int256 d1, my_int256 d2) {
  int compare = my_binary_compare_int128(d1.decimals[1], d2.decimals[1]);

  if (compare == 0) {
    compare = my_binary_compare_int128(d1.decimals[0], d2.decimals[0]);
  }

  return compare;
}
