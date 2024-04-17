#include "my_decimal.h"

my_decimal my_binary_addition_int128(my_decimal decimal1,
                                       my_decimal decimal2) {
  my_decimal result = decimal1;
  my_decimal tmp = decimal2;

  while (!my_binary_equal_zero_int128(tmp)) {
    my_decimal overflow_bits = my_binary_and_int128(result, tmp);
    overflow_bits = my_binary_shift_left_int128(overflow_bits, 1);
    result = my_binary_xor_int128(result, tmp);
    tmp = overflow_bits;
  }

  return result;
}

my_int256 my_binary_addition_int256(my_int256 decimal1,
                                      my_int256 decimal2) {
  my_int256 result = decimal1;
  my_int256 tmp = decimal2;

  while (!my_binary_equal_zero_int128(tmp.decimals[0]) ||
         !my_binary_equal_zero_int128(tmp.decimals[1])) {
    my_int256 overflow_bits;
    overflow_bits.decimals[0] =
        my_binary_and_int128(result.decimals[0], tmp.decimals[0]);
    overflow_bits.decimals[1] =
        my_binary_and_int128(result.decimals[1], tmp.decimals[1]);

    overflow_bits = my_binary_shift_left_int256(overflow_bits, 1);
    result.decimals[0] =
        my_binary_xor_int128(result.decimals[0], tmp.decimals[0]);
    result.decimals[1] =
        my_binary_xor_int128(result.decimals[1], tmp.decimals[1]);

    tmp = overflow_bits;
  }

  return result;
}
