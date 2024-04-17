#include "s21_decimal.h"

s21_decimal s21_abs(s21_decimal value_1) {
  s21_decimal result = value_1;
  s21_set_sign_for_decimal(&result, S21_POSITIVE);
  return result;
}
