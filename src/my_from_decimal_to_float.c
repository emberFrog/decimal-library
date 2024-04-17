#include <math.h>

#include "my_decimal.h"

int my_from_decimal_to_float(my_decimal src, float *dst) {
  my_conversion_result ERROR_CODE = MY_CONVERSION_OK;
  if (!dst) {
    ERROR_CODE = MY_CONVERSION_ERROR;
  } else if (!my_check_decimal(src)) {
    ERROR_CODE = MY_CONVERSION_ERROR;
    *dst = 0.0;
  } else if (my_is_equal(src, my_get_zero_for_decimal())) {
    int sign = my_get_sign_decimal(src);
    if (sign == MY_NEGATIVE) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    ERROR_CODE = MY_CONVERSION_OK;
  } else {
    *dst = 0.0;
    double tmp = 0.0;
    int sign = my_get_sign_decimal(src);
    int power = my_get_power_of_decimal(src);

    for (int i = 0; i < MAX_BITS_FOR_NUMBER; i++) {
      if (my_decimal_is_set_bit(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }

    double powerten = pow(10, power);
    tmp /= powerten;

    if (sign == MY_NEGATIVE) {
      tmp *= -1.0;
    }

    *dst = (float)tmp;
  }

  return ERROR_CODE;
}
