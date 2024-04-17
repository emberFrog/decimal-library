#include "my_decimal.h"

int my_negate(my_decimal value, my_decimal *result) {
  my_other_result ERROR_CODE = MY_OTHER_OK;

  if (!result) {
    ERROR_CODE = MY_OTHER_ERROR;
  } else {
    *result = value;
    my_set_sign_for_decimal(result, !my_get_sign_decimal(*result));

    if (!my_check_decimal(value)) {
      ERROR_CODE = MY_OTHER_ERROR;
    }
  }

  return ERROR_CODE;
}
