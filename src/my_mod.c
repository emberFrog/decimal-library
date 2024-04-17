#include "my_decimal.h"

int my_mod(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;

  if (!result) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
  } else if (!my_check_decimal(value_1) || !my_check_decimal(value_2)) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
    *result = my_get_inf_for_decimal();
  } else if (my_is_equal(value_2, my_get_zero_for_decimal())) {
    ERROR_CODE = MY_ARITHMETIC_DIVISION_BY_ZERO;
    *result = my_get_inf_for_decimal();
  } else if (my_is_less(my_abs(value_1), my_abs(value_2))) {
    ERROR_CODE = MY_ARITHMETIC_OK;
    *result = value_1;
  } else {
    *result = my_get_zero_for_decimal();

    int sign1 = my_get_sign_decimal(value_1);
    int power1 = my_get_power_of_decimal(value_1);
    int power2 = my_get_power_of_decimal(value_2);
    int max_power = my_max(power1, power2);
    my_int256 value_1l;
    my_int256 value_2l;
    my_int256 remainder =
        my_create_int256_from_decimal(my_get_zero_for_decimal());

    my_decimal_leveling(value_1, value_2, &value_1l, &value_2l);
    my_binary_division_int256(value_1l, value_2l, &remainder);
    my_set_power_for_decimal(&remainder.decimals[0], max_power);

    *result = remainder.decimals[0];
    my_set_sign_for_decimal(result, sign1);
  }

  return ERROR_CODE;
}
