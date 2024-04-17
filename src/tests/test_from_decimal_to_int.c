#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */
START_TEST(test_from_decimal_to_int_fail_manual1) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = my_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_int_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual9) {
  // Просто все единицы
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_decimal_to_int_ok1) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok2) {
  // -792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok3) {
  // 79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok4) {
  // -79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok5) {
  // 7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok6) {
  // -7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok7) {
  // 792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok8) {
  // -792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok9) {
  // 79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok10) {
  // -79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok11) {
  // 7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok12) {
  // -7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok13) {
  // 792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok14) {
  // -792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok15) {
  // 79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok16) {
  // -79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok17) {
  // 7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok18) {
  // -7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok19) {
  // 792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok20) {
  // -792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok21) {
  // 79228162.514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok22) {
  // -79228162.514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok23) {
  // 7922816.2514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok24) {
  // -7922816.2514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok25) {
  // 792281.62514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok26) {
  // -792281.62514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok27) {
  // 79228.162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok28) {
  // -79228.162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok29) {
  // 7922.8162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok30) {
  // -7922.8162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok31) {
  // 792.28162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok32) {
  // -792.28162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok33) {
  // 79.228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok34) {
  // -79.228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok35) {
  // 7.9228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok36) {
  // -7.9228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok37) {
  // 528187750.09509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok38) {
  // -528187750.09509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok39) {
  // 5.2818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok40) {
  // -5.2818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok41) {
  // 528187750.09509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok42) {
  // -528187750.09509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok43) {
  // 5.2818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok44) {
  // -5.2818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok45) {
  // 528187749.97211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok46) {
  // -528187749.97211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok47) {
  // 5.2818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok48) {
  // -5.2818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok49) {
  // 528187749.97211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok50) {
  // -528187749.97211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok51) {
  // 5.2818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok52) {
  // -5.2818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok53) {
  // 122978293.82473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok54) {
  // -122978293.82473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok55) {
  // 1.2297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok56) {
  // -1.2297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok57) {
  // 122978293.79609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok58) {
  // -122978293.79609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok59) {
  // 1.2297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok60) {
  // -1.2297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok61) {
  // 286331153.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok62) {
  // -286331153.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok63) {
  // 286331.1530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok64) {
  // -286331.1530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok65) {
  // 2.863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok66) {
  // -2.863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok67) {
  // 264093875.04754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok68) {
  // -264093875.04754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok69) {
  // 2.6409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok70) {
  // -2.6409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok71) {
  // 264093875.04754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok72) {
  // -264093875.04754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok73) {
  // 2.6409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok74) {
  // -2.6409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok75) {
  // 264093874.98605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok76) {
  // -264093874.98605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok77) {
  // 2.6409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok78) {
  // -2.6409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok79) {
  // 264093874.98605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok80) {
  // -264093874.98605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok81) {
  // 2.6409387498605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok82) {
  // -2.6409387498605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok83) {
  // 6148914.691236517205
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok84) {
  // -6148914.691236517205
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok85) {
  // 6.148914691236517205
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok86) {
  // -6.148914691236517205
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok87) {
  // 6148914.689804861440
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok88) {
  // -6148914.689804861440
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok89) {
  // 6.148914689804861440
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok90) {
  // -6.148914689804861440
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok91) {
  // 1431655765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok92) {
  // -1431655765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok93) {
  // 143165576.5
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok94) {
  // -143165576.5
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok95) {
  // 143165.5765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok96) {
  // -143165.5765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok97) {
  // 1.431655765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok98) {
  // -1.431655765
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok99) {
  // 184467440.78004518913
  my_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok100) {
  // -184467440.78004518913
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok101) {
  // 1.8446744078004518913
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok102) {
  // -1.8446744078004518913
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok103) {
  // 18446744.078004518912
  my_decimal decimal = {{0x0, 0x1, 0x1, 0xC0000}};
  int check = 18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok104) {
  // -18446744.078004518912
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x800C0000}};
  int check = -18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok105) {
  // 1.8446744078004518912
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok106) {
  // -1.8446744078004518912
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok107) {
  // 1844674.4073709551617
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xD0000}};
  int check = 1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok108) {
  // -1844674.4073709551617
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800D0000}};
  int check = -1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok109) {
  // 1.8446744073709551617
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok110) {
  // -1.8446744073709551617
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok111) {
  // 184467.44073709551616
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xE0000}};
  int check = 184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok112) {
  // -184467.44073709551616
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800E0000}};
  int check = -184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok113) {
  // 1.8446744073709551616
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok114) {
  // -1.8446744073709551616
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok115) {
  // 429496729.7
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok116) {
  // -429496729.7
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok117) {
  // 42949672.97
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok118) {
  // -42949672.97
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok119) {
  // 429496.7297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  int check = 429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok120) {
  // -429496.7297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  int check = -429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok121) {
  // 4.294967297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok122) {
  // -4.294967297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok123) {
  // 42.94967297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok124) {
  // -42.94967297
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok125) {
  // 429496729.6
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok126) {
  // -429496729.6
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok127) {
  // 42949672.96
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok128) {
  // -42949672.96
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok129) {
  // 4294967.296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  int check = 4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok130) {
  // -4294967.296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  int check = -4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok131) {
  // 4.294967296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok132) {
  // -4.294967296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok133) {
  // 42.94967296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok134) {
  // -42.94967296
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok135) {
  // 1
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok136) {
  // -1
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok137) {
  // 0.1
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok138) {
  // -0.1
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok139) {
  // 0.0000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok140) {
  // -0.0000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok141) {
  // 0.00000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok142) {
  // -0.00000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok143) {
  // 0.000000000000000000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok144) {
  // -0.000000000000000000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok145) {
  // 0.0000000000000000000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok146) {
  // -0.0000000000000000000000000001
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok147) {
  // 396140812.66355540835774234624
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x140000}};
  int check = 396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok148) {
  // -396140812.66355540835774234624
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80140000}};
  int check = -396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok149) {
  // 3.9614081266355540835774234624
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok150) {
  // -3.9614081266355540835774234624
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok151) {
  // 39614081.266355540833626750976
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x150000}};
  int check = 39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok152) {
  // -39614081.266355540833626750976
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80150000}};
  int check = -39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok153) {
  // 3.9614081266355540833626750976
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok154) {
  // -3.9614081266355540833626750976
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok155) {
  // 3961408.1257132168798919458816
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x160000}};
  int check = 3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok156) {
  // -3961408.1257132168798919458816
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80160000}};
  int check = -3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok157) {
  // 3.9614081257132168798919458816
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok158) {
  // -3.9614081257132168798919458816
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok159) {
  // 396140.81257132168796771975168
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x170000}};
  int check = 396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok160) {
  // -396140.81257132168796771975168
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80170000}};
  int check = -396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok161) {
  // 3.9614081257132168796771975168
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok162) {
  // -3.9614081257132168796771975168
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok163) {
  // 922337203.9002259456
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0xA0000}};
  int check = 922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok164) {
  // -922337203.9002259456
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x800A0000}};
  int check = -922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok165) {
  // 9.223372039002259456
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok166) {
  // -9.223372039002259456
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok167) {
  // 92233720.36854775808
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0xB0000}};
  int check = 92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok168) {
  // -92233720.36854775808
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x800B0000}};
  int check = -92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok169) {
  // 9.223372036854775808
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok170) {
  // -9.223372036854775808
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok171) {
  // -2147483648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok172) {
  // 214748364.8
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  int check = 214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok173) {
  // -214748364.8
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  int check = -214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok174) {
  // 21474836.48
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok175) {
  // -21474836.48
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok176) {
  // 214748.3648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  int check = 214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok177) {
  // -214748.3648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  int check = -214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok178) {
  // 21.47483648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  int check = 21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok179) {
  // -21.47483648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  int check = -21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok180) {
  // 2.147483648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok181) {
  // -2.147483648
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok182) {
  // 1560647.67562212695305426944
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  int check = 1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok183) {
  // -1560647.67562212695305426944
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  int check = -1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok184) {
  // 1.56064767562212695305426944
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok185) {
  // -1.56064767562212695305426944
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok186) {
  // 15606476.7562212695296966656
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x130000}};
  int check = 15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok187) {
  // -15606476.7562212695296966656
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80130000}};
  int check = -15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok188) {
  // 1.56064767562212695296966656
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok189) {
  // -1.56064767562212695296966656
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok190) {
  // 156064.767525876035030685696
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x150000}};
  int check = 156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok191) {
  // -156064.767525876035030685696
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80150000}};
  int check = -156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok192) {
  // 1.56064767525876035030685696
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok193) {
  // -1.56064767525876035030685696
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok194) {
  // 15606.4767525876035022225408
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x160000}};
  int check = 15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok195) {
  // -15606.4767525876035022225408
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80160000}};
  int check = -15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok196) {
  // 1.56064767525876035022225408
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok197) {
  // -1.56064767525876035022225408
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok198) {
  // 363366602.83201536
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  int check = 363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok199) {
  // -363366602.83201536
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  int check = -363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok200) {
  // 3.6336660283201536
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

Suite *from_decimal_to_int_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_int_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok52);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok53);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok54);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok55);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok56);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok57);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok58);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok59);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok60);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok61);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok62);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok63);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok64);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok65);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok66);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok67);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok68);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok69);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok70);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok71);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok72);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok73);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok74);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok75);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok76);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok77);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok78);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok79);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok80);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok81);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok82);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok83);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok84);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok85);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok86);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok87);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok88);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok89);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok90);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok91);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok92);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok93);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok94);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok95);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok96);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok97);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok98);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok99);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok100);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok101);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok102);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok103);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok104);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok105);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok106);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok107);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok108);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok109);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok110);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok111);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok112);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok113);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok114);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok115);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok116);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok117);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok118);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok119);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok120);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok121);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok122);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok123);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok124);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok125);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok126);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok127);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok128);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok129);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok130);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok131);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok132);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok133);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok134);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok135);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok136);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok137);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok138);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok139);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok140);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok141);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok142);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok143);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok144);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok145);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok146);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok147);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok148);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok149);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok150);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok151);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok152);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok153);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok154);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok155);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok156);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok157);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok158);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok159);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok160);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok161);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok162);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok163);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok164);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok165);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok166);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok167);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok168);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok169);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok170);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok171);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok172);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok173);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok174);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok175);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok176);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok177);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok178);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok179);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok180);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok181);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok182);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok183);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok184);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok185);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok186);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok187);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok188);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok189);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok190);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok191);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok192);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok193);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok194);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok195);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok196);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok197);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok198);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok199);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_int_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int0");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual1);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual2);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual3);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual4);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual5);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual6);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual7);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual8);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_decimal_to_int(my_decimal decimal, int check) {
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}

void test_from_decimal_to_int_fail(my_decimal decimal) {
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
