#include "s21_decimal.h"

int s21_binary_equal_zero_int128(s21_decimal decimal) {
  return decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0 &&
         decimal.bits[3] == 0;
}

int s21_binary_compare_int128(s21_decimal d1, s21_decimal d2) {
  int result = 0;

  for (int i = MAX_BITS - 1; i >= 0; i--) {
    int b1 = s21_decimal_is_set_bit(d1, i);
    int b2 = s21_decimal_is_set_bit(d2, i);

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

int s21_binary_compare_int256(s21_int256 d1, s21_int256 d2) {
  int compare = s21_binary_compare_int128(d1.decimals[1], d2.decimals[1]);

  if (compare == 0) {
    compare = s21_binary_compare_int128(d1.decimals[0], d2.decimals[0]);
  }

  return compare;
}
