#include <math.h>
#include <stdio.h>

#include "my_decimal.h"

int my_from_float_to_decimal(float src, my_decimal *dst) {
  my_conversion_result ERROR_CODE = MY_CONVERSION_OK;
  if (!dst) {
    ERROR_CODE = MY_CONVERSION_ERROR;
  } else if (src == 0.0) {
    ERROR_CODE = MY_CONVERSION_OK;
    *dst = my_get_zero_for_decimal();
    if (signbit(src) != 0) {
      my_set_sign_for_decimal(dst, MY_NEGATIVE);
    }
  } else if (isinf(src) || isnan(src)) {
    ERROR_CODE = MY_CONVERSION_ERROR;
    *dst = my_get_inf_for_decimal();
    if (signbit(src) != 0) {
      my_set_sign_for_decimal(dst, MY_NEGATIVE);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    ERROR_CODE = MY_CONVERSION_ERROR;
    *dst = my_get_inf_for_decimal();
    if (signbit(src) != 0) {
      my_set_sign_for_decimal(dst, MY_NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    ERROR_CODE = MY_CONVERSION_ERROR;
    *dst = my_get_zero_for_decimal();
  } else {
    *dst = my_get_zero_for_decimal();
    my_decimal result;
    char flt[64];

    sprintf(flt, "%.6E", fabsf(src));
    int exp = my_get_float_exp_from_string(flt);
    if (exp <= -23) {
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }

    result = my_float_string_to_decimal(flt);

    if (signbit(src) != 0) {
      my_set_sign_for_decimal(&result, MY_NEGATIVE);
    }

    *dst = result;
  }

  return ERROR_CODE;
}
