#include "my_decimal.h"

my_decimal my_binary_shift_left_int128(my_decimal decimal, int shift) {
  my_decimal result = decimal;
  while (shift > 0) {
    result = my_binary_shift_left_one_int128(result);
    --shift;
  }

  return result;
}

my_decimal my_binary_shift_right_int128(my_decimal decimal, int shift) {
  my_decimal result = decimal;
  while (shift > 0) {
    result = my_binary_shift_right_one_int128(result);
    --shift;
  }

  return result;
}

my_int256 my_binary_shift_left_int256(my_int256 decimal, int shift) {
  my_int256 result = decimal;
  while (shift > 0) {
    int b0 = my_decimal_is_set_bit(result.decimals[0], MAX_BITS - 1);
    result.decimals[0] = my_binary_shift_left_one_int128(result.decimals[0]);
    result.decimals[1] = my_binary_shift_left_one_int128(result.decimals[1]);
    if (b0) {
      result.decimals[1] = my_decimal_set_bit(result.decimals[1], 0);
    }
    --shift;
  }

  return result;
}

my_int256 my_binary_shift_right_int256(my_int256 decimal, int shift) {
  my_int256 result = decimal;
  while (shift > 0) {
    int b1 = my_decimal_is_set_bit(result.decimals[1], 0);
    result.decimals[0] = my_binary_shift_right_one_int128(result.decimals[0]);
    result.decimals[1] = my_binary_shift_right_one_int128(result.decimals[1]);
    if (b1) {
      result.decimals[0] =
          my_decimal_set_bit(result.decimals[0], MAX_BITS - 1);
    }
    --shift;
  }

  return result;
}

my_decimal my_binary_shift_left_one_int128(my_decimal decimal) {
  my_decimal result = my_get_zero_for_decimal();

  int b0 = my_is_set_bit(decimal.bits[0], MAX_SIZE_OF_ARRAYS - 1);
  unsigned int result0 = decimal.bits[0];
  result0 = result0 << 1;
  result.bits[0] = result0;

  int b1 = my_is_set_bit(decimal.bits[1], MAX_SIZE_OF_ARRAYS - 1);
  unsigned int result1 = decimal.bits[1];
  result1 = result1 << 1;
  result.bits[1] = result1;

  int b2 = my_is_set_bit(decimal.bits[2], MAX_SIZE_OF_ARRAYS - 1);
  unsigned int result2 = decimal.bits[2];
  result2 = result2 << 1;
  result.bits[2] = result2;

  unsigned int result3 = decimal.bits[3];
  result3 = result3 << 1;
  result.bits[3] = result3;

  if (b0) {
    result.bits[1] = my_set_bit(result.bits[1], 0);
  }

  if (b1) {
    result.bits[2] = my_set_bit(result.bits[2], 0);
  }

  if (b2) {
    result.bits[3] = my_set_bit(result.bits[3], 0);
  }

  return result;
}

my_decimal my_binary_shift_right_one_int128(my_decimal decimal) {
  my_decimal result = my_get_zero_for_decimal();

  int b3 = my_is_set_bit(decimal.bits[3], 0);
  unsigned int result3 = decimal.bits[3];
  result3 = result3 >> 1;
  result.bits[3] = result3;

  int b2 = my_is_set_bit(decimal.bits[2], 0);
  unsigned int result2 = decimal.bits[2];
  result2 = result2 >> 1;
  result.bits[2] = result2;

  int b1 = my_is_set_bit(decimal.bits[1], 0);
  unsigned int result1 = decimal.bits[1];
  result1 = result1 >> 1;
  result.bits[1] = result1;

  unsigned int result0 = decimal.bits[0];
  result0 = result0 >> 1;
  result.bits[0] = result0;

  if (b3) {
    result.bits[2] = my_set_bit(result.bits[2], MAX_SIZE_OF_ARRAYS - 1);
  }

  if (b2) {
    result.bits[1] = my_set_bit(result.bits[1], MAX_SIZE_OF_ARRAYS - 1);
  }

  if (b1) {
    result.bits[0] = my_set_bit(result.bits[0], MAX_SIZE_OF_ARRAYS - 1);
  }

  return result;
}
