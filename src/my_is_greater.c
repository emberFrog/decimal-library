#include "my_decimal.h"

int my_is_greater(my_decimal value_1, my_decimal value_2) {
  return my_is_less(value_2, value_1);
}
