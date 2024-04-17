#include <stdlib.h>

#include "my_decimal.h"

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
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
      ERROR_CODE = my_mul_handle(value_1, value_2, &res);
    } else if (sign1 == MY_POSITIVE && sign2 == MY_NEGATIVE) {
      ERROR_CODE = my_mul_handle(value_1, my_abs(value_2), &res);
      my_negate(res, &res);
    } else if (sign1 == MY_NEGATIVE && sign2 == MY_POSITIVE) {
      ERROR_CODE = my_mul_handle(my_abs(value_1), value_2, &res);
      my_negate(res, &res);
    } else if (sign1 == MY_NEGATIVE && sign2 == MY_NEGATIVE) {
      ERROR_CODE = my_mul_handle(my_abs(value_1), my_abs(value_2), &res);
    }

    if (ERROR_CODE == MY_ARITHEMTIC_TOO_BIG) {
      if (my_get_sign_decimal(res) == MY_NEGATIVE) {
        ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
      }
    }

    if (ERROR_CODE == MY_ARITHMETIC_OK &&
        my_is_not_equal(value_1, my_get_zero_for_decimal()) &&
        my_is_not_equal(value_2, my_get_zero_for_decimal()) &&
        my_is_equal(res, my_get_zero_for_decimal())) {
      ERROR_CODE = MY_ARITHEMTIC_TOO_SMALL;
    }

    *result = res;
  }

  return ERROR_CODE;
}

int my_mul_handle(my_decimal value_1, my_decimal value_2,
                   my_decimal *result) {
  my_arithmetic_result ERROR_CODE = MY_ARITHMETIC_OK;
  int power1 = my_get_power_of_decimal(value_1);
  int power2 = my_get_power_of_decimal(value_2);

  my_decimal_null_service_bits(&value_1);
  my_decimal_null_service_bits(&value_2);

  my_int256 res = my_binary_multiplication_int128(value_1, value_2);

  int shift = my_int256_get_shift_to_decimal(res);
  int res_power = power1 + power2 - shift;

  if (res_power < 0) {
    ERROR_CODE = MY_ARITHEMTIC_TOO_BIG;
    *result = my_get_inf_for_decimal();
  } else {
    while (shift > 28) {
      res = my_binary_division_int256(
          res, my_create_int256_from_decimal(my_get_ten_for_decimal()), NULL);
      --shift;
    }

    if (res_power > 28) {
      my_int256 tmp = res;
      int tmp_power = res_power;
      while (tmp_power > 28) {
        tmp = my_binary_division_int256(
            tmp, my_create_int256_from_decimal(my_get_ten_for_decimal()),
            NULL);
        --tmp_power;
      }
      shift = res_power - tmp_power + shift;
      res_power = tmp_power;
    }

    my_int256 remainder =
        my_create_int256_from_decimal(my_get_zero_for_decimal());
    my_int256 powerten =
        my_create_int256_from_decimal(my_get_ten_for_int128(shift));

    res = my_binary_division_int256(res, powerten, &remainder);
    my_set_power_for_decimal(&remainder.decimals[0], shift);
    res.decimals[0] = my_round_banking(res.decimals[0], remainder.decimals[0]);
    my_set_power_for_decimal(&res.decimals[0], res_power);

    if (!my_binary_equal_zero_int128(res.decimals[1]) ||
        !my_check_decimal(res.decimals[0])) {
      ERROR_CODE = MY_ARITHEMTIC_TOO_BIG;
      *result = my_get_inf_for_decimal();
    } else {
      *result = res.decimals[0];
    }
  }

  return ERROR_CODE;
}
