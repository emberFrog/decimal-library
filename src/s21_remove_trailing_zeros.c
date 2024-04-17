#include "s21_decimal.h"

s21_decimal s21_remove_trailing_zeros(s21_decimal value) {
  s21_decimal result = value;
  int power = s21_get_power_of_decimal(value);
  int sign = s21_get_sign_decimal(value);

  if (power > 0 && s21_check_decimal(value)) {
    s21_decimal remainder = s21_get_zero_for_decimal();
    s21_decimal tmp = value;
    s21_decimal_null_service_bits(&tmp);

    while (power > 0) {
      tmp = s21_binary_division_int128(tmp, s21_get_ten_for_int128(1),
                                       &remainder);
      if (s21_binary_equal_zero_int128(remainder)) {
        --power;
        result = tmp;
      } else {
        break;
      }
    }
    s21_set_power_for_decimal(&result, power);
    s21_set_sign_for_decimal(&result, sign);
  }

  return result;
}
