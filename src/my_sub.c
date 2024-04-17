#include "my_decimal.h"

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;
  if (!result) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
  } else if (!my_check_decimal(value_1) || !my_check_decimal(value_2)) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
    *result = my_get_inf_for_decimal();
  } else {
    *result = my_get_zero_for_decimal();
    my_decimal res = my_get_zero_for_decimal();
    int sign1 = my_get_sign_decimal(value_1);
    int sign2 = my_get_sign_decimal(value_2);

    if (sign1 == MY_POSITIVE && sign2 == MY_POSITIVE) {
      if (my_is_greater_or_equal(value_1, value_2)) {
        ERROR_CODE = my_sub_handle(value_1, value_2, &res);
      } else {
        ERROR_CODE = my_sub_handle(value_2, value_1, &res);
        my_negate(res, &res);
      }
    } else if (sign1 == MY_POSITIVE && sign2 == MY_NEGATIVE) {
      ERROR_CODE = my_add(value_1, my_abs(value_2), &res);
    } else if (sign1 == MY_NEGATIVE && sign2 == MY_POSITIVE) {
      ERROR_CODE = my_add(my_abs(value_1), value_2, &res);
      my_negate(res, &res);
    } else if (sign1 == MY_NEGATIVE && sign2 == MY_NEGATIVE) {
      if (my_is_greater_or_equal(value_1, value_2)) {
        ERROR_CODE = my_sub_handle(my_abs(value_2), my_abs(value_1), &res);
      } else {
        ERROR_CODE = my_sub_handle(my_abs(value_1), my_abs(value_2), &res);
        my_negate(res, &res);
      }
    }

    if (my_get_sign_decimal(res) == MY_NEGATIVE &&
        ERROR_CODE == MY_ARITHEMTIC_TOO_BIG) {
      ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
    }

    *result = res;
  }

  return ERROR_CODE;
}

int my_sub_handle(my_decimal value_1, my_decimal value_2,
                   my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;
  my_int256 value_1l;
  my_int256 value_2l;
  int power1 = my_get_power_of_decimal(value_1);
  int power2 = my_get_power_of_decimal(value_2);
  int max_power = my_max(power1, power2);

  my_decimal_leveling(value_1, value_2, &value_1l, &value_2l);
  my_int256 res = my_binary_subtraction_int256(value_1l, value_2l);
  int shift = my_int256_get_shift_to_decimal(res);
  int res_power = max_power - shift;

  if (res_power < 0) {
    ERROR_CODE = MY_ARITHEMTIC_TOO_BIG;
    *result = my_get_inf_for_decimal();
  } else {
    my_int256 remainder =
        my_create_int256_from_decimal(my_get_zero_for_decimal());
    my_int256 powerten =
        my_create_int256_from_decimal(my_get_ten_for_int128(shift));

    res = my_binary_division_int256(res, powerten, &remainder);
    my_set_power_for_decimal(&remainder.decimals[0], shift);
    res.decimals[0] = my_round_banking(res.decimals[0], remainder.decimals[0]);
    my_set_power_for_decimal(&res.decimals[0], res_power);

    *result = res.decimals[0];
  }

  return ERROR_CODE;
}
