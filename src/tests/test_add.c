#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_add_fail_manual1) {
  // 792281625.14264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = my_add(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_add_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal1 = {{0, 0, 0, 1000000000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual9) {
  // Просто все единицы
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal2 = {{0, 0, 0, 1000000000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_add_fail_manual17) {
  // Просто все единицы
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на все типы данных (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_add_manual1) {
  // 7.922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};
  // 3.9614081257132168796771975168
  my_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 11.884224377139650639031592551
  my_decimal check = {{0x66666667, 0x66666666, 0x26666666, 0x1B0000}};

  test_add(decimal1, decimal2, check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests all data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_add1) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add2) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add3) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add4) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add5) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add6) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add7) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add8) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add9) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add10) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add11) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add12) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add13) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add14) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add15) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add16) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add17) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add18) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add19) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add20) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add21) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add22) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add23) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add24) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add25) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add26) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 52818775009509558395695966890
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add27) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add28) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 52818775015658473085500828330
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add29) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add30) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433130
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add31) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add32) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422903739088895
  my_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add33) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add34) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337592112294570
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add35) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add36) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add37) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add38) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add39) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add40) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add41) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add42) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add43) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add44) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add45) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add46) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950331
  my_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add47) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add48) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add49) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add50) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add51) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add52) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add53) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add54) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add55) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 79228106389283212384222373411
  my_decimal check = {{0x3AC4E623, 0x756BD584, 0xFFFFF41D, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add56) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add57) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 79228162514264337543839948913
  my_decimal check = {{0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add58) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add59) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337592894706333
  my_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add60) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add61) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add62) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add63) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add64) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add65) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add66) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add67) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -71305346262837903834189555302
  my_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add68) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add69) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add70) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add71) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add72) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add73) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add74) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add75) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add76) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add77) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add78) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add79) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add80) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add81) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add82) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add83) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add84) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add85) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -52818775009509558395695966890
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add86) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add87) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // -52818775015658473085500828330
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add88) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add89) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -79228162508115422902307433130
  my_decimal check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add90) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add91) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162508115422903739088895
  my_decimal check = {{0xFFFFFFFF, 0xAAAAAAAA, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add92) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add93) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337592112294570
  my_decimal check = {{0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add94) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add95) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // -79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add96) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add97) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // -79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add98) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add99) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // -79228162514264337593517540948
  my_decimal check = {{0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add100) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add101) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add102) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add103) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950327
  my_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add104) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add105) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950331
  my_decimal check = {{0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add106) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add107) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add108) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add109) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add110) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add111) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add112) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add113) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add114) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add115) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add116) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // -79228106389283212384222373411
  my_decimal check = {{0x3AC4E623, 0x756BD584, 0xFFFFF41D, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add117) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add118) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // -79228162514264337543839948913
  my_decimal check = {{0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add119) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add120) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // -79228162514264337592894706333
  my_decimal check = {{0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add121) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add122) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add123) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add124) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add125) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add126) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add127) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add128) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add129) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add130) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add131) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add132) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555299
  my_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add133) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add134) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add135) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add136) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add137) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add138) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add139) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add140) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add141) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add142) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  my_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 79228162514264337593543950332
  my_decimal check = {{0xFFFFFFFC, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add143) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add144) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  my_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add145) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add146) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 52818775009509558395695966889
  my_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add147) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add148) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // 52818775015658473085500828329
  my_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add149) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add150) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914691236517205
  my_decimal decimal2 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422902307433129
  my_decimal check = {{0xAAAAAAA9, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add151) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add152) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -6148914689804861440
  my_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162508115422903739088894
  my_decimal check = {{0xFFFFFFFE, 0xAAAAAAAA, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add153) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add154) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337592112294569
  my_decimal check = {{0xAAAAAAA9, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add155) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add156) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.704754779197847983445
  my_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000}};
  // 79228162514264337593517540946
  my_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add157) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x150000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add158) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387.498605864508043122005
  my_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add159) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add160) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387
  my_decimal decimal2 = {{0x192F9AB, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593517540947
  my_decimal check = {{0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add161) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add162) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 79228162514264337593543950326
  my_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add163) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add164) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8
  my_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950326
  my_decimal check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add165) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add166) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.6336660283201536
  my_decimal decimal2 = {{0x811800, 0x811800, 0x0, 0x80100000}};
  // 79228162514264337593543950330
  my_decimal check = {{0xFFFFFFFA, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add167) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add168) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add169) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add170) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add171) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add172) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add173) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add174) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add175) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // 79228106389283212384222373410
  my_decimal check = {{0x3AC4E622, 0x756BD584, 0xFFFFF41D, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add176) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 56124981125209321576924.010631
  my_decimal decimal2 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add177) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // 79228162514264337543839948912
  my_decimal check = {{0x6D692070, 0xFFFFFFF4, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add178) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 49704001422.391670881925172831
  my_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x120000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add179) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000}};
  // 79228162514264337592894706332
  my_decimal check = {{0xD94D529C, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add180) {
  // 79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 649244002.20841517182548587502
  my_decimal decimal2 = {{0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000}};
  // overflow
  int check = TEST_ARITHMETIC_BIG;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add181) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add182) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add183) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add184) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add185) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555301
  my_decimal check = {{0x66666665, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add186) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add187) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add188) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add189) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555300
  my_decimal check = {{0x66666664, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add190) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add191) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -71305346262837903834189555299
  my_decimal check = {{0x66666663, 0x66666666, 0xE6666666, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add192) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395035
  my_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = TEST_ARITHMETIC_SMALL;

  test_add_fail(decimal1, decimal2, check);
}

