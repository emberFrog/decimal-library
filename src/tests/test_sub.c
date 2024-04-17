#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_sub_fail_manual1) {
  // 792281625.14264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = my_sub(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_sub_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal1 = {{0, 0, 0, 1000000000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual9) {
  // Просто все единицы
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal2 = {{0, 0, 0, 1000000000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_sub_fail_manual17) {
  // Просто все единицы
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на все типы данных (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_sub_manual1) {
  // 7.922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  my_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 3.9614081257132168796771975172
  my_decimal check = {{0x4, 0x0, 0x80000000, 0x1C0000}};

  test_sub(decimal1, decimal2, check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests all data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_sub1) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub2) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub3) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub4) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub5) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub6) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub7) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub8) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub9) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub10) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub11) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub12) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub13) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub14) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub15) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub16) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub17) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub18) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub19) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub20) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub21) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub22) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub23) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub24) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub25) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 52818775009509558395695966890
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub26) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub27) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 52818775015658473085500828330
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub28) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub29) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 79228162508115422902307433130
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub30) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub31) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 79228162508115422903739088895
  my_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub32) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub33) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337592112294570
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub34) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub35) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub36) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub37) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub38) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub39) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub40) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub41) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub42) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub43) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub44) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub45) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 79228162514264337593543950331
  my_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub46) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub47) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub48) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub49) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub50) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub51) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub52) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub53) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub54) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub55) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 79228162514264337593543949689
  my_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub56) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub57) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub58) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 79228162514240090656400479551
  my_decimal check = {{0x4AC153F, 0xFFA9DB8A, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub59) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // 18994429982494779296567793531
  my_decimal check = {{0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub60) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub61) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub62) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  my_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub63) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub64) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub65) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub66) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub67) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub68) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub69) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub70) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub71) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub72) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub73) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub74) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub75) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub76) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub77) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub78) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub79) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub80) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub81) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub82) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub83) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub84) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub85) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub86) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -52818775009509558395695966890
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub87) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub88) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -52818775015658473085500828330
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub89) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub90) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422902307433130
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub91) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub92) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -79228162508115422903739088895
  my_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub93) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub94) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337592112294570
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub95) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub96) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // -79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub97) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub98) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub99) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub100) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub101) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub102) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub103) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub104) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub105) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub106) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // -79228162514264337593543950331
  my_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub107) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub108) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub109) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub110) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub111) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub112) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub113) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub114) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub115) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub116) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // -79228162514264337593543949689
  my_decimal check = {{0xFFFFFD79, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub117) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // -79228162514240090656400479551
  my_decimal check = {{0x4AC153F, 0xFFA9DB8A, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub118) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub119) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub120) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // -18994429982494779296567793531
  my_decimal check = {{0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub121) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub122) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub123) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub124) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub125) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub126) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub127) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub128) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub129) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub130) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub131) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // 71305346262837903834189555299
  my_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub132) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub133) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub134) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub135) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub136) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub137) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub138) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub139) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub140) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub141) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162514264337593543950332
  my_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub142) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub143) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub144) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub145) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 52818775009509558395695966889
  my_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub146) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub147) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 52818775015658473085500828329
  my_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub148) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub149) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // 79228162508115422902307433129
  my_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub150) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub151) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // 79228162508115422903739088894
  my_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub152) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub153) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337592112294569
  my_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub154) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub155) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 79228162514264337593517540946
  my_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub156) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub157) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub158) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub159) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub160) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub161) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950326
  my_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub162) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub163) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950326
  my_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub164) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub165) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 79228162514264337593543950330
  my_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub166) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub167) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub168) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub169) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub170) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub171) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub172) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub173) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub174) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub175) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x1A0000}};
  // 79228162514264337593543949688
  my_decimal check = {{0xFFFFFD78, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub176) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -646.33673839575124685661598885
  my_decimal decimal2 = {{0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub177) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub178) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 24246937143470783.81744120110
  my_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000}};
  // 79228162514240090656400479550
  my_decimal check = {{0x4AC153E, 0xFFA9DB8A, 0xFFFFFFFF, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub179) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0}};
  // 18994429982494779296567793530
  my_decimal check = {{0xB3DC177A, 0x9B738FD3, 0x3D5FD300, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub180) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60233732531769558296976156804
  my_decimal decimal2 = {{0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub181) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub182) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub183) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub184) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  my_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub185) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub186) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub187) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub188) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub189) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub190) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub191) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_sub_fail(decimal1, decimal2, check);
}

