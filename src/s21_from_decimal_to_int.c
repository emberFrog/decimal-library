#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_conversion_result ERROR_CODE = S21_CONVERSION_OK;

  if (!dst) {
    ERROR_CODE = S21_CONVERSION_ERROR;
  } else if (!s21_check_decimal(src)) {
    ERROR_CODE = S21_CONVERSION_ERROR;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated_decimal = s21_get_zero_for_decimal();
    s21_truncate(src, &truncated_decimal);

    if (s21_is_less(truncated_decimal, s21_get_int_min_for_decimal()) ==
        S21_COMPARISON_TRUE) {
      ERROR_CODE = S21_CONVERSION_ERROR;
    } else if (s21_is_greater(truncated_decimal,
                              s21_get_int_max_for_decimal()) ==
               S21_COMPARISON_TRUE) {
      ERROR_CODE = S21_CONVERSION_ERROR;
    } else {
      for (int i = 0; i < MAX_BITS_FOR_NUMBER; i++) {
        if (s21_decimal_is_set_bit(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }

      if (s21_get_sign_decimal(src) == S21_NEGATIVE && *dst != -2147483648) {
        *dst = -*dst;
      }
    }
  }

  return ERROR_CODE;
}
