#include "s21_decimal.h"

s21_decimal s21_binary_subtraction_int128(s21_decimal decimal1,
                                          s21_decimal decimal2) {
  s21_decimal result;
  decimal2 = s21_binary_not_int128(decimal2);
  decimal2 = s21_binary_addition_int128(decimal2, s21_get_one_for_decimal());
  result = s21_binary_addition_int128(decimal1, decimal2);

  return result;
}

s21_int256 s21_binary_subtraction_int256(s21_int256 decimal1,
                                         s21_int256 decimal2) {
  s21_int256 result;
  decimal2.decimals[0] = s21_binary_not_int128(decimal2.decimals[0]);
  decimal2.decimals[1] = s21_binary_not_int128(decimal2.decimals[1]);

  s21_int256 one = s21_create_int256_from_decimal(s21_get_one_for_decimal());

  decimal2 = s21_binary_addition_int256(decimal2, one);
  result = s21_binary_addition_int256(decimal1, decimal2);

  return result;
}
