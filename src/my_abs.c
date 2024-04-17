#include "my_decimal.h"

my_decimal my_abs(my_decimal value_1) {
  my_decimal result = value_1;
  my_set_sign_for_decimal(&result, MY_POSITIVE);
  return result;
}
