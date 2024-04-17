#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../s21_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_div_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_div(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_div_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_div_fail_manual17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на все типы данных (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_div_manual1) {
  // 1.2640938749860586450804312205
  s21_decimal decimal1 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 0.6320469374930293225402156102
  s21_decimal check = {{0x8C444446, 0x5F128130, 0x146C2B73, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual2) {
  // 2
  s21_decimal decimal1 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.2640938749860586450804312205
  s21_decimal decimal2 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 1.5821609767882606564463392905
  s21_decimal check = {{0x8B80B889, 0x20B8279E, 0x331F5430, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual3) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 12.640938749860586450805
  s21_decimal decimal2 = {{0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000}};
  // 113255494.17884722765619814067
  s21_decimal check = {{0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual4) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 500
  s21_decimal decimal2 = {{0x1F4, 0x0, 0x0, 0x0}};
  // 0.002
  s21_decimal check = {{0x2, 0x0, 0x0, 0x30000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual6) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual8) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 156064767525876035022225408
  s21_decimal decimal2 = {{0x0, 0x0, 0x811800, 0x0}};
  // -169.22068909868474138626644073
  s21_decimal check = {{0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual9) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -429496729.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  // 61489146926681729710
  s21_decimal check = {{0xAAAAAAAE, 0x55555558, 0x3, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual10) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual11) {
  // 1.2640938749860586450804312207
  s21_decimal decimal1 = {{0x1888888F, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2.0000000000000000000000000000
  s21_decimal decimal2 = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.6320469374930293225402156104
  s21_decimal check = {{0x8C444448, 0x5F128130, 0x146C2B73, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual12) {
  // 3.6336660283201536
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 36336660283201536000000000000
  s21_decimal check = {{0x89800000, 0xFEE8FB1C, 0x7568FB1C, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual13) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual17) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}

START_TEST(test_div_manual18) {
  // 0.0000000074505801528346182749
  s21_decimal decimal1 = {{0xCAD4845D, 0x9F9C7BD, 0x4, 0x1C0000}};
  // 1152921504606846976
  s21_decimal decimal2 = {{0x0, 0x10000000, 0x0, 0x0}};
  // 0.0000000000000000000000000065
  s21_decimal decimal_check = {{0x41, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual19) {
  // 0.0000000000000000000542101054
  s21_decimal decimal1 = {{0x204FCE3E, 0x0, 0x0, 0x1C0000}};
  // 8388608
  s21_decimal decimal2 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000000000065
  s21_decimal decimal_check = {{0x41, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual20) {
  // 8388608
  s21_decimal decimal1 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000542101054
  s21_decimal decimal2 = {{0x204FCE3E, 0x0, 0x0, 0x1C0000}};
  // 154742514114351823414827745.38
  s21_decimal decimal_check = {{0x6306800A, 0xE4ABBB05, 0x32000031, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual21) {
  // 0.0000000000000000000020971522
  s21_decimal decimal1 = {{0x1400002, 0x0, 0x0, 0x1C0000}};
  // 8388608
  s21_decimal decimal2 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000000000003
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual22) {
  // 8388608
  s21_decimal decimal1 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000020971522
  s21_decimal decimal2 = {{0x1400002, 0x0, 0x0, 0x1C0000}};
  // 3999999618530309817284601470.5
  s21_decimal decimal_check = {{0x695280F1, 0x2D062C6F, 0x813F38AA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual23) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}

START_TEST(test_div_manual24) {
  // 79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual25) {
  // -79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual26) {
  // 79228162514264337593543950319
  s21_decimal decimal1 = {{0xFFFFFFEF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual27) {
  // 79228162514264337593543950319
  s21_decimal decimal1 = {{0xFFFFFFEF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests all data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_div1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 20000000000000000000000000000
  s21_decimal decimal_check = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -20000000000000000000000000000
  s21_decimal decimal_check = {
      {0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div62) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 55340232234013556739000000000
  s21_decimal decimal_check = {{0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div64) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -55340232234013556739000000000
  s21_decimal decimal_check = {
      {0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 9364712231340627836019760.833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div66) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -9364712231340627836019760.833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div68) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013500763574019524425909
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div70) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -79149013500763574019524425909
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div72) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div74) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div76) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div78) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div80) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div82) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div84) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -20000000000000000000000000000
  s21_decimal decimal_check = {
      {0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 20000000000000000000000000000
  s21_decimal decimal_check = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div101) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div102) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div103) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div104) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div105) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div106) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div107) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div108) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div109) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div110) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div111) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div112) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div114) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div118) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div120) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div122) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div124) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div126) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div128) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div130) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div132) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div134) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div136) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div138) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div140) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div142) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div144) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div146) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -55340232234013556739000000000
  s21_decimal decimal_check = {
      {0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div148) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 55340232234013556739000000000
  s21_decimal decimal_check = {{0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -9364712231340627836019760.833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div150) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 9364712231340627836019760.833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div152) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -79149013500763574019524425909
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div154) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 79149013500763574019524425909
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div156) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div158) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div160) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div162) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div164) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div166) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div168) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div169) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div170) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div171) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div172) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div173) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div174) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div175) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div176) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div177) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div178) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div179) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div180) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div181) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div182) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div183) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div184) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div185) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div186) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div187) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div188) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div189) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div190) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div191) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div192) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div193) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 1584563250285286751870879006.7
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div194) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -1584563250285286751870879006.7
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div195) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div196) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div197) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div198) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div199) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div200) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

