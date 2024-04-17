#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result ERROR_CODE = S21_COMPARISON_FALSE;

  int sign1 = s21_get_sign_decimal(value_1);
  int sign2 = s21_get_sign_decimal(value_2);

  if (s21_is_equal(value_1, s21_get_zero_for_decimal()) &&
      s21_is_equal(value_2, s21_get_zero_for_decimal())) {
    ERROR_CODE = S21_COMPARISON_FALSE;
  } else if (sign1 == S21_NEGATIVE && sign2 == S21_POSITIVE) {
    ERROR_CODE = S21_COMPARISON_TRUE;
  } else if (sign1 == S21_POSITIVE && sign2 == S21_NEGATIVE) {
    ERROR_CODE = S21_COMPARISON_FALSE;
  } else if (sign1 == S21_NEGATIVE && sign2 == S21_NEGATIVE) {
    ERROR_CODE = s21_is_less_handle(s21_abs(value_2), s21_abs(value_1));
  } else {
    ERROR_CODE = s21_is_less_handle(value_1, value_2);
  }

  return ERROR_CODE;
}

int s21_is_less_handle(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result ERROR_CODE = S21_COMPARISON_FALSE;
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;
  s21_int256 tmp1l;
  s21_int256 tmp2l;

  s21_decimal_leveling(tmp1, tmp2, &tmp1l, &tmp2l);

  int compare = s21_binary_compare_int256(tmp1l, tmp2l);

  if (compare == -1) {
    ERROR_CODE = S21_COMPARISON_TRUE;
  } else {
    ERROR_CODE = S21_COMPARISON_FALSE;
  }

  return ERROR_CODE;
}
