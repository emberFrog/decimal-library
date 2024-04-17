#include "my_decimal.h"

my_decimal my_remove_trailing_zeros(my_decimal value) {
  my_decimal result = value;
  int power = my_get_power_of_decimal(value);
  int sign = my_get_sign_decimal(value);

  if (power > 0 && my_check_decimal(value)) {
    my_decimal remainder = my_get_zero_for_decimal();
    my_decimal tmp = value;
    my_decimal_null_service_bits(&tmp);

    while (power > 0) {
      tmp = my_binary_division_int128(tmp, my_get_ten_for_int128(1),
                                       &remainder);
      if (my_binary_equal_zero_int128(remainder)) {
        --power;
        result = tmp;
      } else {
        break;
      }
    }
    my_set_power_for_decimal(&result, power);
    my_set_sign_for_decimal(&result, sign);
  }

  return result;
}