START_TEST(test_add193) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add194) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add195) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add196) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  my_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add197) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add198) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.4999999999999999999999999999
  my_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950334
  my_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add199) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -79228162514264337593543950333
  my_decimal check = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

START_TEST(test_add200) {
  // -79228162514264337593543950334
  my_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  my_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_add(decimal1, decimal2, check);
}

Suite *add_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("add1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_add1);
  tcase_add_test(tc_core, test_add2);
  tcase_add_test(tc_core, test_add3);
  tcase_add_test(tc_core, test_add4);
  tcase_add_test(tc_core, test_add5);
  tcase_add_test(tc_core, test_add6);
  tcase_add_test(tc_core, test_add7);
  tcase_add_test(tc_core, test_add8);
  tcase_add_test(tc_core, test_add9);
  tcase_add_test(tc_core, test_add10);
  tcase_add_test(tc_core, test_add11);
  tcase_add_test(tc_core, test_add12);
  tcase_add_test(tc_core, test_add13);
  tcase_add_test(tc_core, test_add14);
  tcase_add_test(tc_core, test_add15);
  tcase_add_test(tc_core, test_add16);
  tcase_add_test(tc_core, test_add17);
  tcase_add_test(tc_core, test_add18);
  tcase_add_test(tc_core, test_add19);
  tcase_add_test(tc_core, test_add20);
  tcase_add_test(tc_core, test_add21);
  tcase_add_test(tc_core, test_add22);
  tcase_add_test(tc_core, test_add23);
  tcase_add_test(tc_core, test_add24);
  tcase_add_test(tc_core, test_add25);
  tcase_add_test(tc_core, test_add26);
  tcase_add_test(tc_core, test_add27);
  tcase_add_test(tc_core, test_add28);
  tcase_add_test(tc_core, test_add29);
  tcase_add_test(tc_core, test_add30);
  tcase_add_test(tc_core, test_add31);
  tcase_add_test(tc_core, test_add32);
  tcase_add_test(tc_core, test_add33);
  tcase_add_test(tc_core, test_add34);
  tcase_add_test(tc_core, test_add35);
  tcase_add_test(tc_core, test_add36);
  tcase_add_test(tc_core, test_add37);
  tcase_add_test(tc_core, test_add38);
  tcase_add_test(tc_core, test_add39);
  tcase_add_test(tc_core, test_add40);
  tcase_add_test(tc_core, test_add41);
  tcase_add_test(tc_core, test_add42);
  tcase_add_test(tc_core, test_add43);
  tcase_add_test(tc_core, test_add44);
  tcase_add_test(tc_core, test_add45);
  tcase_add_test(tc_core, test_add46);
  tcase_add_test(tc_core, test_add47);
  tcase_add_test(tc_core, test_add48);
  tcase_add_test(tc_core, test_add49);
  tcase_add_test(tc_core, test_add50);
  tcase_add_test(tc_core, test_add51);
  tcase_add_test(tc_core, test_add52);
  tcase_add_test(tc_core, test_add53);
  tcase_add_test(tc_core, test_add54);
  tcase_add_test(tc_core, test_add55);
  tcase_add_test(tc_core, test_add56);
  tcase_add_test(tc_core, test_add57);
  tcase_add_test(tc_core, test_add58);
  tcase_add_test(tc_core, test_add59);
  tcase_add_test(tc_core, test_add60);
  tcase_add_test(tc_core, test_add61);
  tcase_add_test(tc_core, test_add62);
  tcase_add_test(tc_core, test_add63);
  tcase_add_test(tc_core, test_add64);
  tcase_add_test(tc_core, test_add65);
  tcase_add_test(tc_core, test_add66);
  tcase_add_test(tc_core, test_add67);
  tcase_add_test(tc_core, test_add68);
  tcase_add_test(tc_core, test_add69);
  tcase_add_test(tc_core, test_add70);
  tcase_add_test(tc_core, test_add71);
  tcase_add_test(tc_core, test_add72);
  tcase_add_test(tc_core, test_add73);
  tcase_add_test(tc_core, test_add74);
  tcase_add_test(tc_core, test_add75);
  tcase_add_test(tc_core, test_add76);
  tcase_add_test(tc_core, test_add77);
  tcase_add_test(tc_core, test_add78);
  tcase_add_test(tc_core, test_add79);
  tcase_add_test(tc_core, test_add80);
  tcase_add_test(tc_core, test_add81);
  tcase_add_test(tc_core, test_add82);
  tcase_add_test(tc_core, test_add83);
  tcase_add_test(tc_core, test_add84);
  tcase_add_test(tc_core, test_add85);
  tcase_add_test(tc_core, test_add86);
  tcase_add_test(tc_core, test_add87);
  tcase_add_test(tc_core, test_add88);
  tcase_add_test(tc_core, test_add89);
  tcase_add_test(tc_core, test_add90);
  tcase_add_test(tc_core, test_add91);
  tcase_add_test(tc_core, test_add92);
  tcase_add_test(tc_core, test_add93);
  tcase_add_test(tc_core, test_add94);
  tcase_add_test(tc_core, test_add95);
  tcase_add_test(tc_core, test_add96);
  tcase_add_test(tc_core, test_add97);
  tcase_add_test(tc_core, test_add98);
  tcase_add_test(tc_core, test_add99);
  tcase_add_test(tc_core, test_add100);
  tcase_add_test(tc_core, test_add101);
  tcase_add_test(tc_core, test_add102);
  tcase_add_test(tc_core, test_add103);
  tcase_add_test(tc_core, test_add104);
  tcase_add_test(tc_core, test_add105);
  tcase_add_test(tc_core, test_add106);
  tcase_add_test(tc_core, test_add107);
  tcase_add_test(tc_core, test_add108);
  tcase_add_test(tc_core, test_add109);
  tcase_add_test(tc_core, test_add110);
  tcase_add_test(tc_core, test_add111);
  tcase_add_test(tc_core, test_add112);
  tcase_add_test(tc_core, test_add113);
  tcase_add_test(tc_core, test_add114);
  tcase_add_test(tc_core, test_add115);
  tcase_add_test(tc_core, test_add116);
  tcase_add_test(tc_core, test_add117);
  tcase_add_test(tc_core, test_add118);
  tcase_add_test(tc_core, test_add119);
  tcase_add_test(tc_core, test_add120);
  tcase_add_test(tc_core, test_add121);
  tcase_add_test(tc_core, test_add122);
  tcase_add_test(tc_core, test_add123);
  tcase_add_test(tc_core, test_add124);
  tcase_add_test(tc_core, test_add125);
  tcase_add_test(tc_core, test_add126);
  tcase_add_test(tc_core, test_add127);
  tcase_add_test(tc_core, test_add128);
  tcase_add_test(tc_core, test_add129);
  tcase_add_test(tc_core, test_add130);
  tcase_add_test(tc_core, test_add131);
  tcase_add_test(tc_core, test_add132);
  tcase_add_test(tc_core, test_add133);
  tcase_add_test(tc_core, test_add134);
  tcase_add_test(tc_core, test_add135);
  tcase_add_test(tc_core, test_add136);
  tcase_add_test(tc_core, test_add137);
  tcase_add_test(tc_core, test_add138);
  tcase_add_test(tc_core, test_add139);
  tcase_add_test(tc_core, test_add140);
  tcase_add_test(tc_core, test_add141);
  tcase_add_test(tc_core, test_add142);
  tcase_add_test(tc_core, test_add143);
  tcase_add_test(tc_core, test_add144);
  tcase_add_test(tc_core, test_add145);
  tcase_add_test(tc_core, test_add146);
  tcase_add_test(tc_core, test_add147);
  tcase_add_test(tc_core, test_add148);
  tcase_add_test(tc_core, test_add149);
  tcase_add_test(tc_core, test_add150);
  tcase_add_test(tc_core, test_add151);
  tcase_add_test(tc_core, test_add152);
  tcase_add_test(tc_core, test_add153);
  tcase_add_test(tc_core, test_add154);
  tcase_add_test(tc_core, test_add155);
  tcase_add_test(tc_core, test_add156);
  tcase_add_test(tc_core, test_add157);
  tcase_add_test(tc_core, test_add158);
  tcase_add_test(tc_core, test_add159);
  tcase_add_test(tc_core, test_add160);
  tcase_add_test(tc_core, test_add161);
  tcase_add_test(tc_core, test_add162);
  tcase_add_test(tc_core, test_add163);
  tcase_add_test(tc_core, test_add164);
  tcase_add_test(tc_core, test_add165);
  tcase_add_test(tc_core, test_add166);
  tcase_add_test(tc_core, test_add167);
  tcase_add_test(tc_core, test_add168);
  tcase_add_test(tc_core, test_add169);
  tcase_add_test(tc_core, test_add170);
  tcase_add_test(tc_core, test_add171);
  tcase_add_test(tc_core, test_add172);
  tcase_add_test(tc_core, test_add173);
  tcase_add_test(tc_core, test_add174);
  tcase_add_test(tc_core, test_add175);
  tcase_add_test(tc_core, test_add176);
  tcase_add_test(tc_core, test_add177);
  tcase_add_test(tc_core, test_add178);
  tcase_add_test(tc_core, test_add179);
  tcase_add_test(tc_core, test_add180);
  tcase_add_test(tc_core, test_add181);
  tcase_add_test(tc_core, test_add182);
  tcase_add_test(tc_core, test_add183);
  tcase_add_test(tc_core, test_add184);
  tcase_add_test(tc_core, test_add185);
  tcase_add_test(tc_core, test_add186);
  tcase_add_test(tc_core, test_add187);
  tcase_add_test(tc_core, test_add188);
  tcase_add_test(tc_core, test_add189);
  tcase_add_test(tc_core, test_add190);
  tcase_add_test(tc_core, test_add191);
  tcase_add_test(tc_core, test_add192);
  tcase_add_test(tc_core, test_add193);
  tcase_add_test(tc_core, test_add194);
  tcase_add_test(tc_core, test_add195);
  tcase_add_test(tc_core, test_add196);
  tcase_add_test(tc_core, test_add197);
  tcase_add_test(tc_core, test_add198);
  tcase_add_test(tc_core, test_add199);
  tcase_add_test(tc_core, test_add200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *add_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("add0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_add_fail_manual1);
  tcase_add_test(tc_core, test_add_fail_manual2);
  tcase_add_test(tc_core, test_add_fail_manual3);
  tcase_add_test(tc_core, test_add_fail_manual4);
  tcase_add_test(tc_core, test_add_fail_manual5);
  tcase_add_test(tc_core, test_add_fail_manual6);
  tcase_add_test(tc_core, test_add_fail_manual7);
  tcase_add_test(tc_core, test_add_fail_manual8);
  tcase_add_test(tc_core, test_add_fail_manual9);
  tcase_add_test(tc_core, test_add_fail_manual10);
  tcase_add_test(tc_core, test_add_fail_manual11);
  tcase_add_test(tc_core, test_add_fail_manual12);
  tcase_add_test(tc_core, test_add_fail_manual13);
  tcase_add_test(tc_core, test_add_fail_manual14);
  tcase_add_test(tc_core, test_add_fail_manual15);
  tcase_add_test(tc_core, test_add_fail_manual16);
  tcase_add_test(tc_core, test_add_fail_manual17);

  tcase_add_test(tc_core, test_add_manual1);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_add(my_decimal decimal1, my_decimal decimal2, my_decimal check) {
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

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
  printf("---------------------------------\n\n\n\n");
#endif

  ck_assert_int_eq(my_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_add_fail(my_decimal decimal1, my_decimal decimal2, int check) {
  my_decimal result;
  int code = my_add(decimal1, decimal2, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  my_print_decimal_bits(decimal1);
  my_print_decimal_string(decimal1);
  my_print_decimal_bits(decimal2);
  my_print_decimal_string(decimal2);
  printf("Check: %d\n", check);
  printf("Result: %d\n", code);
  printf("---------------------------------\n\n\n\n");
#endif

  ck_assert_int_eq(code, check);
}
