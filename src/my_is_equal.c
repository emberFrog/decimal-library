#include "my_decimal.h"

int my_is_equal(my_decimal value_1, my_decimal value_2) {
  my_comparison_result ERROR_CODE = MY_COMPARISON_TRUE;

  my_decimal tmp1 = my_remove_trailing_zeros(value_1);
  my_decimal tmp2 = my_remove_trailing_zeros(value_2);

  if (tmp1.bits[0] == 0 && tmp1.bits[1] == 0 && tmp1.bits[2] == 0 &&
      tmp2.bits[0] == 0 && tmp2.bits[1] == 0 && tmp2.bits[2] == 0) {
    ERROR_CODE = MY_COMPARISON_TRUE;
  } else {
    ERROR_CODE = tmp1.bits[0] == tmp2.bits[0] && tmp1.bits[1] == tmp2.bits[1] &&
                 tmp1.bits[2] == tmp2.bits[2] && tmp1.bits[3] == tmp2.bits[3];
  }

  return ERROR_CODE;
}
