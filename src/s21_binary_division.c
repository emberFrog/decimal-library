#include "s21_decimal.h"

s21_decimal s21_binary_division_int128(s21_decimal decimal1,
                                       s21_decimal decimal2,
                                       s21_decimal *remainder) {
  s21_decimal result;
  s21_decimal partial_remainder = s21_get_zero_for_decimal();
  s21_decimal quotient = s21_get_zero_for_decimal();

  if (s21_binary_equal_zero_int128(decimal1)) {
    quotient = s21_get_zero_for_decimal();
    partial_remainder = s21_get_zero_for_decimal();
  } else if (s21_binary_compare_int128(decimal1, decimal2) == -1) {
    quotient = s21_get_zero_for_decimal();
    partial_remainder = decimal1;
  } else {
    int left1 = s21_decimal_get_not_zero_bit(decimal1);
    int left2 = s21_decimal_get_not_zero_bit(decimal2);
    int shift = left1 - left2;

    s21_decimal shifted_divisor = s21_binary_shift_left_int128(decimal2, shift);
    s21_decimal dividend = decimal1;

    int need_subtraction = 1;

    while (shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder =
            s21_binary_subtraction_int128(dividend, shifted_divisor);
      } else {
        partial_remainder =
            s21_binary_addition_int128(dividend, shifted_divisor);
      }

      quotient = s21_binary_shift_left_int128(quotient, 1);
      if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1) == 0) {
        quotient = s21_decimal_set_bit(quotient, 0);
      }

      dividend = s21_binary_shift_left_int128(partial_remainder, 1);

      if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    if (s21_decimal_is_set_bit(partial_remainder, MAX_BITS - 1)) {
      partial_remainder =
          s21_binary_addition_int128(partial_remainder, shifted_divisor);
    }
    partial_remainder =
        s21_binary_shift_right_int128(partial_remainder, left1 - left2);
  }

  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

s21_int256 s21_binary_division_int256(s21_int256 decimal1, s21_int256 decimal2,
                                      s21_int256 *remainder) {
  s21_int256 result;

  s21_int256 partial_remainder =
      s21_create_int256_from_decimal(s21_get_zero_for_decimal());
  s21_int256 quotient =
      s21_create_int256_from_decimal(s21_get_zero_for_decimal());

  if (s21_binary_equal_zero_int128(decimal1.decimals[0]) &&
      s21_binary_equal_zero_int128(decimal1.decimals[1])) {
    quotient = s21_create_int256_from_decimal(s21_get_zero_for_decimal());
    partial_remainder =
        s21_create_int256_from_decimal(s21_get_zero_for_decimal());
  } else if (s21_binary_compare_int256(decimal1, decimal2) == -1) {
    quotient = s21_create_int256_from_decimal(s21_get_zero_for_decimal());
    partial_remainder = decimal1;
  } else {
    int left1 = s21_decimal_get_not_zero_bit(decimal1.decimals[1]);
    if (left1 == -1) {
      left1 = s21_decimal_get_not_zero_bit(decimal1.decimals[0]);
    } else {
      left1 = MAX_BITS + left1;
    }

    int left2 = s21_decimal_get_not_zero_bit(decimal2.decimals[1]);
    if (left2 == -1) {
      left2 = s21_decimal_get_not_zero_bit(decimal2.decimals[0]);
    } else {
      left2 = MAX_BITS + left2;
    }

    int shift = left1 - left2;

    s21_int256 shifted_divisor = s21_binary_shift_left_int256(decimal2, shift);
    s21_int256 dividend = decimal1;

    int need_subtraction = 1;

    while (shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder =
            s21_binary_subtraction_int256(dividend, shifted_divisor);
      } else {
        partial_remainder =
            s21_binary_addition_int256(dividend, shifted_divisor);
      }

      quotient = s21_binary_shift_left_int256(quotient, 1);
      if (s21_decimal_is_set_bit(partial_remainder.decimals[1], MAX_BITS - 1) ==
          0) {
        quotient.decimals[0] = s21_decimal_set_bit(quotient.decimals[0], 0);
      }

      dividend = s21_binary_shift_left_int256(partial_remainder, 1);

      if (s21_decimal_is_set_bit(partial_remainder.decimals[1], MAX_BITS - 1) ==
          0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    if (s21_decimal_is_set_bit(partial_remainder.decimals[1], MAX_BITS - 1)) {
      partial_remainder =
          s21_binary_addition_int256(partial_remainder, shifted_divisor);
    }
    partial_remainder =
        s21_binary_shift_right_int256(partial_remainder, left1 - left2);
  }

  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}
