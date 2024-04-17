#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_result ERROR_CODE = S21_ARITHMETIC_OK;

  if (!result) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
  } else if (!s21_check_decimal(value_1) || !s21_check_decimal(value_2)) {
    ERROR_CODE = S21_ARITHMETIC_ERROR;
    *result = s21_get_inf_for_decimal();
  } else if (s21_is_equal(value_2, s21_get_zero_for_decimal())) {
    ERROR_CODE = S21_ARITHMETIC_DIVISION_BY_ZERO;
    *result = s21_get_inf_for_decimal();
  } else {
    *result = s21_get_zero_for_decimal();
    int sign1 = s21_get_sign_decimal(value_1);
    int sign2 = s21_get_sign_decimal(value_2);
    s21_int256 value_1l;
    s21_int256 value_2l;
    s21_decimal_leveling(value_1, value_2, &value_1l, &value_2l);

    s21_int256 remainder =
        s21_create_int256_from_decimal(s21_get_zero_for_decimal());
    s21_int256 res;

    res = s21_binary_division_int256(value_1l, value_2l, &remainder);

    if (res.decimals[0].bits[3] != 0 ||
        !s21_binary_equal_zero_int128(res.decimals[1])) {
      if (sign1 != sign2) {
        ERROR_CODE = S21_ARITHEMTIC_TOO_SMALL;
      } else {
        ERROR_CODE = S21_ARITHEMTIC_TOO_BIG;
      }
      *result = s21_get_inf_for_decimal();
    } else {
      ERROR_CODE = s21_div_handle(value_2l, res, remainder, result);
      if (sign1 != sign2) {
        s21_set_sign_for_decimal(result, S21_NEGATIVE);
      }
      if (s21_get_sign_decimal(*result) == S21_NEGATIVE &&
          ERROR_CODE == S21_ARITHEMTIC_TOO_BIG) {
        ERROR_CODE = S21_ARITHEMTIC_TOO_SMALL;
      }
      if (ERROR_CODE == S21_ARITHMETIC_OK &&
          s21_is_not_equal(value_1, s21_get_zero_for_decimal()) &&
          s21_is_equal(*result, s21_get_zero_for_decimal())) {
        ERROR_CODE = S21_ARITHEMTIC_TOO_SMALL;
      }
    }
  }

  return ERROR_CODE;
}

int s21_div_handle(s21_int256 value_2l, s21_int256 res, s21_int256 remainder,
                   s21_decimal *result) {
  s21_arithmetic_result ERROR_CODE = S21_ARITHMETIC_OK;

  int power1 = s21_div_calc_fractional(&res, value_2l, &remainder);

  s21_int256 tmp_res =
      s21_create_int256_from_decimal(s21_get_zero_for_decimal());
  int power2 = s21_div_calc_fractional(&tmp_res, value_2l, &remainder);

  s21_set_power_for_decimal(&tmp_res.decimals[0], power2);

  if (s21_is_equal(tmp_res.decimals[0],
                   s21_get_zero_point_five_for_decimal())) {
    if (!s21_binary_equal_zero_int128(remainder.decimals[0]) ||
        !s21_binary_equal_zero_int128(remainder.decimals[1])) {
      s21_add(tmp_res.decimals[0], s21_get_min_for_decimal(),
              &tmp_res.decimals[0]);
    }
  }
  res.decimals[0] = s21_round_banking(res.decimals[0], tmp_res.decimals[0]);
  s21_set_power_for_decimal(&res.decimals[0], power1);
  if (!s21_binary_equal_zero_int128(res.decimals[1]) ||
      !s21_check_decimal(res.decimals[0])) {
    ERROR_CODE = S21_ARITHEMTIC_TOO_BIG;
    *result = s21_get_inf_for_decimal();
  } else {
    *result = res.decimals[0];
  }

  return ERROR_CODE;
}

int s21_div_calc_fractional(s21_int256 *res, s21_int256 value_2l,
                            s21_int256 *remainder) {
  int power = 0;
  s21_int256 number = *res;

  s21_int256 tmp;
  s21_int256 tmp_remainder = *remainder;

  while ((!s21_binary_equal_zero_int128((*remainder).decimals[0]) ||
          !s21_binary_equal_zero_int128((*remainder).decimals[1])) &&
         power < 28) {
    s21_int256 number_stored = number;
    s21_int256 remainder_stored = tmp_remainder;

    number =
        s21_binary_multiplication_int256(number, s21_get_ten_for_decimal());
    tmp_remainder = s21_binary_multiplication_int256(tmp_remainder,
                                                     s21_get_ten_for_decimal());
    tmp = s21_binary_division_int256(tmp_remainder, value_2l, &tmp_remainder);
    number = s21_binary_addition_int256(number, tmp);

    if (!s21_check_decimal(number.decimals[0])) {
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
