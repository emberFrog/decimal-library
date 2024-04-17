#include "my_decimal.h"

my_decimal my_binary_and_int128(my_decimal decimal1, my_decimal decimal2) {
  my_decimal result = my_get_zero_for_decimal();
  result.bits[0] = decimal1.bits[0] & decimal2.bits[0];
  result.bits[1] = decimal1.bits[1] & decimal2.bits[1];
  result.bits[2] = decimal1.bits[2] & decimal2.bits[2];
  result.bits[3] = decimal1.bits[3] & decimal2.bits[3];

  return result;
}

my_decimal my_binary_xor_int128(my_decimal decimal1, my_decimal decimal2) {
  my_decimal result = my_get_zero_for_decimal();
  result.bits[0] = decimal1.bits[0] ^ decimal2.bits[0];
  result.bits[1] = decimal1.bits[1] ^ decimal2.bits[1];
  result.bits[2] = decimal1.bits[2] ^ decimal2.bits[2];
  result.bits[3] = decimal1.bits[3] ^ decimal2.bits[3];

  return result;
}

my_decimal my_binary_not_int128(my_decimal decimal) {
  my_decimal result = my_get_zero_for_decimal();
  result.bits[0] = ~decimal.bits[0];
  result.bits[1] = ~decimal.bits[1];
  result.bits[2] = ~decimal.bits[2];
  result.bits[3] = ~decimal.bits[3];

  return result;
}
