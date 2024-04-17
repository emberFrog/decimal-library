#include "my_decimal.h"

my_decimal my_decimal_get_from_char(char c) {
  my_decimal result;

  switch (c) {
    case '0':
      result = my_get_zero_for_decimal();
      break;
    case '1':
      result = my_get_one_for_decimal();
      break;
    case '2':
      my_from_int_to_decimal(2, &result);
      break;
    case '3':
      my_from_int_to_decimal(3, &result);
      break;
    case '4':
      my_from_int_to_decimal(4, &result);
      break;
    case '5':
      my_from_int_to_decimal(5, &result);
      break;
    case '6':
      my_from_int_to_decimal(6, &result);
      break;
    case '7':
      my_from_int_to_decimal(7, &result);
      break;
    case '8':
      my_from_int_to_decimal(8, &result);
      break;
    case '9':
      my_from_int_to_decimal(9, &result);
      break;
  }

  return result;
}

int my_get_float_exp_from_string(char *str) {
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

my_decimal my_float_string_to_decimal(char *str) {
  int digits_counter = 6;
  my_decimal result = my_get_zero_for_decimal();
  char *ptr = str;

  int exp = my_get_float_exp_from_string(str);

  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
      continue;
    } else if (*ptr >= '0' && *ptr <= '9') {
      my_decimal tmp = my_get_zero_for_decimal();
      my_mul(my_decimal_get_from_char(*ptr),
              my_get_ten_for_int128(digits_counter), &tmp);
      my_add(result, tmp, &result);
      --digits_counter;
      ++ptr;
    } else {
      break;
    }
  }
  exp = exp - 6;

  if (exp > 0) {
    my_mul(result, my_get_ten_for_int128(exp), &result);
  } else if (exp < 0) {
    if (exp < -28) {
      my_div(result, my_get_ten_for_int128(28), &result);
      exp += 28;
    }
    my_div(result, my_get_ten_for_int128(-exp), &result);
  }

  return result;
}
