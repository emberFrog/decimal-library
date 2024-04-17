#include <limits.h>

#include "my_decimal.h"

int my_from_int_to_decimal(int src, my_decimal *dst) {
  my_conversion_result ERROR_CODE = MY_CONVERSION_OK;

  if (!dst) {
    ERROR_CODE = MY_CONVERSION_ERROR;
  } else {
    *dst = my_get_zero_for_decimal();
    int sign;

    if (src < 0) {
      sign = MY_NEGATIVE;
      if (src != INT_MIN) {
        src = -src;
      }
    } else {
      sign = MY_POSITIVE;
    }

    dst->bits[0] = src;
    my_set_sign_for_decimal(dst, sign);
  }

  return ERROR_CODE;
}
