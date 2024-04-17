#include "my_decimal.h"

int my_round(my_decimal value, my_decimal *result) {
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

    value_unsigned_truncated =
        my_round_banking(value_unsigned_truncated, fractional);

    *result = value_unsigned_truncated;
    my_set_sign_for_decimal(result, sign);
  }

  return ERROR_CODE;
}
