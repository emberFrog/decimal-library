#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_int_to_decimal_fail1) {
  int number = -2147483648;
  int result = my_from_int_to_decimal(number, NULL);

  ck_assert_int_eq(result, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на корректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_int_to_decimal_ok1) {
  int number = -2147483648;
  // Converted the Int32 value -2147483648 to the Decimal value -2147483648.
  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok2) {
  int number = -2147483647;
  // Converted the Int32 value -2147483647 to the Decimal value -2147483647.
  my_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok3) {
  int number = -214748364;
  // Converted the Int32 value -214748364 to the Decimal value -214748364.
  my_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok4) {
  int number = -214748;
  // Converted the Int32 value -214748 to the Decimal value -214748.
  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok5) {
  int number = -1000;
  // Converted the Int32 value -1000 to the Decimal value -1000.
  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok6) {
  int number = -1;
  // Converted the Int32 value -1 to the Decimal value -1.
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok7) {
  int number = 0;
  // Converted the Int32 value 0 to the Decimal value 0.
  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok8) {
  int number = 1;
  // Converted the Int32 value 1 to the Decimal value 1.
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok9) {
  int number = 1000;
  // Converted the Int32 value 1000 to the Decimal value 1000.
  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok10) {
  int number = 214748;
  // Converted the Int32 value 214748 to the Decimal value 214748.
  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok11) {
  int number = 214748364;
  // Converted the Int32 value 214748364 to the Decimal value 214748364.
  my_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok12) {
  int number = 2147483646;
  // Converted the Int32 value 2147483646 to the Decimal value 2147483646.
  my_decimal decimal_check = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_ok13) {
  int number = 2147483647;
  // Converted the Int32 value 2147483647 to the Decimal value 2147483647.
  my_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на рандомные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_int_to_decimal_ok_random1) {
  int num = my_random_int(1, INT_MAX - 1);
  my_decimal decimal_check1 = {{num, 0x0, 0x0, 0x0}};
  test_from_int_to_decimal(num, decimal_check1);
  my_decimal decimal_check2 = {{num, 0x0, 0x0, 0x80000000}};
  test_from_int_to_decimal(-num, decimal_check2);
}
END_TEST

Suite *from_int_to_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_int_to_decimal");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_int_to_decimal_fail1);

  tcase_add_test(tc_core, test_from_int_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok5);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok6);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok7);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok8);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok9);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok10);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok11);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok12);
  tcase_add_test(tc_core, test_from_int_to_decimal_ok13);

  tcase_add_loop_test(tc_core, test_from_int_to_decimal_ok_random1, 0,
                      NUM_RANDOM_TEST);

  suite_add_tcase(s, tc_core);

  return s;
}

void test_from_int_to_decimal(int number, my_decimal decimal_check) {
  my_decimal result;
  int code = my_from_int_to_decimal(number, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("Test:\n");
  printf("number: %d\n", number);
  printf("Check:\n");
  my_print_decimal_bits(decimal_check);
  my_print_decimal_string(decimal_check);
  printf("sign = %d\n", sign_check);
  printf("Result:\n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
  printf("sign = %d\n", sign_check);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(my_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
