#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_other_result ERROR_CODE = S21_OTHER_OK;

  if (!result) {
    ERROR_CODE = S21_OTHER_ERROR;
  } else if (!s21_check_decimal(value)) {
    ERROR_CODE = S21_OTHER_ERROR;
    *result = s21_get_inf_for_decimal();
  } else {
    *result = s21_get_zero_for_decimal();
    int sign = s21_get_sign_decimal(value);
    s21_decimal fractional;
    s21_decimal value_unsigned_truncated;
    s21_decimal value_unsigned = s21_abs(value);
    s21_truncate(value_unsigned, &value_unsigned_truncated);

    s21_sub(value_unsigned, value_unsigned_truncated, &fractional);

    value_unsigned_truncated =
        s21_round_banking(value_unsigned_truncated, fractional);

    *result = value_unsigned_truncated;
    s21_set_sign_for_decimal(result, sign);
  }

  return ERROR_CODE;
}
