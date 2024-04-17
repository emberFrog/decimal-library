#include <stdio.h>
#include <stdlib.h>

#include "my_decimal.h"

int my_is_set_bit(int number, int index) { return !!(number & (1U << index)); }

int my_set_bit(int number, int index) { return number | (1U << index); }

int my_reset_bit(int number, int index) { return number & ~(1U << index); }

int my_decimal_is_set_bit(my_decimal decimal, int index) {
  return my_is_set_bit(decimal.bits[index / MAX_SIZE_OF_ARRAYS],
                        index % MAX_SIZE_OF_ARRAYS);
}

my_decimal my_decimal_set_bit(my_decimal decimal, int index) {
  decimal.bits[index / MAX_SIZE_OF_ARRAYS] = my_set_bit(
      decimal.bits[index / MAX_SIZE_OF_ARRAYS], index % MAX_SIZE_OF_ARRAYS);
  return decimal;
}

int my_decimal_get_not_zero_bit(my_decimal decimal) {
  int result = -1;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    if (my_decimal_is_set_bit(decimal, i)) {
      result = i;
      break;
    }
  }

  return result;
}

int my_check_decimal(my_decimal decimal) {
  int ERROR_CODE = 1;

  if (my_get_empty1_from_decimal(decimal) != 0 ||
      my_get_empty2_from_decimal(decimal) != 0) {
    ERROR_CODE = 0;
  } else {
    int power = my_get_power_of_decimal(decimal);
    if (power < 0 || power > 28) {
      ERROR_CODE = 0;
    }
  }

  return ERROR_CODE;
}

int my_get_sign_decimal(my_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.sign;
}

int my_get_power_of_decimal(my_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.power;
}

int my_get_empty1_from_decimal(my_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty1;
}

int my_get_empty2_from_decimal(my_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];

  return bits3.parts.empty2;
}

void my_set_sign_for_decimal(my_decimal *decimal, int sign) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  if (sign == MY_POSITIVE) {
    bits3.parts.sign = MY_POSITIVE;
  } else {
    bits3.parts.sign = MY_NEGATIVE;
  }

  decimal->bits[3] = bits3.i;
}

void my_set_power_for_decimal(my_decimal *decimal, int power) {
  decimal_bit3 bits3;
  bits3.i = decimal->bits[3];
  bits3.parts.power = power;

  decimal->bits[3] = bits3.i;
}

int my_decimal_even(my_decimal value) { return (value.bits[0] & 1) != 1; }

int my_int256_get_shift_to_decimal(my_int256 value) {
  int cnt = 0;
  if (!(my_binary_equal_zero_int128(value.decimals[0]) &&
        my_binary_equal_zero_int128(value.decimals[1]))) {
    my_int256 max = my_create_int256_from_decimal(my_get_max_for_decimal());
    my_int256 quotient = my_binary_division_int256(value, max, NULL);
    while (1) {
      int compare = my_binary_compare_int128(quotient.decimals[0],
                                              my_get_ten_for_int128(cnt));
      if (compare == -1 || compare == 0) {
        break;
      }
      ++cnt;
    }
    my_int256 tmp = my_binary_division_int256(
        value, my_create_int256_from_decimal(my_get_ten_for_int128(cnt)),
        NULL);
    if (!my_binary_equal_zero_int128(tmp.decimals[1]) ||
        tmp.decimals[0].bits[3] != 0) {
      ++cnt;
    }
  }

  return cnt;
}

int my_max(int value_1, int value_2) {
  int result = value_2;
  if (value_1 > value_2) {
    result = value_1;
  }

  return result;
}

void my_decimal_leveling(my_decimal value_1, my_decimal value_2,
                          my_int256 *value_1l, my_int256 *value_2l) {
  int power1 = my_get_power_of_decimal(value_1);
  int power2 = my_get_power_of_decimal(value_2);
  my_decimal tmp1 = value_1;
  my_decimal tmp2 = value_2;

  my_decimal_null_service_bits(&tmp1);
  my_decimal_null_service_bits(&tmp2);

  if (power1 > power2) {
    *value_1l = my_create_int256_from_decimal(tmp1);
    *value_2l = my_binary_multiplication_int128(
        tmp2, my_get_ten_for_int128(power1 - power2));
  } else if (power1 < power2) {
    *value_1l = my_binary_multiplication_int128(
        tmp1, my_get_ten_for_int128(power2 - power1));
    *value_2l = my_create_int256_from_decimal(tmp2);
  } else {
    *value_1l = my_create_int256_from_decimal(tmp1);
    *value_2l = my_create_int256_from_decimal(tmp2);
  }
}
