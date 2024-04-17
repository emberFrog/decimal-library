#include <string.h>

#include "s21_decimal.h"

// s21_decimal s21_create_decimal_from_array(int data1, int data2, int data3,
//                                           int data4) {
//   s21_decimal decimal;

//   decimal.bits[0] = data1;
//   decimal.bits[1] = data2;
//   decimal.bits[2] = data3;
//   decimal.bits[3] = data4;

//   return decimal;
// }

// s21_decimal s21_create_decimal_from_data(int sign, int power, int data1,
//                                          int data2, int data3) {
//   s21_decimal decimal;
//   s21_set_to_zero_decimal(&decimal);

//   decimal.bits[0] = data1;
//   decimal.bits[1] = data2;
//   decimal.bits[2] = data3;

//   s21_set_power_for_decimal(&decimal, power);
//   s21_set_sign_for_decimal(&decimal, sign);

//   return decimal;
// }

// s21_decimal s21_create_decimal_from_strings(char *str1, char *str2, char
// *str3,
//                                             char *str4) {
//   s21_decimal decimal = s21_get_zero_for_decimal();
//   int error = 0;

//   error = s21_set_bits_for_decimal_from_string(&decimal.bits[0], str1);

//   if (error == 0) {
//     error = s21_set_bits_for_decimal_from_string(&decimal.bits[1], str2);
//   }

//   if (error == 0) {
//     error = s21_set_bits_for_decimal_from_string(&decimal.bits[2], str3);
//   }

//   if (error == 0) {
//     error = s21_set_bits_for_decimal_from_string(&decimal.bits[3], str4);
//   }

//   if (error == 1) {
//     decimal = s21_get_inf_for_decimal();
//   }

//   return decimal;
// }

// int s21_set_bits_for_decimal_from_string(int *bits, char *str) {
//   int index = 0;
//   int error = 0;

//   for (int i = (int)strlen(str) - 1; i >= 0; i--) {
//     if (str[i] == ' ') {
//       continue;
//     } else if (str[i] == '1') {
//       *bits = s21_set_bit(*bits, index);
//     } else if (str[i] == '0') {
//       *bits = s21_reset_bit(*bits, index);
//     } else {
//       error = 1;
//       break;
//     }
//     ++index;
//   }

//   return error;
// }

void s21_set_to_zero_decimal(s21_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
}

void s21_decimal_null_service_bits(s21_decimal *value) { value->bits[3] = 0; }

s21_decimal s21_get_zero_for_decimal(void) {
  s21_decimal result;
  s21_set_to_zero_decimal(&result);

  return result;
}

s21_decimal s21_get_one_for_decimal(void) {
  s21_decimal result;
  s21_set_to_zero_decimal(&result);
  result.bits[0] = 1;

  return result;
}

s21_decimal s21_get_ten_for_decimal(void) {
  s21_decimal result;
  s21_set_to_zero_decimal(&result);
  result.bits[0] = 10;

  return result;
}

s21_decimal s21_get_ten_for_int128(int pow) { return all_ten_pows[pow]; }

s21_decimal s21_get_zero_point_five_for_decimal(void) {
  s21_decimal result = {{0x5, 0x0, 0x0, 0x10000}};

  return result;
}

s21_decimal s21_get_min_for_decimal(void) {
  s21_decimal result = {{0x1, 0x0, 0x0, 0x1C0000}};

  return result;
}

s21_decimal s21_get_max_for_decimal(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  return result;
}

s21_decimal s21_get_int_max_for_decimal(void) {
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  return result;
}

s21_decimal s21_get_int_min_for_decimal(void) {
  s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};

  return result;
}

s21_int256 s21_create_int256_from_decimal(s21_decimal value_1) {
  s21_int256 result;
  result.decimals[0] = value_1;
  result.decimals[1] = s21_get_zero_for_decimal();
  return result;
}

s21_decimal s21_get_inf_for_decimal(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  return result;
}
