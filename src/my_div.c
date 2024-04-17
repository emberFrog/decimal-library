#include "my_decimal.h"

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;

  if (!result) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
  } else if (!my_check_decimal(value_1) || !my_check_decimal(value_2)) {
    ERROR_CODE = MY_ARITHMETIC_ERROR;
    *result = my_get_inf_for_decimal();
  } else if (my_is_equal(value_2, my_get_zero_for_decimal())) {
    ERROR_CODE = MY_ARITHMETIC_DIVISION_BY_ZERO;
    *result = my_get_inf_for_decimal();
  } else {
    *result = my_get_zero_for_decimal();
    int sign1 = my_get_sign_decimal(value_1);
    int sign2 = my_get_sign_decimal(value_2);
    my_int256 value_1l;
    my_int256 value_2l;
    my_decimal_leveling(value_1, value_2, &value_1l, &value_2l);

    my_int256 remainder =
        my_create_int256_from_decimal(my_get_zero_for_decimal());
    my_int256 res;

    res = my_binary_division_int256(value_1l, value_2l, &remainder);

    if (res.decimals[0].bits[3] != 0 ||
        !my_binary_equal_zero_int128(res.decimals[1])) {
      if (sign1 != sign2) {
        ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
      } else {
        ERROR_CODE = MY_ARITHEMTIC_TOO_BIG;
      }
      *result = my_get_inf_for_decimal();
    } else {
      ERROR_CODE = my_div_handle(value_2l, res, remainder, result);
      if (sign1 != sign2) {
        my_set_sign_for_decimal(result, MY_NEGATIVE);
      }
      if (my_get_sign_decimal(*result) == MY_NEGATIVE &&
          ERROR_CODE == MY_ARITHEMTIC_TOO_BIG) {
        ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
      }
      if (ERROR_CODE == MY_ARITHMETIC_OK &&
          my_is_not_equal(value_1, my_get_zero_for_decimal()) &&
          my_is_equal(*result, my_get_zero_for_decimal())) {
        ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
      }
    }
  }

  return ERROR_CODE;
}

int my_div_handle(my_int256 value_2l, my_int256 res, my_int256 remainder,
                   my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;

  int power1 = my_div_calc_fractional(&res, value_2l, &remainder);

  my_int256 tmp_res =
      my_create_int256_from_decimal(my_get_zero_for_decimal());
  int power2 = my_div_calc_fractional(&tmp_res, value_2l, &remainder);

  my_set_power_for_decimal(&tmp_res.decimals[0], power2);

  if (my_is_equal(tmp_res.decimals[0],
                   my_get_zero_point_five_for_decimal())) {
    if (!my_binary_equal_zero_int128(remainder.decimals[0]) ||
        !my_binary_equal_zero_int128(remainder.decimals[1])) {
      my_add(tmp_res.decimals[0], my_get_min_for_decimal(),
              &tmp_res.decimals[0]);
    }
  }
  res.decimals[0] = my_round_banking(res.decimals[0], tmp_res.decimals[0]);
  my_set_power_for_decimal(&res.decimals[0], power1);
  if (!my_binary_equal_zero_int128(res.decimals[1]) ||
      !my_check_decimal(res.decimals[0])) {
    ERROR_CODE = MY_ARITHEMTIC_TOO_BIG;
    *result = my_get_inf_for_decimal();
  } else {
    *result = res.decimals[0];
  }

  return ERROR_CODE;
}

int my_div_calc_fractional(my_int256 *res, my_int256 value_2l,
                            my_int256 *remainder) {
  int power = 0;
  my_int256 number = *res;

  my_int256 tmp;
  my_int256 tmp_remainder = *remainder;

  while ((!my_binary_equal_zero_int128((*remainder).decimals[0]) ||
          !my_binary_equal_zero_int128((*remainder).decimals[1])) &&
         power < 28) {
    my_int256 number_stored = number;
    my_int256 remainder_stored = tmp_remainder;

    number =
        my_binary_multiplication_int256(number, my_get_ten_for_decimal());
    tmp_remainder = my_binary_multiplication_int256(tmp_remainder,
                                                     my_get_ten_for_decimal());
    tmp = my_binary_division_int256(tmp_remainder, value_2l, &tmp_remainder);
    number = my_binary_addition_int256(number, tmp);

    if (!my_check_decimal(number.decimals[0])) {
      number = number_stored;
      tmp_remainder = remainder_stored;
      break;
    }

    ++power;
  }

  *res = number;
  *remainder = tmp_remainder;

  return power;
}
