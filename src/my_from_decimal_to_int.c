#include <math.h>
#include <stdio.h>

#include "my_decimal.h"

int my_from_decimal_to_int(my_decimal src, int *dst) {
  my_conversion_result ERROR_CODE = MY_CONVERSION_OK;

  if (!dst) {
    ERROR_CODE = MY_CONVERSION_ERROR;
  } else if (!my_check_decimal(src)) {
    ERROR_CODE = MY_CONVERSION_ERROR;
    *dst = 0;
  } else {
    *dst = 0;
    my_decimal truncated_decimal = my_get_zero_for_decimal();
    my_truncate(src, &truncated_decimal);

    if (my_is_less(truncated_decimal, my_get_int_min_for_decimal()) ==
        MY_COMPARISON_TRUE) {
      ERROR_CODE = MY_CONVERSION_ERROR;
    } else if (my_is_greater(truncated_decimal,
                              my_get_int_max_for_decimal()) ==
               MY_COMPARISON_TRUE) {
      ERROR_CODE = MY_CONVERSION_ERROR;
    } else {
      for (int i = 0; i < MAX_BITS_FOR_NUMBER; i++) {
        if (my_decimal_is_set_bit(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }

      if (my_get_sign_decimal(src) == MY_NEGATIVE && *dst != -2147483648) {
        *dst = -*dst;
      }
    }
  }

  return ERROR_CODE;
}
