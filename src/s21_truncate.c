#include <stdlib.h>

#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_other_result ERROR_CODE = S21_OTHER_OK;

  if (!result) {
    ERROR_CODE = S21_OTHER_ERROR;
  } else if (!s21_check_decimal(value)) {
    ERROR_CODE = S21_OTHER_ERROR;
    *result = s21_get_inf_for_decimal();
  } else {
    *result = s21_get_zero_for_decimal();
    int power = s21_get_power_of_decimal(value);
    s21_decimal tmp = value;
    s21_decimal_null_service_bits(&tmp);

    tmp = s21_binary_division_int128(tmp, s21_get_ten_for_int128(power), NULL);

    *result = tmp;
    if (s21_get_sign_decimal(value) == S21_NEGATIVE) {
      s21_set_sign_for_decimal(result, S21_NEGATIVE);
    }
  }

  return ERROR_CODE;
}
