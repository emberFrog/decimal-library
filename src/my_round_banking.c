#include "my_decimal.h"

my_decimal my_round_banking(my_decimal integral, my_decimal fractional) {
  my_decimal zerofive = my_get_zero_point_five_for_decimal();
  my_decimal result;

  if (my_is_equal(fractional, zerofive)) {
    if (my_decimal_even(integral)) {
      result = integral;
    } else {
      result = my_binary_addition_int128(integral, my_get_one_for_decimal());
    }
  } else if (my_is_greater(fractional, zerofive)) {
    result = my_binary_addition_int128(integral, my_get_one_for_decimal());
  } else {
    result = integral;
  }

  return result;
}
