#include <math.h>

#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  s21_conversion_result ERROR_CODE = S21_CONVERSION_OK;
  if (!dst) {
    ERROR_CODE = S21_CONVERSION_ERROR;
  } else if (!s21_check_decimal(src)) {
    ERROR_CODE = S21_CONVERSION_ERROR;
    *dst = 0.0;
  } else if (s21_is_equal(src, s21_get_zero_for_decimal())) {
    int sign = s21_get_sign_decimal(src);
    if (sign == S21_NEGATIVE) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    ERROR_CODE = S21_CONVERSION_OK;
  } else {
    *dst = 0.0;
    double tmp = 0.0;
    int sign = s21_get_sign_decimal(src);
    int power = s21_get_power_of_decimal(src);

    for (int i = 0; i < MAX_BITS_FOR_NUMBER; i++) {
      if (s21_decimal_is_set_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }

    double powerten = pow(10, power);
    tmp /= powerten;

    if (sign == S21_NEGATIVE) {
      tmp *= -1.0;
    }

    *dst = (float)tmp;
  }

  return ERROR_CODE;
}
