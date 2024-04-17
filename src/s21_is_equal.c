#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_result ERROR_CODE = S21_COMPARISON_TRUE;

  s21_decimal tmp1 = s21_remove_trailing_zeros(value_1);
  s21_decimal tmp2 = s21_remove_trailing_zeros(value_2);

  if (tmp1.bits[0] == 0 && tmp1.bits[1] == 0 && tmp1.bits[2] == 0 &&
      tmp2.bits[0] == 0 && tmp2.bits[1] == 0 && tmp2.bits[2] == 0) {
    ERROR_CODE = S21_COMPARISON_TRUE;
  } else {
    ERROR_CODE = tmp1.bits[0] == tmp2.bits[0] && tmp1.bits[1] == tmp2.bits[1] &&
                 tmp1.bits[2] == tmp2.bits[2] && tmp1.bits[3] == tmp2.bits[3];
  }

  return ERROR_CODE;
}
