#ifndef SRC_TESTS_TEST_H_
#define SRC_TESTS_TEST_H_

#include <check.h>

#include "./../my_decimal.h"
#include "./_debug.h"

// Отображение отладочной информации в тестах
// #define __DEBUG 1

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

Suite *add_suite0(void);
Suite *add_suite1(void);

Suite *sub_suite0(void);
Suite *sub_suite1(void);

Suite *mul_suite0(void);
Suite *mul_suite1(void);

Suite *div_suite0(void);
Suite *div_suite1(void);

Suite *mod_suite0(void);
Suite *mod_suite1(void);

void test_add(my_decimal decimal1, my_decimal decimal2, my_decimal check);
void test_add_fail(my_decimal decimal1, my_decimal decimal2, int check);
void test_sub(my_decimal decimal1, my_decimal decimal2, my_decimal check);
void test_sub_fail(my_decimal decimal1, my_decimal decimal2, int check);
void test_mul(my_decimal decimal1, my_decimal decimal2, my_decimal check);
void test_mul_fail1(my_decimal decimal1, my_decimal decimal2, int code_check);
void test_mul_fail2(my_decimal decimal1, my_decimal decimal2,
                    my_decimal decimal_check, int code_check);
void test_div(my_decimal decimal1, my_decimal decimal2, my_decimal check);
void test_div_fail1(my_decimal decimal1, my_decimal decimal2, int code_check);
void test_div_fail2(my_decimal decimal1, my_decimal decimal2,
                    my_decimal decimal_check, int code_check);
void test_mod(my_decimal decimal1, my_decimal decimal2, my_decimal check);
void test_mod_fail(my_decimal decimal1, my_decimal decimal2, int code_check);

#define TEST_COMPARISON_FALSE 0
#define TEST_COMPARISON_TRUE 1

Suite *is_less_suite1(void);

Suite *is_equal_suite1(void);

Suite *is_less_or_equal_suite1(void);

Suite *is_greater_suite1(void);

Suite *is_greater_or_equal_suite1(void);

Suite *is_not_equal_suite1(void);

void test_is_less(my_decimal decimal1, my_decimal decimal2, int check);
void test_is_equal(my_decimal decimal1, my_decimal decimal2, int check);
void test_is_less_or_equal(my_decimal decimal1, my_decimal decimal2,
                           int check);
void test_is_greater(my_decimal decimal1, my_decimal decimal2, int check);
void test_is_greater_or_equal(my_decimal decimal1, my_decimal decimal2,
                              int check);
void test_is_not_equal(my_decimal decimal1, my_decimal decimal2, int check);

#define TEST_CONVERSION_OK 0
#define TEST_CONVERSION_ERROR 1

Suite *from_int_to_decimal_suite(void);

Suite *from_float_to_decimal_suite0(void);
Suite *from_float_to_decimal_suite1(void);

Suite *from_decimal_to_int_suite0(void);
Suite *from_decimal_to_int_suite1(void);

Suite *from_decimal_to_float_suite0(void);
Suite *from_decimal_to_float_suite1(void);
void test_from_int_to_decimal(int number, my_decimal decimal_check);
void test_from_float_to_decimal(int f, my_decimal decimal_check);
void test_from_decimal_to_int(my_decimal decimal, int check);
void test_from_decimal_to_int_fail(my_decimal decimal);
void test_from_decimal_to_float(my_decimal decimal, int check);

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

Suite *floor_suite0(void);
Suite *floor_suite1(void);

Suite *round_suite0(void);
Suite *round_suite1(void);

Suite *truncate_suite0(void);
Suite *truncate_suite1(void);

Suite *negate_suite0(void);
Suite *negate_suite1(void);

void test_floor(my_decimal decimal, my_decimal decimal_check);
void test_round(my_decimal decimal, my_decimal decimal_check);
void test_truncate(my_decimal decimal, my_decimal decimal_check);
void test_negate(my_decimal decimal, my_decimal decimal_check);

Suite *debug0(void);
Suite *debug1(void);
Suite *debug2(void);
Suite *debug3(void);

void test_debug(my_decimal decimal, char *check);

#define NUM_RANDOM_TEST 10

int my_random_int(int min, int max);
int test_decimal_get_sign(my_decimal value);
int test_decimal_get_power(my_decimal value);
int test_is_correct_decimal(my_decimal decimal);
int test_decimal_is_full_equal(my_decimal value_1, my_decimal value_2);

#endif  // SRC_TESTS_TEST_H_
