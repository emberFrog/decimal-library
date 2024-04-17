#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result ERROR_CODE = S21_ARITHMETIC_OK;

  if (!result) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
  } else if (!s21_check_decimal(value_1) || !s21_check_decimal(value_2)) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
    *result = s21_get_inf_for_decimal();
  } else if (s21_is_equal(value_2, s21_get_zero_for_decimal())) {
    ERROR_CODE = S21_ARITHMETIC_DIVISION_BY_ZERO;
    *result = s21_get_inf_for_decimal();
  } else if (s21_is_less(s21_abs(value_1), s21_abs(value_2))) {
    ERROR_CODE = S21_ARITHMETIC_OK;
    *result = value_1;
  } else {
    *result = s21_get_zero_for_decimal();

    int sign1 = s21_get_sign_decimal(value_1);
    int power1 = s21_get_power_of_decimal(value_1);
    int power2 = s21_get_power_of_decimal(value_2);
    int max_power = s21_max(power1, power2);
    s21_int256 value_1l;
    s21_int256 value_2l;
    s21_int256 remainder =
        s21_create_int256_from_decimal(s21_get_zero_for_decimal());

    s21_decimal_leveling(value_1, value_2, &value_1l, &value_2l);
    s21_binary_division_int256(value_1l, value_2l, &remainder);
    s21_set_power_for_decimal(&remainder.decimals[0], max_power);

    *result = remainder.decimals[0];
    s21_set_sign_for_decimal(result, sign1);
  }

  return ERROR_CODE;
}
