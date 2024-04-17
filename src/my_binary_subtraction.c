#include "my_decimal.h"

my_decimal my_binary_subtraction_int128(my_decimal decimal1,
                                          my_decimal decimal2) {
  my_decimal result;
  decimal2 = my_binary_not_int128(decimal2);
  decimal2 = my_binary_addition_int128(decimal2, my_get_one_for_decimal());
  result = my_binary_addition_int128(decimal1, decimal2);

  return result;
}

my_int256 my_binary_subtraction_int256(my_int256 decimal1,
                                         my_int256 decimal2) {
  my_int256 result;
  decimal2.decimals[0] = my_binary_not_int128(decimal2.decimals[0]);
  decimal2.decimals[1] = my_binary_not_int128(decimal2.decimals[1]);

  my_int256 one = my_create_int256_from_decimal(my_get_one_for_decimal());

  decimal2 = my_binary_addition_int256(decimal2, one);
  result = my_binary_addition_int256(decimal1, decimal2);

  return result;
}
