#include "s21_decimal.h"

s21_decimal s21_binary_addition_int128(s21_decimal decimal1,
                                       s21_decimal decimal2) {
  s21_decimal result = decimal1;
  s21_decimal tmp = decimal2;

  while (!s21_binary_equal_zero_int128(tmp)) {
    s21_decimal overflow_bits = s21_binary_and_int128(result, tmp);
    overflow_bits = s21_binary_shift_left_int128(overflow_bits, 1);
    result = s21_binary_xor_int128(result, tmp);
    tmp = overflow_bits;
  }

  return result;
}

s21_int256 s21_binary_addition_int256(s21_int256 decimal1,
                                      s21_int256 decimal2) {
  s21_int256 result = decimal1;
  s21_int256 tmp = decimal2;

  while (!s21_binary_equal_zero_int128(tmp.decimals[0]) ||
         !s21_binary_equal_zero_int128(tmp.decimals[1])) {
    s21_int256 overflow_bits;
    overflow_bits.decimals[0] =
        s21_binary_and_int128(result.decimals[0], tmp.decimals[0]);
    overflow_bits.decimals[1] =
        s21_binary_and_int128(result.decimals[1], tmp.decimals[1]);

    overflow_bits = s21_binary_shift_left_int256(overflow_bits, 1);
    result.decimals[0] =
        s21_binary_xor_int128(result.decimals[0], tmp.decimals[0]);
    result.decimals[1] =
        s21_binary_xor_int128(result.decimals[1], tmp.decimals[1]);

    tmp = overflow_bits;
  }

  return result;
}
