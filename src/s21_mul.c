#include <stdlib.h>

#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result ERROR_CODE = S21_ARITHMETIC_OK;

  if (!result) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
  } else if (!s21_check_decimal(value_1) || !s21_check_decimal(value_2)) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
    *result = s21_get_inf_for_decimal();
  } else {
    *result = s21_get_zero_for_decimal();
    s21_decimal res = s21_get_zero_for_decimal();

    int sign1 = s21_get_sign_decimal(value_1);
    int sign2 = s21_get_sign_decimal(value_2);

    if (sign1 == S21_POSITIVE && sign2 == S21_POSITIVE) {
      ERROR_CODE = s21_mul_handle(value_1, value_2, &res);
    } else if (sign1 == S21_POSITIVE && sign2 == S21_NEGATIVE) {
      ERROR_CODE = s21_mul_handle(value_1, s21_abs(value_2), &res);
      s21_negate(res, &res);
    } else if (sign1 == S21_NEGATIVE && sign2 == S21_POSITIVE) {
      ERROR_CODE = s21_mul_handle(s21_abs(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign1 == S21_NEGATIVE && sign2 == S21_NEGATIVE) {
      ERROR_CODE = s21_mul_handle(s21_abs(value_1), s21_abs(value_2), &res);
    }

    if (ERROR_CODE == S21_ARITHEMTIC_TOO_BIG) {
      if (s21_get_sign_decimal(res) == S21_NEGATIVE) {
        ERROR_CODE = S21_ARITHEMTIC_TOO_SMALL;
      }
    }

    if (ERROR_CODE == S21_ARITHMETIC_OK &&
        s21_is_not_equal(value_1, s21_get_zero_for_decimal()) &&
        s21_is_not_equal(value_2, s21_get_zero_for_decimal()) &&
        s21_is_equal(res, s21_get_zero_for_decimal())) {
      ERROR_CODE = S21_ARITHEMTIC_TOO_SMALL;
    }

    *result = res;
  }

  return ERROR_CODE;
}

int s21_mul_handle(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_arithmetic_result ERROR_CODE = S21_ARITHMETIC_OK;
  int power1 = s21_get_power_of_decimal(value_1);
  int power2 = s21_get_power_of_decimal(value_2);

  s21_decimal_null_service_bits(&value_1);
  s21_decimal_null_service_bits(&value_2);

  s21_int256 res = s21_binary_multiplication_int128(value_1, value_2);

  int shift = s21_int256_get_shift_to_decimal(res);
  int res_power = power1 + power2 - shift;

  if (res_power < 0) {
    ERROR_CODE = S21_ARITHEMTIC_TOO_BIG;
    *result = s21_get_inf_for_decimal();
  } else {
    while (shift > 28) {
      res = s21_binary_division_int256(
          res, s21_create_int256_from_decimal(s21_get_ten_for_decimal()), NULL);
      --shift;
    }

    if (res_power > 28) {
      s21_int256 tmp = res;
      int tmp_power = res_power;
      while (tmp_power > 28) {
        tmp = s21_binary_division_int256(
            tmp, s21_create_int256_from_decimal(s21_get_ten_for_decimal()),
            NULL);
        --tmp_power;
      }
      shift = res_power - tmp_power + shift;
      res_power = tmp_power;
    }

    s21_int256 remainder =
        s21_create_int256_from_decimal(s21_get_zero_for_decimal());
    s21_int256 powerten =
        s21_create_int256_from_decimal(s21_get_ten_for_int128(shift));

    res = s21_binary_division_int256(res, powerten, &remainder);
    s21_set_power_for_decimal(&remainder.decimals[0], shift);
    res.decimals[0] = s21_round_banking(res.decimals[0], remainder.decimals[0]);
    s21_set_power_for_decimal(&res.decimals[0], res_power);

    if (!s21_binary_equal_zero_int128(res.decimals[1]) ||
        !s21_check_decimal(res.decimals[0])) {
      ERROR_CODE = S21_ARITHEMTIC_TOO_BIG;
      *result = s21_get_inf_for_decimal();
    } else {
      *result = res.decimals[0];
    }
  }

  return ERROR_CODE;
}
