#include "s21_decimal.h"

s21_decimal s21_decimal_get_from_char(char c) {
  s21_decimal result;

  switch (c) {
    case '0':
      result = s21_get_zero_for_decimal();
      break;
    case '1':
      result = s21_get_one_for_decimal();
      break;
    case '2':
      s21_from_int_to_decimal(2, &result);
      break;
    case '3':
      s21_from_int_to_decimal(3, &result);
      break;
    case '4':
      s21_from_int_to_decimal(4, &result);
      break;
    case '5':
      s21_from_int_to_decimal(5, &result);
      break;
    case '6':
      s21_from_int_to_decimal(6, &result);
      break;
    case '7':
      s21_from_int_to_decimal(7, &result);
      break;
    case '8':
      s21_from_int_to_decimal(8, &result);
      break;
    case '9':
      s21_from_int_to_decimal(9, &result);
      break;
  }

  return result;
}

int s21_get_float_exp_from_string(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'E') {
      ++ptr;
      result = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }

  return result;
}

s21_decimal s21_float_string_to_decimal(char *str) {
  int digits_counter = 6;
  s21_decimal result = s21_get_zero_for_decimal();
  char *ptr = str;

  int exp = s21_get_float_exp_from_string(str);

  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
      continue;
    } else if (*ptr >= '0' && *ptr <= '9') {
      s21_decimal tmp = s21_get_zero_for_decimal();
      s21_mul(s21_decimal_get_from_char(*ptr),
              s21_get_ten_for_int128(digits_counter), &tmp);
      s21_add(result, tmp, &result);
      --digits_counter;
      ++ptr;
    } else {
      break;
    }
  }
  exp = exp - 6;

  if (exp > 0) {
    s21_mul(result, s21_get_ten_for_int128(exp), &result);
  } else if (exp < 0) {
    if (exp < -28) {
      s21_div(result, s21_get_ten_for_int128(28), &result);
      exp += 28;
    }
    s21_div(result, s21_get_ten_for_int128(-exp), &result);
  }

  return result;
}
