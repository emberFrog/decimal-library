#include "s21_decimal.h"

s21_int256 s21_binary_multiplication_int128(s21_decimal decimal1,
                                            s21_decimal decimal2) {
  s21_int256 int256_result =
      s21_create_int256_from_decimal(s21_get_zero_for_decimal());
  s21_int256 int256_tmp1 = s21_create_int256_from_decimal(decimal1);

  int max_bit = s21_decimal_get_not_zero_bit(decimal2);

  for (int i = 0; i <= max_bit; i++) {
    if (s21_decimal_is_set_bit(decimal2, i) != 0) {
      int256_result = s21_binary_addition_int256(int256_result, int256_tmp1);
    }
    int256_tmp1 = s21_binary_shift_left_int256(int256_tmp1, 1);
  }

  return int256_result;
}

s21_int256 s21_binary_multiplication_int256(s21_int256 decimal1,
                                            s21_decimal decimal2) {
  s21_int256 int256_result =
      s21_create_int256_from_decimal(s21_get_zero_for_decimal());
  s21_int256 int256_tmp1 = decimal1;

  int max_bit = s21_decimal_get_not_zero_bit(decimal2);

  for (int i = 0; i <= max_bit; i++) {
    if (s21_decimal_is_set_bit(decimal2, i) != 0) {
      int256_result = s21_binary_addition_int256(int256_result, int256_tmp1);
    }

    int256_tmp1 = s21_binary_shift_left_int256(int256_tmp1, 1);
  }

  return int256_result;
}