Suite *div_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("div1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_div1);
  tcase_add_test(tc_core, test_div2);
  tcase_add_test(tc_core, test_div3);
  tcase_add_test(tc_core, test_div4);
  tcase_add_test(tc_core, test_div5);
  tcase_add_test(tc_core, test_div6);
  tcase_add_test(tc_core, test_div7);
  tcase_add_test(tc_core, test_div8);
  tcase_add_test(tc_core, test_div9);
  tcase_add_test(tc_core, test_div10);
  tcase_add_test(tc_core, test_div11);
  tcase_add_test(tc_core, test_div12);
  tcase_add_test(tc_core, test_div13);
  tcase_add_test(tc_core, test_div14);
  tcase_add_test(tc_core, test_div15);
  tcase_add_test(tc_core, test_div16);
  tcase_add_test(tc_core, test_div17);
  tcase_add_test(tc_core, test_div18);
  tcase_add_test(tc_core, test_div19);
  tcase_add_test(tc_core, test_div20);
  tcase_add_test(tc_core, test_div21);
  tcase_add_test(tc_core, test_div22);
  tcase_add_test(tc_core, test_div23);
  tcase_add_test(tc_core, test_div24);
  tcase_add_test(tc_core, test_div25);
  tcase_add_test(tc_core, test_div26);
  tcase_add_test(tc_core, test_div27);
  tcase_add_test(tc_core, test_div28);
  tcase_add_test(tc_core, test_div29);
  tcase_add_test(tc_core, test_div30);
  tcase_add_test(tc_core, test_div31);
  tcase_add_test(tc_core, test_div32);
  tcase_add_test(tc_core, test_div33);
  tcase_add_test(tc_core, test_div34);
  tcase_add_test(tc_core, test_div35);
  tcase_add_test(tc_core, test_div36);
  tcase_add_test(tc_core, test_div37);
  tcase_add_test(tc_core, test_div38);
  tcase_add_test(tc_core, test_div39);
  tcase_add_test(tc_core, test_div40);
  tcase_add_test(tc_core, test_div41);
  tcase_add_test(tc_core, test_div42);
  tcase_add_test(tc_core, test_div43);
  tcase_add_test(tc_core, test_div44);
  tcase_add_test(tc_core, test_div45);
  tcase_add_test(tc_core, test_div46);
  tcase_add_test(tc_core, test_div47);
  tcase_add_test(tc_core, test_div48);
  tcase_add_test(tc_core, test_div49);
  tcase_add_test(tc_core, test_div50);
  tcase_add_test(tc_core, test_div51);
  tcase_add_test(tc_core, test_div52);
  tcase_add_test(tc_core, test_div53);
  tcase_add_test(tc_core, test_div54);
  tcase_add_test(tc_core, test_div55);
  tcase_add_test(tc_core, test_div56);
  tcase_add_test(tc_core, test_div57);
  tcase_add_test(tc_core, test_div58);
  tcase_add_test(tc_core, test_div59);
  tcase_add_test(tc_core, test_div60);
  tcase_add_test(tc_core, test_div61);
  tcase_add_test(tc_core, test_div62);
  tcase_add_test(tc_core, test_div63);
  tcase_add_test(tc_core, test_div64);
  tcase_add_test(tc_core, test_div65);
  tcase_add_test(tc_core, test_div66);
  tcase_add_test(tc_core, test_div67);
  tcase_add_test(tc_core, test_div68);
  tcase_add_test(tc_core, test_div69);
  tcase_add_test(tc_core, test_div70);
  tcase_add_test(tc_core, test_div71);
  tcase_add_test(tc_core, test_div72);
  tcase_add_test(tc_core, test_div73);
  tcase_add_test(tc_core, test_div74);
  tcase_add_test(tc_core, test_div75);
  tcase_add_test(tc_core, test_div76);
  tcase_add_test(tc_core, test_div77);
  tcase_add_test(tc_core, test_div78);
  tcase_add_test(tc_core, test_div79);
  tcase_add_test(tc_core, test_div80);
  tcase_add_test(tc_core, test_div81);
  tcase_add_test(tc_core, test_div82);
  tcase_add_test(tc_core, test_div83);
  tcase_add_test(tc_core, test_div84);
  tcase_add_test(tc_core, test_div85);
  tcase_add_test(tc_core, test_div86);
  tcase_add_test(tc_core, test_div87);
  tcase_add_test(tc_core, test_div88);
  tcase_add_test(tc_core, test_div89);
  tcase_add_test(tc_core, test_div90);
  tcase_add_test(tc_core, test_div91);
  tcase_add_test(tc_core, test_div92);
  tcase_add_test(tc_core, test_div93);
  tcase_add_test(tc_core, test_div94);
  tcase_add_test(tc_core, test_div95);
  tcase_add_test(tc_core, test_div96);
  tcase_add_test(tc_core, test_div97);
  tcase_add_test(tc_core, test_div98);
  tcase_add_test(tc_core, test_div99);
  tcase_add_test(tc_core, test_div100);
  tcase_add_test(tc_core, test_div101);
  tcase_add_test(tc_core, test_div102);
  tcase_add_test(tc_core, test_div103);
  tcase_add_test(tc_core, test_div104);
  tcase_add_test(tc_core, test_div105);
  tcase_add_test(tc_core, test_div106);
  tcase_add_test(tc_core, test_div107);
  tcase_add_test(tc_core, test_div108);
  tcase_add_test(tc_core, test_div109);
  tcase_add_test(tc_core, test_div110);
  tcase_add_test(tc_core, test_div111);
  tcase_add_test(tc_core, test_div112);
  tcase_add_test(tc_core, test_div113);
  tcase_add_test(tc_core, test_div114);
  tcase_add_test(tc_core, test_div115);
  tcase_add_test(tc_core, test_div116);
  tcase_add_test(tc_core, test_div117);
  tcase_add_test(tc_core, test_div118);
  tcase_add_test(tc_core, test_div119);
  tcase_add_test(tc_core, test_div120);
  tcase_add_test(tc_core, test_div121);
  tcase_add_test(tc_core, test_div122);
  tcase_add_test(tc_core, test_div123);
  tcase_add_test(tc_core, test_div124);
  tcase_add_test(tc_core, test_div125);
  tcase_add_test(tc_core, test_div126);
  tcase_add_test(tc_core, test_div127);
  tcase_add_test(tc_core, test_div128);
  tcase_add_test(tc_core, test_div129);
  tcase_add_test(tc_core, test_div130);
  tcase_add_test(tc_core, test_div131);
  tcase_add_test(tc_core, test_div132);
  tcase_add_test(tc_core, test_div133);
  tcase_add_test(tc_core, test_div134);
  tcase_add_test(tc_core, test_div135);
  tcase_add_test(tc_core, test_div136);
  tcase_add_test(tc_core, test_div137);
  tcase_add_test(tc_core, test_div138);
  tcase_add_test(tc_core, test_div139);
  tcase_add_test(tc_core, test_div140);
  tcase_add_test(tc_core, test_div141);
  tcase_add_test(tc_core, test_div142);
  tcase_add_test(tc_core, test_div143);
  tcase_add_test(tc_core, test_div144);
  tcase_add_test(tc_core, test_div145);
  tcase_add_test(tc_core, test_div146);
  tcase_add_test(tc_core, test_div147);
  tcase_add_test(tc_core, test_div148);
  tcase_add_test(tc_core, test_div149);
  tcase_add_test(tc_core, test_div150);
  tcase_add_test(tc_core, test_div151);
  tcase_add_test(tc_core, test_div152);
  tcase_add_test(tc_core, test_div153);
  tcase_add_test(tc_core, test_div154);
  tcase_add_test(tc_core, test_div155);
  tcase_add_test(tc_core, test_div156);
  tcase_add_test(tc_core, test_div157);
  tcase_add_test(tc_core, test_div158);
  tcase_add_test(tc_core, test_div159);
  tcase_add_test(tc_core, test_div160);
  tcase_add_test(tc_core, test_div161);
  tcase_add_test(tc_core, test_div162);
  tcase_add_test(tc_core, test_div163);
  tcase_add_test(tc_core, test_div164);
  tcase_add_test(tc_core, test_div165);
  tcase_add_test(tc_core, test_div166);
  tcase_add_test(tc_core, test_div167);
  tcase_add_test(tc_core, test_div168);
  tcase_add_test(tc_core, test_div169);
  tcase_add_test(tc_core, test_div170);
  tcase_add_test(tc_core, test_div171);
  tcase_add_test(tc_core, test_div172);
  tcase_add_test(tc_core, test_div173);
  tcase_add_test(tc_core, test_div174);
  tcase_add_test(tc_core, test_div175);
  tcase_add_test(tc_core, test_div176);
  tcase_add_test(tc_core, test_div177);
  tcase_add_test(tc_core, test_div178);
  tcase_add_test(tc_core, test_div179);
  tcase_add_test(tc_core, test_div180);
  tcase_add_test(tc_core, test_div181);
  tcase_add_test(tc_core, test_div182);
  tcase_add_test(tc_core, test_div183);
  tcase_add_test(tc_core, test_div184);
  tcase_add_test(tc_core, test_div185);
  tcase_add_test(tc_core, test_div186);
  tcase_add_test(tc_core, test_div187);
  tcase_add_test(tc_core, test_div188);
  tcase_add_test(tc_core, test_div189);
  tcase_add_test(tc_core, test_div190);
  tcase_add_test(tc_core, test_div191);
  tcase_add_test(tc_core, test_div192);
  tcase_add_test(tc_core, test_div193);
  tcase_add_test(tc_core, test_div194);
  tcase_add_test(tc_core, test_div195);
  tcase_add_test(tc_core, test_div196);
  tcase_add_test(tc_core, test_div197);
  tcase_add_test(tc_core, test_div198);
  tcase_add_test(tc_core, test_div199);
  tcase_add_test(tc_core, test_div200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *div_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("div0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_div_fail_manual1);
  tcase_add_test(tc_core, test_div_fail_manual2);
  tcase_add_test(tc_core, test_div_fail_manual3);
  tcase_add_test(tc_core, test_div_fail_manual4);
  tcase_add_test(tc_core, test_div_fail_manual5);
  tcase_add_test(tc_core, test_div_fail_manual6);
  tcase_add_test(tc_core, test_div_fail_manual7);
  tcase_add_test(tc_core, test_div_fail_manual8);
  tcase_add_test(tc_core, test_div_fail_manual9);
  tcase_add_test(tc_core, test_div_fail_manual10);
  tcase_add_test(tc_core, test_div_fail_manual11);
  tcase_add_test(tc_core, test_div_fail_manual12);
  tcase_add_test(tc_core, test_div_fail_manual13);
  tcase_add_test(tc_core, test_div_fail_manual14);
  tcase_add_test(tc_core, test_div_fail_manual15);
  tcase_add_test(tc_core, test_div_fail_manual16);
  tcase_add_test(tc_core, test_div_fail_manual17);

  tcase_add_test(tc_core, test_div_manual1);
  tcase_add_test(tc_core, test_div_manual2);
  tcase_add_test(tc_core, test_div_manual3);
  tcase_add_test(tc_core, test_div_manual4);
  tcase_add_test(tc_core, test_div_manual5);
  tcase_add_test(tc_core, test_div_manual6);
  tcase_add_test(tc_core, test_div_manual7);
  tcase_add_test(tc_core, test_div_manual8);
  tcase_add_test(tc_core, test_div_manual9);
  tcase_add_test(tc_core, test_div_manual10);
  tcase_add_test(tc_core, test_div_manual11);
  tcase_add_test(tc_core, test_div_manual12);
  tcase_add_test(tc_core, test_div_manual13);
  tcase_add_test(tc_core, test_div_manual14);
  tcase_add_test(tc_core, test_div_manual15);
  tcase_add_test(tc_core, test_div_manual16);
  tcase_add_test(tc_core, test_div_manual17);
  tcase_add_test(tc_core, test_div_manual18);
  tcase_add_test(tc_core, test_div_manual19);
  tcase_add_test(tc_core, test_div_manual20);
  tcase_add_test(tc_core, test_div_manual21);
  tcase_add_test(tc_core, test_div_manual22);
  tcase_add_test(tc_core, test_div_manual23);
  tcase_add_test(tc_core, test_div_manual24);
  tcase_add_test(tc_core, test_div_manual25);
  tcase_add_test(tc_core, test_div_manual26);
  tcase_add_test(tc_core, test_div_manual27);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);
#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  s21_print_decimal_bits(decimal1);
  s21_print_decimal_string(decimal1);
  s21_print_decimal_bits(decimal2);
  s21_print_decimal_string(decimal2);
  printf("\ncheck:\n");
  s21_print_decimal_bits(check);
  s21_print_decimal_string(check);
  printf("\nres:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("---------------------------------\n");
#endif
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_div_fail1(s21_decimal decimal1, s21_decimal decimal2,
                    int code_check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  s21_print_decimal_bits(decimal1);
  s21_print_decimal_string(decimal1);
  s21_print_decimal_bits(decimal2);
  s21_print_decimal_string(decimal2);
  printf("\ncheck:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("\nres:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("Check: %d\n", code_check);
  printf("Result: %d\n", code);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(code, code_check);
}

void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  s21_print_decimal_bits(decimal1);
  s21_print_decimal_string(decimal1);
  s21_print_decimal_bits(decimal2);
  s21_print_decimal_string(decimal2);
  printf("\ncheck:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("\nres:\n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
  printf("Check: %d\n", code_check);
  printf("Result: %d\n", code);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(code, code_check);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
