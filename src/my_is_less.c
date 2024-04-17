#include "my_decimal.h"

int my_is_less(my_decimal value_1, my_decimal value_2) {
  my_comparison_result ERROR_CODE = MY_COMPARISON_FALSE;

  int sign1 = my_get_sign_decimal(value_1);
  int sign2 = my_get_sign_decimal(value_2);

  if (my_is_equal(value_1, my_get_zero_for_decimal()) &&
      my_is_equal(value_2, my_get_zero_for_decimal())) {
    ERROR_CODE = MY_COMPARISON_FALSE;
  } else if (sign1 == MY_NEGATIVE && sign2 == MY_POSITIVE) {
    ERROR_CODE = MY_COMPARISON_TRUE;
  } else if (sign1 == MY_POSITIVE && sign2 == MY_NEGATIVE) {
    ERROR_CODE = MY_COMPARISON_FALSE;
  } else if (sign1 == MY_NEGATIVE && sign2 == MY_NEGATIVE) {
    ERROR_CODE = my_is_less_handle(my_abs(value_2), my_abs(value_1));
  } else {
    ERROR_CODE = my_is_less_handle(value_1, value_2);
  }

  return ERROR_CODE;
}

int my_is_less_handle(my_decimal value_1, my_decimal value_2) {
  my_comparison_result ERROR_CODE = MY_COMPARISON_FALSE;
  my_decimal tmp1 = value_1;
  my_decimal tmp2 = value_2;
  my_int256 tmp1l;
  my_int256 tmp2l;

  my_decimal_leveling(tmp1, tmp2, &tmp1l, &tmp2l);

  int compare = my_binary_compare_int256(tmp1l, tmp2l);

  if (compare == -1) {
    ERROR_CODE = MY_COMPARISON_TRUE;
  } else {
    ERROR_CODE = MY_COMPARISON_FALSE;
  }

  return ERROR_CODE;
}
