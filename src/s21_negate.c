#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_other_result ERROR_CODE = S21_OTHER_OK;

  if (!result) {
    ERROR_CODE = S21_OTHER_ERROR;
  } else {
    *result = value;
    s21_set_sign_for_decimal(result, !s21_get_sign_decimal(*result));

    if (!s21_check_decimal(value)) {
      ERROR_CODE = S21_OTHER_ERROR;
    }
  }

  return ERROR_CODE;
}
