#include <string.h>

#include "my_decimal.h"

void my_set_to_zero_decimal(my_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
}

void my_decimal_null_service_bits(my_decimal *value) { value->bits[3] = 0; }

my_decimal my_get_zero_for_decimal(void) {
  my_decimal result;
  my_set_to_zero_decimal(&result);

  return result;
}

my_decimal my_get_one_for_decimal(void) {
  my_decimal result;
  my_set_to_zero_decimal(&result);
  result.bits[0] = 1;

  return result;
}

my_decimal my_get_ten_for_decimal(void) {
  my_decimal result;
  my_set_to_zero_decimal(&result);
  result.bits[0] = 10;

  return result;
}

my_decimal my_get_ten_for_int128(int pow) { return all_ten_pows[pow]; }

my_decimal my_get_zero_point_five_for_decimal(void) {
  my_decimal result = {{0x5, 0x0, 0x0, 0x10000}};

  return result;
}

my_decimal my_get_min_for_decimal(void) {
  my_decimal result = {{0x1, 0x0, 0x0, 0x1C0000}};

  return result;
}

my_decimal my_get_max_for_decimal(void) {
  my_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  return result;
}

my_decimal my_get_int_max_for_decimal(void) {
  my_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  return result;
}

my_decimal my_get_int_min_for_decimal(void) {
  my_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};

  return result;
}

my_int256 my_create_int256_from_decimal(my_decimal value_1) {
  my_int256 result;
  result.decimals[0] = value_1;
  result.decimals[1] = my_get_zero_for_decimal();
  return result;
}

my_decimal my_get_inf_for_decimal(void) {
  my_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  return result;
}
