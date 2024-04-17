#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int s21_is_set_bit(int number, int index) { return !!(number & (1U << index)); }

int s21_set_bit(int number, int index) { return number | (1U << index); }

int s21_reset_bit(int number, int index) { return number & ~(1U << index); }

int s21_decimal_is_set_bit(s21_decimal decimal, int index) {
  return s21_is_set_bit(decimal.bits[index / MAX_SIZE_OF_ARRAYS],
                        index % MAX_SIZE_OF_ARRAYS);
}

s21_decimal s21_decimal_set_bit(s21_decimal decimal, int index) {
  decimal.bits[index / MAX_SIZE_OF_ARRAYS] = s21_set_bit(
      decimal.bits[index / MAX_SIZE_OF_ARRAYS], index % MAX_SIZE_OF_ARRAYS);
  return decimal;
}

int s21_decimal_get_not_zero_bit(s21_decimal decimal) {
  int result = -1;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    if (s21_decimal_is_set_bit(decimal, i)) {
      result = i;
      break;
    }
  }

  return result;
}

int s21_check_decimal(s21_decimal decimal) {
  int ERROR_CODE = 1;

  if (s21_get_empty1_from_decimal(decimal) != 0 ||
      s21_get_empty2_from_decimal(decimal) != 0) {
    ERROR_CODE = 0;
  } else {
    int power = s21_get_power_of_decimal(decimal);
    if (power < 0 || power > 28) {
      ERROR_CODE = 0;
    }
  }

  return ERROR_CODE;
}

int s21_get_sign_decimal(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.sign;
}

int s21_get_power_of_decimal(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.power;
}

int s21_get_empty1_from_decimal(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty1;
}

int s21_get_empty2_from_decimal(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty2;
}

void s21_set_sign_for_decimal(s21_decimal *decimal, int sign) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  if (sign == S21_POSITIVE) {
    bits3.parts.sign = S21_POSITIVE;
  } else {
    bits3.parts.sign = S21_NEGATIVE;
  }

  decimal->bits[3] = bits3.i;
}

void s21_set_power_for_decimal(s21_decimal *decimal, int power) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  bits3.parts.power = power;

  decimal->bits[3] = bits3.i;
}

int s21_decimal_even(s21_decimal value) { return (value.bits[0] & 1) != 1; }

int s21_int256_get_shift_to_decimal(s21_int256 value) {
  int cnt = 0;
  if (!(s21_binary_equal_zero_int128(value.decimals[0]) &&
        s21_binary_equal_zero_int128(value.decimals[1]))) {
    s21_int256 max = s21_create_int256_from_decimal(s21_get_max_for_decimal());
    s21_int256 quotient = s21_binary_division_int256(value, max, NULL);
    while (1) {
      int compare = s21_binary_compare_int128(quotient.decimals[0],
                                              s21_get_ten_for_int128(cnt));
      if (compare == -1 || compare == 0) {
        break;
      }
      ++cnt;
    }
    s21_int256 tmp = s21_binary_division_int256(
        value, s21_create_int256_from_decimal(s21_get_ten_for_int128(cnt)),
        NULL);
    if (!s21_binary_equal_zero_int128(tmp.decimals[1]) ||
        tmp.decimals[0].bits[3] != 0) {
      ++cnt;
    }
  }

  return cnt;
}

int s21_max(int value_1, int value_2) {
  int result = value_2;
  if (value_1 > value_2) {
    result = value_1;
  }

  return result;
}

void s21_decimal_leveling(s21_decimal value_1, s21_decimal value_2,
                          s21_int256 *value_1l, s21_int256 *value_2l) {
  int power1 = s21_get_power_of_decimal(value_1);
  int power2 = s21_get_power_of_decimal(value_2);
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;

  s21_decimal_null_service_bits(&tmp1);
  s21_decimal_null_service_bits(&tmp2);

  if (power1 > power2) {
    *value_1l = s21_create_int256_from_decimal(tmp1);
    *value_2l = s21_binary_multiplication_int128(
        tmp2, s21_get_ten_for_int128(power1 - power2));
  } else if (power1 < power2) {
    *value_1l = s21_binary_multiplication_int128(
        tmp1, s21_get_ten_for_int128(power2 - power1));
    *value_2l = s21_create_int256_from_decimal(tmp2);
  } else {
    *value_1l = s21_create_int256_from_decimal(tmp1);
    *value_2l = s21_create_int256_from_decimal(tmp2);
  }
}
