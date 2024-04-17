#ifndef SRC_TESTS__HELPERS__DEBUG_H_
#define SRC_TESTS__HELPERS__DEBUG_H_

#include "./../my_decimal.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[93m"
#define OKCYAN "\033[96m"
#define RESET "\033[0m"

typedef union test_decimal_bytes {
  struct my_decimal d;
  struct {
    uint32_t part0;
    uint32_t part1;
    uint32_t part2;
    uint32_t empty2 : 16;
    uint32_t power : 8;
    uint32_t empty1 : 7;
    uint32_t sign : 1;
  } parts;
} test_decimal_bytes;

void my_print_bits(size_t const size, void const *const ptr, int color);
void my_print_bit(int number, int color);
void my_decimal_to_string(my_decimal decimal, char *res);
void my_format_decimal_to_str(my_decimal decimal, char *res);
void my_print_decimal_bits(my_decimal decimal);
void my_print_decimal_string(my_decimal decimal);
char *my_bin128_to_string(my_decimal decimal);

#endif  //  SRC_TESTS__HELPERS__DEBUG_H_
