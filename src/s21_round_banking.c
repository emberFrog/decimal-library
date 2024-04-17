#include "s21_decimal.h"

s21_decimal s21_round_banking(s21_decimal integral, s21_decimal fractional) {
  s21_decimal zerofive = s21_get_zero_point_five_for_decimal();
  s21_decimal result;

  if (s21_is_equal(fractional, zerofive)) {
    if (s21_decimal_even(integral)) {
      result = integral;
    } else {
      result = s21_binary_addition_int128(integral, s21_get_one_for_decimal());
    }
  } else if (s21_is_greater(fractional, zerofive)) {
    result = s21_binary_addition_int128(integral, s21_get_one_for_decimal());
  } else {
    result = integral;
  }

  return result;
}
