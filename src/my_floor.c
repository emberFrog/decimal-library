#include "my_decimal.h"

int my_floor(my_decimal value, my_decimal *result) {
  my_other_result ERROR_CODE = MY_OTHER_OK;

  if (!result) {
    ERROR_CODE = MY_OTHER_ERROR;
  } else if (!my_check_decimal(value)) {
    ERROR_CODE = MY_OTHER_ERROR;
    *result = my_get_inf_for_decimal();
  } else {
    *result = my_get_zero_for_decimal();
    int sign = my_get_sign_decimal(value);
    my_decimal fractional;
    my_decimal value_unsigned_truncated;
    my_decimal value_unsigned = my_abs(value);

    my_truncate(value_unsigned, &value_unsigned_truncated);

    my_sub(value_unsigned, value_unsigned_truncated, &fractional);

    if (sign == MY_NEGATIVE &&
        my_is_greater(fractional, my_get_zero_for_decimal())) {
      my_add(value_unsigned_truncated, my_get_one_for_decimal(),
              &value_unsigned_truncated);
    }

    *result = value_unsigned_truncated;
    my_set_sign_for_decimal(result, sign);
  }

  return ERROR_CODE;
}
