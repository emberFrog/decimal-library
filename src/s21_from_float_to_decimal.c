#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_conversion_result ERROR_CODE = S21_CONVERSION_OK;
  if (!dst) {
    ERROR_CODE = S21_CONVERSION_ERROR;
  } else if (src == 0.0) {
    ERROR_CODE = S21_CONVERSION_OK;
    *dst = s21_get_zero_for_decimal();
    if (signbit(src) != 0) {
      s21_set_sign_for_decimal(dst, S21_NEGATIVE);
    }
  } else if (isinf(src) || isnan(src)) {
    ERROR_CODE = S21_CONVERSION_ERROR;
    *dst = s21_get_inf_for_decimal();
    if (signbit(src) != 0) {
      s21_set_sign_for_decimal(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    ERROR_CODE = S21_CONVERSION_ERROR;
    *dst = s21_get_inf_for_decimal();
    if (signbit(src) != 0) {
      s21_set_sign_for_decimal(dst, S21_NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    ERROR_CODE = S21_CONVERSION_ERROR;
    *dst = s21_get_zero_for_decimal();
  } else {
    *dst = s21_get_zero_for_decimal();
    s21_decimal result;
    char flt[64];

    sprintf(flt, "%.6E", fabsf(src));
    int exp = s21_get_float_exp_from_string(flt);
    if (exp <= -23) {
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }

    result = s21_float_string_to_decimal(flt);

    if (signbit(src) != 0) {
      s21_set_sign_for_decimal(&result, S21_NEGATIVE);
    }

    *dst = result;
  }

  return ERROR_CODE;
}
