#include "my_decimal.h"

my_int256 my_binary_multiplication_int128(my_decimal decimal1,
                                            my_decimal decimal2) {
  my_int256 int256_result =
      my_create_int256_from_decimal(my_get_zero_for_decimal());
  my_int256 int256_tmp1 = my_create_int256_from_decimal(decimal1);

  int max_bit = my_decimal_get_not_zero_bit(decimal2);

  for (int i = 0; i <= max_bit; i++) {
    if (my_decimal_is_set_bit(decimal2, i) != 0) {
      int256_result = my_binary_addition_int256(int256_result, int256_tmp1);
    }
    int256_tmp1 = my_binary_shift_left_int256(int256_tmp1, 1);
  }

  return int256_result;
}

my_int256 my_binary_multiplication_int256(my_int256 decimal1,
                                            my_decimal decimal2) {
  my_int256 int256_result =
      my_create_int256_from_decimal(my_get_zero_for_decimal());
  my_int256 int256_tmp1 = decimal1;

  int max_bit = my_decimal_get_not_zero_bit(decimal2);

  for (int i = 0; i <= max_bit; i++) {
    if (my_decimal_is_set_bit(decimal2, i) != 0) {
      int256_result = my_binary_addition_int256(int256_result, int256_tmp1);
    }

    int256_tmp1 = my_binary_shift_left_int256(int256_tmp1, 1);
  }

  return int256_result;
}