START_TEST(test_sub192) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // -71305346262837903834189555299
  my_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub193) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub194) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub195) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub196) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub197) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub198) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub199) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

START_TEST(test_sub200) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_sub(decimal1, decimal2, check);
}

Suite *sub_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sub1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sub1);
  tcase_add_test(tc_core, test_sub2);
  tcase_add_test(tc_core, test_sub3);
  tcase_add_test(tc_core, test_sub4);
  tcase_add_test(tc_core, test_sub5);
  tcase_add_test(tc_core, test_sub6);
  tcase_add_test(tc_core, test_sub7);
  tcase_add_test(tc_core, test_sub8);
  tcase_add_test(tc_core, test_sub9);
  tcase_add_test(tc_core, test_sub10);
  tcase_add_test(tc_core, test_sub11);
  tcase_add_test(tc_core, test_sub12);
  tcase_add_test(tc_core, test_sub13);
  tcase_add_test(tc_core, test_sub14);
  tcase_add_test(tc_core, test_sub15);
  tcase_add_test(tc_core, test_sub16);
  tcase_add_test(tc_core, test_sub17);
  tcase_add_test(tc_core, test_sub18);
  tcase_add_test(tc_core, test_sub19);
  tcase_add_test(tc_core, test_sub20);
  tcase_add_test(tc_core, test_sub21);
  tcase_add_test(tc_core, test_sub22);
  tcase_add_test(tc_core, test_sub23);
  tcase_add_test(tc_core, test_sub24);
  tcase_add_test(tc_core, test_sub25);
  tcase_add_test(tc_core, test_sub26);
  tcase_add_test(tc_core, test_sub27);
  tcase_add_test(tc_core, test_sub28);
  tcase_add_test(tc_core, test_sub29);
  tcase_add_test(tc_core, test_sub30);
  tcase_add_test(tc_core, test_sub31);
  tcase_add_test(tc_core, test_sub32);
  tcase_add_test(tc_core, test_sub33);
  tcase_add_test(tc_core, test_sub34);
  tcase_add_test(tc_core, test_sub35);
  tcase_add_test(tc_core, test_sub36);
  tcase_add_test(tc_core, test_sub37);
  tcase_add_test(tc_core, test_sub38);
  tcase_add_test(tc_core, test_sub39);
  tcase_add_test(tc_core, test_sub40);
  tcase_add_test(tc_core, test_sub41);
  tcase_add_test(tc_core, test_sub42);
  tcase_add_test(tc_core, test_sub43);
  tcase_add_test(tc_core, test_sub44);
  tcase_add_test(tc_core, test_sub45);
  tcase_add_test(tc_core, test_sub46);
  tcase_add_test(tc_core, test_sub47);
  tcase_add_test(tc_core, test_sub48);
  tcase_add_test(tc_core, test_sub49);
  tcase_add_test(tc_core, test_sub50);
  tcase_add_test(tc_core, test_sub51);
  tcase_add_test(tc_core, test_sub52);
  tcase_add_test(tc_core, test_sub53);
  tcase_add_test(tc_core, test_sub54);
  tcase_add_test(tc_core, test_sub55);
  tcase_add_test(tc_core, test_sub56);
  tcase_add_test(tc_core, test_sub57);
  tcase_add_test(tc_core, test_sub58);
  tcase_add_test(tc_core, test_sub59);
  tcase_add_test(tc_core, test_sub60);
  tcase_add_test(tc_core, test_sub61);
  tcase_add_test(tc_core, test_sub62);
  tcase_add_test(tc_core, test_sub63);
  tcase_add_test(tc_core, test_sub64);
  tcase_add_test(tc_core, test_sub65);
  tcase_add_test(tc_core, test_sub66);
  tcase_add_test(tc_core, test_sub67);
  tcase_add_test(tc_core, test_sub68);
  tcase_add_test(tc_core, test_sub69);
  tcase_add_test(tc_core, test_sub70);
  tcase_add_test(tc_core, test_sub71);
  tcase_add_test(tc_core, test_sub72);
  tcase_add_test(tc_core, test_sub73);
  tcase_add_test(tc_core, test_sub74);
  tcase_add_test(tc_core, test_sub75);
  tcase_add_test(tc_core, test_sub76);
  tcase_add_test(tc_core, test_sub77);
  tcase_add_test(tc_core, test_sub78);
  tcase_add_test(tc_core, test_sub79);
  tcase_add_test(tc_core, test_sub80);
  tcase_add_test(tc_core, test_sub81);
  tcase_add_test(tc_core, test_sub82);
  tcase_add_test(tc_core, test_sub83);
  tcase_add_test(tc_core, test_sub84);
  tcase_add_test(tc_core, test_sub85);
  tcase_add_test(tc_core, test_sub86);
  tcase_add_test(tc_core, test_sub87);
  tcase_add_test(tc_core, test_sub88);
  tcase_add_test(tc_core, test_sub89);
  tcase_add_test(tc_core, test_sub90);
  tcase_add_test(tc_core, test_sub91);
  tcase_add_test(tc_core, test_sub92);
  tcase_add_test(tc_core, test_sub93);
  tcase_add_test(tc_core, test_sub94);
  tcase_add_test(tc_core, test_sub95);
  tcase_add_test(tc_core, test_sub96);
  tcase_add_test(tc_core, test_sub97);
  tcase_add_test(tc_core, test_sub98);
  tcase_add_test(tc_core, test_sub99);
  tcase_add_test(tc_core, test_sub100);
  tcase_add_test(tc_core, test_sub101);
  tcase_add_test(tc_core, test_sub102);
  tcase_add_test(tc_core, test_sub103);
  tcase_add_test(tc_core, test_sub104);
  tcase_add_test(tc_core, test_sub105);
  tcase_add_test(tc_core, test_sub106);
  tcase_add_test(tc_core, test_sub107);
  tcase_add_test(tc_core, test_sub108);
  tcase_add_test(tc_core, test_sub109);
  tcase_add_test(tc_core, test_sub110);
  tcase_add_test(tc_core, test_sub111);
  tcase_add_test(tc_core, test_sub112);
  tcase_add_test(tc_core, test_sub113);
  tcase_add_test(tc_core, test_sub114);
  tcase_add_test(tc_core, test_sub115);
  tcase_add_test(tc_core, test_sub116);
  tcase_add_test(tc_core, test_sub117);
  tcase_add_test(tc_core, test_sub118);
  tcase_add_test(tc_core, test_sub119);
  tcase_add_test(tc_core, test_sub120);
  tcase_add_test(tc_core, test_sub121);
  tcase_add_test(tc_core, test_sub122);
  tcase_add_test(tc_core, test_sub123);
  tcase_add_test(tc_core, test_sub124);
  tcase_add_test(tc_core, test_sub125);
  tcase_add_test(tc_core, test_sub126);
  tcase_add_test(tc_core, test_sub127);
  tcase_add_test(tc_core, test_sub128);
  tcase_add_test(tc_core, test_sub129);
  tcase_add_test(tc_core, test_sub130);
  tcase_add_test(tc_core, test_sub131);
  tcase_add_test(tc_core, test_sub132);
  tcase_add_test(tc_core, test_sub133);
  tcase_add_test(tc_core, test_sub134);
  tcase_add_test(tc_core, test_sub135);
  tcase_add_test(tc_core, test_sub136);
  tcase_add_test(tc_core, test_sub137);
  tcase_add_test(tc_core, test_sub138);
  tcase_add_test(tc_core, test_sub139);
  tcase_add_test(tc_core, test_sub140);
  tcase_add_test(tc_core, test_sub141);
  tcase_add_test(tc_core, test_sub142);
  tcase_add_test(tc_core, test_sub143);
  tcase_add_test(tc_core, test_sub144);
  tcase_add_test(tc_core, test_sub145);
  tcase_add_test(tc_core, test_sub146);
  tcase_add_test(tc_core, test_sub147);
  tcase_add_test(tc_core, test_sub148);
  tcase_add_test(tc_core, test_sub149);
  tcase_add_test(tc_core, test_sub150);
  tcase_add_test(tc_core, test_sub151);
  tcase_add_test(tc_core, test_sub152);
  tcase_add_test(tc_core, test_sub153);
  tcase_add_test(tc_core, test_sub154);
  tcase_add_test(tc_core, test_sub155);
  tcase_add_test(tc_core, test_sub156);
  tcase_add_test(tc_core, test_sub157);
  tcase_add_test(tc_core, test_sub158);
  tcase_add_test(tc_core, test_sub159);
  tcase_add_test(tc_core, test_sub160);
  tcase_add_test(tc_core, test_sub161);
  tcase_add_test(tc_core, test_sub162);
  tcase_add_test(tc_core, test_sub163);
  tcase_add_test(tc_core, test_sub164);
  tcase_add_test(tc_core, test_sub165);
  tcase_add_test(tc_core, test_sub166);
  tcase_add_test(tc_core, test_sub167);
  tcase_add_test(tc_core, test_sub168);
  tcase_add_test(tc_core, test_sub169);
  tcase_add_test(tc_core, test_sub170);
  tcase_add_test(tc_core, test_sub171);
  tcase_add_test(tc_core, test_sub172);
  tcase_add_test(tc_core, test_sub173);
  tcase_add_test(tc_core, test_sub174);
  tcase_add_test(tc_core, test_sub175);
  tcase_add_test(tc_core, test_sub176);
  tcase_add_test(tc_core, test_sub177);
  tcase_add_test(tc_core, test_sub178);
  tcase_add_test(tc_core, test_sub179);
  tcase_add_test(tc_core, test_sub180);
  tcase_add_test(tc_core, test_sub181);
  tcase_add_test(tc_core, test_sub182);
  tcase_add_test(tc_core, test_sub183);
  tcase_add_test(tc_core, test_sub184);
  tcase_add_test(tc_core, test_sub185);
  tcase_add_test(tc_core, test_sub186);
  tcase_add_test(tc_core, test_sub187);
  tcase_add_test(tc_core, test_sub188);
  tcase_add_test(tc_core, test_sub189);
  tcase_add_test(tc_core, test_sub190);
  tcase_add_test(tc_core, test_sub191);
  tcase_add_test(tc_core, test_sub192);
  tcase_add_test(tc_core, test_sub193);
  tcase_add_test(tc_core, test_sub194);
  tcase_add_test(tc_core, test_sub195);
  tcase_add_test(tc_core, test_sub196);
  tcase_add_test(tc_core, test_sub197);
  tcase_add_test(tc_core, test_sub198);
  tcase_add_test(tc_core, test_sub199);
  tcase_add_test(tc_core, test_sub200);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *sub_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("sub0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sub_fail_manual1);
  tcase_add_test(tc_core, test_sub_fail_manual2);
  tcase_add_test(tc_core, test_sub_fail_manual3);
  tcase_add_test(tc_core, test_sub_fail_manual4);
  tcase_add_test(tc_core, test_sub_fail_manual5);
  tcase_add_test(tc_core, test_sub_fail_manual6);
  tcase_add_test(tc_core, test_sub_fail_manual7);
  tcase_add_test(tc_core, test_sub_fail_manual8);
  tcase_add_test(tc_core, test_sub_fail_manual9);
  tcase_add_test(tc_core, test_sub_fail_manual10);
  tcase_add_test(tc_core, test_sub_fail_manual11);
  tcase_add_test(tc_core, test_sub_fail_manual12);
  tcase_add_test(tc_core, test_sub_fail_manual13);
  tcase_add_test(tc_core, test_sub_fail_manual14);
  tcase_add_test(tc_core, test_sub_fail_manual15);
  tcase_add_test(tc_core, test_sub_fail_manual16);
  tcase_add_test(tc_core, test_sub_fail_manual17);

  tcase_add_test(tc_core, test_sub_manual1);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_sub(my_decimal decimal1, my_decimal decimal2, my_decimal check) {
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);
#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  my_print_decimal_bits(decimal1);
  my_print_decimal_string(decimal1);
  my_print_decimal_bits(decimal2);
  my_print_decimal_string(decimal2);
  printf("\ncheck:\n");
  my_print_decimal_bits(check);
  my_print_decimal_string(check);
  printf("\nres:\n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
  printf("---------------------------------\n");
#endif
  ck_assert_int_eq(my_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_sub_fail(my_decimal decimal1, my_decimal decimal2, int check) {
  my_decimal result;
  int code = my_sub(decimal1, decimal2, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  my_print_decimal_bits(decimal1);
  my_print_decimal_string(decimal1);
  my_print_decimal_bits(decimal2);
  my_print_decimal_string(decimal2);
  printf("\nres:\n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(code, check);
}
