#include <limits.h>

#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_conversion_result ERROR_CODE = S21_CONVERSION_OK;

  if (!dst) {
    ERROR_CODE = S21_CONVERSION_ERROR;
  } else {
    *dst = s21_get_zero_for_decimal();
    int sign;

    if (src < 0) {
      sign = S21_NEGATIVE;
      if (src != INT_MIN) {
        src = -src;
      }
    } else {
      sign = S21_POSITIVE;
    }

    dst->bits[0] = src;
    s21_set_sign_for_decimal(dst, sign);
  }

  return ERROR_CODE;
}
