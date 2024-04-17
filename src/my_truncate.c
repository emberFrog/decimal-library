#include <stdlib.h>

#include "my_decimal.h"

int my_truncate(my_decimal value, my_decimal *result) {
  my_other_result ERROR_CODE = MY_OTHER_OK;

  if (!result) {
    ERROR_CODE = MY_OTHER_ERROR;
  } else if (!my_check_decimal(value)) {
    ERROR_CODE = MY_OTHER_ERROR;
    *result = my_get_inf_for_decimal();
  } else {
    *result = my_get_zero_for_decimal();
    int power = my_get_power_of_decimal(value);
    my_decimal tmp = value;
    my_decimal_null_service_bits(&tmp);

    tmp = my_binary_division_int128(tmp, my_get_ten_for_int128(power), NULL);

    *result = tmp;
    if (my_get_sign_decimal(value) == MY_NEGATIVE) {
      my_set_sign_for_decimal(result, MY_NEGATIVE);
    }
  }

  return ERROR_CODE;
}
