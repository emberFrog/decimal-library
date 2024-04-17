#include <stdio.h>
#include <stdlib.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_mod_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_mod(decimal1, decimal2, NULL);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_mod_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal1 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal1 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual10) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual11) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual12) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal2 = {{0, 0, 0, 0x1D0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual13) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C0001}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual14) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x1C8000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual15) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x11C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual16) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal2 = {{-1, 0, 0, 0x401C0000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

START_TEST(test_mod_fail_manual17) {
  // Просто все единицы
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на все типы данных (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_mod_manual1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000012345
  s21_decimal decimal2 = {{0x3039, 0x0, 0x0, 0xA0000}};
  // 0.0000002880
  s21_decimal decimal_check = {{0xB40, 0x0, 0x0, 0xA0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000003
  s21_decimal decimal2 = {{0x3, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};
  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000003456
  s21_decimal decimal2 = {{0xD80, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000002304
  s21_decimal decimal_check = {{0x900, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual4) {
  // 0.0000000000000000000000034567
  s21_decimal decimal1 = {{0x8707, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000000001234
  s21_decimal decimal2 = {{0x4D2, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000000000015
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual5) {
  // -0.1111111111111111111111111111
  s21_decimal decimal1 = {{0x571C71C7, 0x6E7AAEE, 0x39716EE, 0x801C0000}};
  // -0.0100000002000000030000000004
  s21_decimal decimal2 = {{0x2EEBAC04, 0xF8897A41, 0x52B7D2, 0x801C0000}};
  // -0.0011111089111110781111111067
  s21_decimal decimal_check = {{0x52FC0D9B, 0x58FF6A21, 0x930DD, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual6) {
  // -0.1111111111111111111111111111
  s21_decimal decimal1 = {{0x571C71C7, 0x6E7AAEE, 0x39716EE, 0x801C0000}};
  // 0.01
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x20000}};
  // -0.0011111111111111111111111111
  s21_decimal decimal_check = {{0x8B1C71C7, 0x8A4F1DDE, 0x930DE, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 100.00000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1A0000}};
  // 27.07718374857356624064560497
  s21_decimal decimal_check = {{0x30A3D71, 0x39973179, 0x8BFC5AB, 0x1A0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual100) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.1
  s21_decimal decimal2 = {{0xB, 0x0, 0x0, 0x10000}};
  // 0.7
  s21_decimal decimal_check = {{0x7, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual101) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.01
  s21_decimal decimal2 = {{0x65, 0x0, 0x0, 0x20000}};
  // 0.33
  s21_decimal decimal_check = {{0x21, 0x0, 0x0, 0x20000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual102) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 0.381
  s21_decimal decimal_check = {{0x17D, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual103) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0001
  s21_decimal decimal2 = {{0x2711, 0x0, 0x0, 0x40000}};
  // 0.2158
  s21_decimal decimal_check = {{0x86E, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual104) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00001
  s21_decimal decimal2 = {{0x186A1, 0x0, 0x0, 0x50000}};
  // 0.75654
  s21_decimal decimal_check = {{0x12786, 0x0, 0x0, 0x50000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual105) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000001
  s21_decimal decimal2 = {{0xF4241, 0x0, 0x0, 0x60000}};
  // 0.036999
  s21_decimal decimal_check = {{0x9087, 0x0, 0x0, 0x60000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual106) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000001
  s21_decimal decimal2 = {{0x989681, 0x0, 0x0, 0x70000}};
  // 0.5033134
  s21_decimal decimal_check = {{0x4CCCAE, 0x0, 0x0, 0x70000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual107) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000001
  s21_decimal decimal2 = {{0x5F5E101, 0x0, 0x0, 0x80000}};
  // 0.05032747
  s21_decimal decimal_check = {{0x4CCB2B, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual108) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000001
  s21_decimal decimal2 = {{0x3B9ACA01, 0x0, 0x0, 0x90000}};
  // 0.705032709
  s21_decimal decimal_check = {{0x2A05F205, 0x0, 0x0, 0x90000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual109) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000001
  s21_decimal decimal2 = {{0x540BE401, 0x2, 0x0, 0xA0000}};
  // 0.5705032705
  s21_decimal decimal_check = {{0x540BE401, 0x1, 0x0, 0xA0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual110) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000001
  s21_decimal decimal2 = {{0x4876E801, 0x17, 0x0, 0xB0000}};
  // 0.95705032705
  s21_decimal decimal_check = {{0x4876E801, 0x16, 0x0, 0xB0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual111) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000001
  s21_decimal decimal2 = {{0xD4A51001, 0xE8, 0x0, 0xC0000}};
  // 0.995705032705
  s21_decimal decimal_check = {{0xD4A51001, 0xE7, 0x0, 0xC0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual112) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000001
  s21_decimal decimal2 = {{0x4E72A001, 0x918, 0x0, 0xD0000}};
  // 0.9995705032705
  s21_decimal decimal_check = {{0x4E72A001, 0x917, 0x0, 0xD0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual113) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000000001
  s21_decimal decimal2 = {{0x107A4001, 0x5AF3, 0x0, 0xE0000}};
  // 0.99995705032705
  s21_decimal decimal_check = {{0x107A4001, 0x5AF2, 0x0, 0xE0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual114) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000000001
  s21_decimal decimal2 = {{0xA4C68001, 0x38D7E, 0x0, 0xF0000}};
  // 0.999995705032705
  s21_decimal decimal_check = {{0xA4C68001, 0x38D7D, 0x0, 0xF0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual115) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000000001
  s21_decimal decimal2 = {{0x6FC10001, 0x2386F2, 0x0, 0x100000}};
  // 0.9999995705032705
  s21_decimal decimal_check = {{0x6FC10001, 0x2386F1, 0x0, 0x100000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual116) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000000000001
  s21_decimal decimal2 = {{0x5D8A0001, 0x1634578, 0x0, 0x110000}};
  // 0.99999995705032705
  s21_decimal decimal_check = {{0x5D8A0001, 0x1634577, 0x0, 0x110000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual117) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000000000001
  s21_decimal decimal2 = {{0xA7640001, 0xDE0B6B3, 0x0, 0x120000}};
  // 0.999999995705032705
  s21_decimal decimal_check = {{0xA7640001, 0xDE0B6B2, 0x0, 0x120000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual118) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000000000001
  s21_decimal decimal2 = {{0x89E80001, 0x8AC72304, 0x0, 0x130000}};
  // 0.9999999995705032705
  s21_decimal decimal_check = {{0x89E80001, 0x8AC72303, 0x0, 0x130000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual119) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000000000000001
  s21_decimal decimal2 = {{0x63100001, 0x6BC75E2D, 0x5, 0x140000}};
  // 0.99999999995705032705
  s21_decimal decimal_check = {{0x63100001, 0x6BC75E2C, 0x5, 0x140000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual120) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000000000000001
  s21_decimal decimal2 = {{0xDEA00001, 0x35C9ADC5, 0x36, 0x150000}};
  // 0.999999999995705032705
  s21_decimal decimal_check = {{0xDEA00001, 0x35C9ADC4, 0x36, 0x150000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual121) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000000000000001
  s21_decimal decimal2 = {{0xB2400001, 0x19E0C9BA, 0x21E, 0x160000}};
  // 0.9999999999995705032705
  s21_decimal decimal_check = {{0xB2400001, 0x19E0C9B9, 0x21E, 0x160000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual122) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000000000000000001
  s21_decimal decimal2 = {{0xF6800001, 0x2C7E14A, 0x152D, 0x170000}};
  // 0.99999999999995705032705
  s21_decimal decimal_check = {{0xF6800001, 0x2C7E149, 0x152D, 0x170000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual123) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000000000000000001
  s21_decimal decimal2 = {{0xA1000001, 0x1BCECCED, 0xD3C2, 0x180000}};
  // 0.999999999999995705032705
  s21_decimal decimal_check = {{0xA1000001, 0x1BCECCEC, 0xD3C2, 0x180000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual124) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000000000000000001
  s21_decimal decimal2 = {{0x4A000001, 0x16140148, 0x84595, 0x190000}};
  // 0.9999999999999995705032705
  s21_decimal decimal_check = {{0x4A000001, 0x16140147, 0x84595, 0x190000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual125) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.00000000000000000000000001
  s21_decimal decimal2 = {{0xE4000001, 0xDCC80CD2, 0x52B7D2, 0x1A0000}};
  // 0.99999999999999995705032705
  s21_decimal decimal_check = {{0xE4000001, 0xDCC80CD1, 0x52B7D2, 0x1A0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual126) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.000000000000000000000000001
  s21_decimal decimal2 = {{0xE8000001, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  // 0.999999999999999995705032705
  s21_decimal decimal_check = {{0xE8000001, 0x9FD0803B, 0x33B2E3C, 0x1B0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual127) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 0.9999999999999999995705032705
  s21_decimal decimal_check = {{0x10000001, 0x3E250260, 0x204FCE5E, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod_manual200) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.1
  s21_decimal decimal2 = {{0xB, 0x0, 0x0, 0x10000}};
  // 0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual201) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.01
  s21_decimal decimal2 = {{0x65, 0x0, 0x0, 0x20000}};
  // 0.83
  s21_decimal decimal_check = {{0x53, 0x0, 0x0, 0x20000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual202) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 0.091
  s21_decimal decimal_check = {{0x5B, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual203) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0001
  s21_decimal decimal2 = {{0x2711, 0x0, 0x0, 0x40000}};
  // 0.3441
  s21_decimal decimal_check = {{0xD71, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual204) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.00001
  s21_decimal decimal2 = {{0x186A1, 0x0, 0x0, 0x50000}};
  // 0.91908
  s21_decimal decimal_check = {{0x16704, 0x0, 0x0, 0x50000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual205) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.000001
  s21_decimal decimal2 = {{0xF4241, 0x0, 0x0, 0x60000}};
  // 0.462158
  s21_decimal decimal_check = {{0x70D4E, 0x0, 0x0, 0x60000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual206) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000001
  s21_decimal decimal2 = {{0x989681, 0x0, 0x0, 0x70000}};
  // 0.3894531
  s21_decimal decimal_check = {{0x3B6D03, 0x0, 0x0, 0x70000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual207) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.00000001
  s21_decimal decimal2 = {{0x5F5E101, 0x0, 0x0, 0x80000}};
  // 0.83253403
  s21_decimal decimal_check = {{0x4F6589B, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual208) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.000000001
  s21_decimal decimal2 = {{0x3B9ACA01, 0x0, 0x0, 0x90000}};
  // 0.492224824
  s21_decimal decimal_check = {{0x1D56C138, 0x0, 0x0, 0x90000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual209) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000001
  s21_decimal decimal2 = {{0x540BE401, 0x2, 0x0, 0xA0000}};
  // 0.7090201800
  s21_decimal decimal_check = {{0xA69BE4C8, 0x1, 0x0, 0xA0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual210) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.00000000001
  s21_decimal decimal2 = {{0x4876E801, 0x17, 0x0, 0xB0000}};
  // 0.31590770225
  s21_decimal decimal_check = {{0x5AF4E631, 0x7, 0x0, 0xB0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual211) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.000000000001
  s21_decimal decimal2 = {{0xD4A51001, 0xE8, 0x0, 0xC0000}};
  // 0.568970234775
  s21_decimal decimal_check = {{0x7944CB97, 0x84, 0x0, 0xC0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual212) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000001
  s21_decimal decimal2 = {{0x4E72A001, 0x918, 0x0, 0xD0000}};
  // 0.5222707475307
  s21_decimal decimal_check = {{0x19FB36B, 0x4C0, 0x0, 0xD0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual213) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.00000000000001
  s21_decimal decimal2 = {{0x107A4001, 0x5AF3, 0x0, 0xE0000}};
  // 0.54688081192301
  s21_decimal decimal_check = {{0xFA7256D, 0x31BD, 0x0, 0xE0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual214) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.000000000000001
  s21_decimal decimal2 = {{0xA4C68001, 0x38D7E, 0x0, 0xF0000}};
  // 0.741634618563930
  s21_decimal decimal_check = {{0x43FE1D5A, 0x2A283, 0x0, 0xF0000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual215) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000001
  s21_decimal decimal2 = {{0x6FC10001, 0x2386F2, 0x0, 0x100000}};
  // 0.5670329272301092
  s21_decimal decimal_check = {{0x6A08F624, 0x142522, 0x0, 0x100000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual216) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.00000000000000001
  s21_decimal decimal2 = {{0x5D8A0001, 0x1634578, 0x0, 0x110000}};
  // 0.35663198737674808
  s21_decimal decimal_check = {{0x84503238, 0x7EB37D, 0x0, 0x110000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual217) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.000000000000000001
  s21_decimal decimal2 = {{0xA7640001, 0xDE0B6B3, 0x0, 0x120000}};
  // 0.735662485684212180
  s21_decimal decimal_check = {{0xDC9D1D4, 0xA359922, 0x0, 0x120000}};

  test_mod(decimal1, decimal2, decimal_check);
}
START_TEST(test_mod_manual218) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000001
  s21_decimal decimal2 = {{0x89E80001, 0x8AC72304, 0x0, 0x130000}};
  // 0.5735662414378865917
  s21_decimal decimal_check = {{0xB89C94FD, 0x4F992A93, 0x0, 0x130000}};

  test_mod(decimal1, decimal2, decimal_check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests all data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_mod1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 39614081257132168794624491519
  s21_decimal decimal_check = {{0x7FFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168794624491519
  s21_decimal decimal_check = {{0x7FFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 39614081257132168796771975167
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168796771975167
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 2.9614081257132168796771975168
  s21_decimal decimal_check = {{0xF0000000, 0xC1DAFD9E, 0x5FB031A1, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 2.9614081257132168796771975168
  s21_decimal decimal_check = {{0xF0000000, 0xC1DAFD9E, 0x5FB031A1, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 18446744069414584320
  s21_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 18446744069414584320
  s21_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 2147483647
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 2147483647
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 1073741823
  s21_decimal decimal_check = {{0x3FFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 1073741823
  s21_decimal decimal_check = {{0x3FFFFFFF, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.4081257132168796771977148000
  s21_decimal decimal_check = {{0x701E3660, 0x755E302F, 0xD2FEFD0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 0.4081257132168796771977148000
  s21_decimal decimal_check = {{0x701E3660, 0x755E302F, 0xD2FEFD0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.9614081257132168796771975169
  s21_decimal decimal_check = {{0xD0000001, 0x4590F8DC, 0x1F1094E5, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 0.9614081257132168796771975169
  s21_decimal decimal_check = {{0xD0000001, 0x4590F8DC, 0x1F1094E5, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 0.9228162514264337593543950342
  s21_decimal decimal_check = {{0x90000006, 0x4CFCEF58, 0x1DD15B6C, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 0.9228162514264337593543950342
  s21_decimal decimal_check = {{0x90000006, 0x4CFCEF58, 0x1DD15B6C, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 8.397653123811305200538004140
  s21_decimal decimal_check = {{0x42AAAAAC, 0x7E22E3C, 0x1B226038, 0x1B0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 8.397653123811305200538004140
  s21_decimal decimal_check = {{0x42AAAAAC, 0x7E22E3C, 0x1B226038, 0x1B0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // 0.000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 0.000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // 0.015
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // 0.015
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 28232649134943.668301643481088
  s21_decimal decimal_check = {{0x5B398000, 0x5B398000, 0x5B398000, 0xF0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 28232649134943.668301643481088
  s21_decimal decimal_check = {{0x5B398000, 0x5B398000, 0x5B398000, 0xF0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 41.94967296
  s21_decimal decimal_check = {{0xFA0A1F00, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 41.94967296
  s21_decimal decimal_check = {{0xFA0A1F00, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 214747.3648
  s21_decimal decimal_check = {{0x7FFFD8F0, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 214747.3648
  s21_decimal decimal_check = {{0x7FFFD8F0, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 0.00000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 0.00000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 0.7290
  s21_decimal decimal_check = {{0x1C7A, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod62) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 0.7290
  s21_decimal decimal_check = {{0x1C7A, 0x0, 0x0, 0x40000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 0.000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x90000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod64) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 0.000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x90000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 7044.120
  s21_decimal decimal_check = {{0x6B7C18, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod66) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 7044.120
  s21_decimal decimal_check = {{0x6B7C18, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 7.000
  s21_decimal decimal_check = {{0x1B58, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod68) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 7.000
  s21_decimal decimal_check = {{0x1B58, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 0.091
  s21_decimal decimal_check = {{0x5B, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod70) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 0.091
  s21_decimal decimal_check = {{0x5B, 0x0, 0x0, 0x30000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod72) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod74) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod76) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod78) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3359055301292796708334.2402749
  s21_decimal decimal2 = {{0x43114BD, 0x948E9182, 0x6C897447, 0x70000}};
  // 2834584564307424183811.2473691
  s21_decimal decimal_check = {{0x9376825B, 0x5BA570D3, 0x5B97224B, 0x70000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod80) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3359055301292796708334.2402749
  s21_decimal decimal2 = {{0x43114BD, 0x948E9182, 0x6C897447, 0x80070000}};
  // 2834584564307424183811.2473691
  s21_decimal decimal_check = {{0x9376825B, 0x5BA570D3, 0x5B97224B, 0x70000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -29293803674175591779113420402
  s21_decimal decimal2 = {{0x85B0C672, 0x31FBFF52, 0x5EA74437, 0x80000000}};
  // 20640555165913154035317109531
  s21_decimal decimal_check = {{0xF49E731B, 0x9C08015A, 0x42B17791, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod82) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 29293803674175591779113420402
  s21_decimal decimal2 = {{0x85B0C672, 0x31FBFF52, 0x5EA74437, 0x0}};
  // 20640555165913154035317109531
  s21_decimal decimal_check = {{0xF49E731B, 0x9C08015A, 0x42B17791, 0x0}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 25817.443351246080434413985401
  s21_decimal decimal2 = {{0x29675E79, 0x78DCFEE6, 0x536BB048, 0x180000}};
  // 24274.269098408429436559324273
  s21_decimal decimal_check = {{0xAE567471, 0x997FEE25, 0x4E6F346C, 0x180000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod84) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -25817.443351246080434413985401
  s21_decimal decimal2 = {{0x29675E79, 0x78DCFEE6, 0x536BB048, 0x80180000}};
  // 24274.269098408429436559324273
  s21_decimal decimal_check = {{0xAE567471, 0x997FEE25, 0x4E6F346C, 0x180000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -39614081257132168794624491519
  s21_decimal decimal_check = {
      {0x7FFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168794624491519
  s21_decimal decimal_check = {
      {0x7FFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -39614081257132168796771975167
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168796771975167
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -2.9614081257132168796771975168
  s21_decimal decimal_check = {
      {0xF0000000, 0xC1DAFD9E, 0x5FB031A1, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -2.9614081257132168796771975168
  s21_decimal decimal_check = {
      {0xF0000000, 0xC1DAFD9E, 0x5FB031A1, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod101) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -18446744069414584320
  s21_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod102) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -18446744069414584320
  s21_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod103) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod104) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -4294967295
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod105) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -2147483647
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod106) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -2147483647
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod107) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -1073741823
  s21_decimal decimal_check = {{0x3FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod108) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -1073741823
  s21_decimal decimal_check = {{0x3FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod109) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod110) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod111) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod112) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -0.4081257132168796771977148000
  s21_decimal decimal_check = {{0x701E3660, 0x755E302F, 0xD2FEFD0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod114) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -0.4081257132168796771977148000
  s21_decimal decimal_check = {{0x701E3660, 0x755E302F, 0xD2FEFD0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -0.9614081257132168796771975169
  s21_decimal decimal_check = {
      {0xD0000001, 0x4590F8DC, 0x1F1094E5, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -0.9614081257132168796771975169
  s21_decimal decimal_check = {
      {0xD0000001, 0x4590F8DC, 0x1F1094E5, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod120) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod122) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod124) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -0.9228162514264337593543950342
  s21_decimal decimal_check = {
      {0x90000006, 0x4CFCEF58, 0x1DD15B6C, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod126) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -0.9228162514264337593543950342
  s21_decimal decimal_check = {
      {0x90000006, 0x4CFCEF58, 0x1DD15B6C, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod128) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -8.397653123811305200538004140
  s21_decimal decimal_check = {{0x42AAAAAC, 0x7E22E3C, 0x1B226038, 0x801B0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod130) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -8.397653123811305200538004140
  s21_decimal decimal_check = {{0x42AAAAAC, 0x7E22E3C, 0x1B226038, 0x801B0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod132) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // -0.000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod134) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -0.000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // -0.015
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod136) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // -0.015
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -28232649134943.668301643481088
  s21_decimal decimal_check = {
      {0x5B398000, 0x5B398000, 0x5B398000, 0x800F0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod138) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -28232649134943.668301643481088
  s21_decimal decimal_check = {
      {0x5B398000, 0x5B398000, 0x5B398000, 0x800F0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -41.94967296
  s21_decimal decimal_check = {{0xFA0A1F00, 0x0, 0x0, 0x80080000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod140) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -41.94967296
  s21_decimal decimal_check = {{0xFA0A1F00, 0x0, 0x0, 0x80080000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -214747.3648
  s21_decimal decimal_check = {{0x7FFFD8F0, 0x0, 0x0, 0x80040000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod142) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -214747.3648
  s21_decimal decimal_check = {{0x7FFFD8F0, 0x0, 0x0, 0x80040000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -0.00000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80080000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod144) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -0.00000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80080000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -0.7290
  s21_decimal decimal_check = {{0x1C7A, 0x0, 0x0, 0x80040000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod146) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -0.7290
  s21_decimal decimal_check = {{0x1C7A, 0x0, 0x0, 0x80040000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -0.000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80090000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod148) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -0.000000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80090000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -7044.120
  s21_decimal decimal_check = {{0x6B7C18, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod150) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -7044.120
  s21_decimal decimal_check = {{0x6B7C18, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -7.000
  s21_decimal decimal_check = {{0x1B58, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod152) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -7.000
  s21_decimal decimal_check = {{0x1B58, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -0.091
  s21_decimal decimal_check = {{0x5B, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod154) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -0.091
  s21_decimal decimal_check = {{0x5B, 0x0, 0x0, 0x80030000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod156) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod158) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod160) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod162) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_mod_fail(decimal1, decimal2, code_check);
}

START_TEST(test_mod163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3359055301292796708334.2402749
  s21_decimal decimal2 = {{0x43114BD, 0x948E9182, 0x6C897447, 0x70000}};
  // -2834584564307424183811.2473691
  s21_decimal decimal_check = {
      {0x9376825B, 0x5BA570D3, 0x5B97224B, 0x80070000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod164) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3359055301292796708334.2402749
  s21_decimal decimal2 = {{0x43114BD, 0x948E9182, 0x6C897447, 0x80070000}};
  // -2834584564307424183811.2473691
  s21_decimal decimal_check = {
      {0x9376825B, 0x5BA570D3, 0x5B97224B, 0x80070000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -29293803674175591779113420402
  s21_decimal decimal2 = {{0x85B0C672, 0x31FBFF52, 0x5EA74437, 0x80000000}};
  // -20640555165913154035317109531
  s21_decimal decimal_check = {
      {0xF49E731B, 0x9C08015A, 0x42B17791, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod166) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 29293803674175591779113420402
  s21_decimal decimal2 = {{0x85B0C672, 0x31FBFF52, 0x5EA74437, 0x0}};
  // -20640555165913154035317109531
  s21_decimal decimal_check = {
      {0xF49E731B, 0x9C08015A, 0x42B17791, 0x80000000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 25817.443351246080434413985401
  s21_decimal decimal2 = {{0x29675E79, 0x78DCFEE6, 0x536BB048, 0x180000}};
  // -24274.269098408429436559324273
  s21_decimal decimal_check = {
      {0xAE567471, 0x997FEE25, 0x4E6F346C, 0x80180000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod168) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -25817.443351246080434413985401
  s21_decimal decimal2 = {{0x29675E79, 0x78DCFEE6, 0x536BB048, 0x80180000}};
  // -24274.269098408429436559324273
  s21_decimal decimal_check = {
      {0xAE567471, 0x997FEE25, 0x4E6F346C, 0x80180000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod169) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod170) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod171) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod172) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod173) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod174) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod175) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod176) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod177) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod178) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod179) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod180) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod181) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 3.8614081257132168796771975168
  s21_decimal decimal_check = {{0x18000000, 0x602F7FC3, 0x7CC4D1C3, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod182) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 3.8614081257132168796771975168
  s21_decimal decimal_check = {{0x18000000, 0x602F7FC3, 0x7CC4D1C3, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod183) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 429496729.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod184) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 429496729.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod185) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod186) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod187) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 2576980377.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x5, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod188) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 2576980377.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x5, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod189) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 429496729.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod190) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 429496729.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod191) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 1825361100.5
  s21_decimal decimal_check = {{0x3FFFFFFD, 0x4, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod192) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 1825361100.5
  s21_decimal decimal_check = {{0x3FFFFFFD, 0x4, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod193) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 3.5
  s21_decimal decimal_check = {{0x23, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod194) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 3.5
  s21_decimal decimal_check = {{0x23, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod195) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod196) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod197) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.6408125713216879677197714000
  s21_decimal decimal_check = {{0xD8030250, 0x3BF7D56C, 0x35047BC5, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod198) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 1.6408125713216879677197714000
  s21_decimal decimal_check = {{0xD8030250, 0x3BF7D56C, 0x35047BC5, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod199) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.8961408125713216879677197516
  s21_decimal decimal_check = {{0x64CCCCCC, 0x2A04505E, 0x3D44825A, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

START_TEST(test_mod200) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 1.8961408125713216879677197516
  s21_decimal decimal_check = {{0x64CCCCCC, 0x2A04505E, 0x3D44825A, 0x1C0000}};

  test_mod(decimal1, decimal2, decimal_check);
}

Suite *mod_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("mod1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_mod1);
  tcase_add_test(tc_core, test_mod2);
  tcase_add_test(tc_core, test_mod3);
  tcase_add_test(tc_core, test_mod4);
  tcase_add_test(tc_core, test_mod5);
  tcase_add_test(tc_core, test_mod6);
  tcase_add_test(tc_core, test_mod7);
  tcase_add_test(tc_core, test_mod8);
  tcase_add_test(tc_core, test_mod9);
  tcase_add_test(tc_core, test_mod10);
  tcase_add_test(tc_core, test_mod11);
  tcase_add_test(tc_core, test_mod12);
  tcase_add_test(tc_core, test_mod13);
  tcase_add_test(tc_core, test_mod14);
  tcase_add_test(tc_core, test_mod15);
  tcase_add_test(tc_core, test_mod16);
  tcase_add_test(tc_core, test_mod17);
  tcase_add_test(tc_core, test_mod18);
  tcase_add_test(tc_core, test_mod19);
  tcase_add_test(tc_core, test_mod20);
  tcase_add_test(tc_core, test_mod21);
  tcase_add_test(tc_core, test_mod22);
  tcase_add_test(tc_core, test_mod23);
  tcase_add_test(tc_core, test_mod24);
  tcase_add_test(tc_core, test_mod25);
  tcase_add_test(tc_core, test_mod26);
  tcase_add_test(tc_core, test_mod27);
  tcase_add_test(tc_core, test_mod28);
  tcase_add_test(tc_core, test_mod29);
  tcase_add_test(tc_core, test_mod30);
  tcase_add_test(tc_core, test_mod31);
  tcase_add_test(tc_core, test_mod32);
  tcase_add_test(tc_core, test_mod35);
  tcase_add_test(tc_core, test_mod36);
  tcase_add_test(tc_core, test_mod37);
  tcase_add_test(tc_core, test_mod38);
  tcase_add_test(tc_core, test_mod39);
  tcase_add_test(tc_core, test_mod40);
  tcase_add_test(tc_core, test_mod41);
  tcase_add_test(tc_core, test_mod42);
  tcase_add_test(tc_core, test_mod43);
  tcase_add_test(tc_core, test_mod44);
  tcase_add_test(tc_core, test_mod45);
  tcase_add_test(tc_core, test_mod46);
  tcase_add_test(tc_core, test_mod47);
  tcase_add_test(tc_core, test_mod48);
  tcase_add_test(tc_core, test_mod49);
  tcase_add_test(tc_core, test_mod50);
  tcase_add_test(tc_core, test_mod51);
  tcase_add_test(tc_core, test_mod52);
  tcase_add_test(tc_core, test_mod53);
  tcase_add_test(tc_core, test_mod54);
  tcase_add_test(tc_core, test_mod55);
  tcase_add_test(tc_core, test_mod56);
  tcase_add_test(tc_core, test_mod57);
  tcase_add_test(tc_core, test_mod58);
  tcase_add_test(tc_core, test_mod59);
  tcase_add_test(tc_core, test_mod60);
  tcase_add_test(tc_core, test_mod61);
  tcase_add_test(tc_core, test_mod62);
  tcase_add_test(tc_core, test_mod63);
  tcase_add_test(tc_core, test_mod64);
  tcase_add_test(tc_core, test_mod65);
  tcase_add_test(tc_core, test_mod66);
  tcase_add_test(tc_core, test_mod67);
  tcase_add_test(tc_core, test_mod68);
  tcase_add_test(tc_core, test_mod69);
  tcase_add_test(tc_core, test_mod70);
  tcase_add_test(tc_core, test_mod71);
  tcase_add_test(tc_core, test_mod72);
  tcase_add_test(tc_core, test_mod73);
  tcase_add_test(tc_core, test_mod74);
  tcase_add_test(tc_core, test_mod75);
  tcase_add_test(tc_core, test_mod76);
  tcase_add_test(tc_core, test_mod77);
  tcase_add_test(tc_core, test_mod78);
  tcase_add_test(tc_core, test_mod79);
  tcase_add_test(tc_core, test_mod80);
  tcase_add_test(tc_core, test_mod81);
  tcase_add_test(tc_core, test_mod82);
  tcase_add_test(tc_core, test_mod83);
  tcase_add_test(tc_core, test_mod84);
  tcase_add_test(tc_core, test_mod85);
  tcase_add_test(tc_core, test_mod86);
  tcase_add_test(tc_core, test_mod87);
  tcase_add_test(tc_core, test_mod88);
  tcase_add_test(tc_core, test_mod89);
  tcase_add_test(tc_core, test_mod90);
  tcase_add_test(tc_core, test_mod91);
  tcase_add_test(tc_core, test_mod92);
  tcase_add_test(tc_core, test_mod93);
  tcase_add_test(tc_core, test_mod94);
  tcase_add_test(tc_core, test_mod95);
  tcase_add_test(tc_core, test_mod96);
  tcase_add_test(tc_core, test_mod97);
  tcase_add_test(tc_core, test_mod98);
  tcase_add_test(tc_core, test_mod99);
  tcase_add_test(tc_core, test_mod100);
  tcase_add_test(tc_core, test_mod101);
  tcase_add_test(tc_core, test_mod102);
  tcase_add_test(tc_core, test_mod103);
  tcase_add_test(tc_core, test_mod104);
  tcase_add_test(tc_core, test_mod105);
  tcase_add_test(tc_core, test_mod106);
  tcase_add_test(tc_core, test_mod107);
  tcase_add_test(tc_core, test_mod108);
  tcase_add_test(tc_core, test_mod109);
  tcase_add_test(tc_core, test_mod110);
  tcase_add_test(tc_core, test_mod111);
  tcase_add_test(tc_core, test_mod112);
  tcase_add_test(tc_core, test_mod113);
  tcase_add_test(tc_core, test_mod114);
  tcase_add_test(tc_core, test_mod115);
  tcase_add_test(tc_core, test_mod116);
  tcase_add_test(tc_core, test_mod119);
  tcase_add_test(tc_core, test_mod120);
  tcase_add_test(tc_core, test_mod121);
  tcase_add_test(tc_core, test_mod122);
  tcase_add_test(tc_core, test_mod123);
  tcase_add_test(tc_core, test_mod124);
  tcase_add_test(tc_core, test_mod125);
  tcase_add_test(tc_core, test_mod126);
  tcase_add_test(tc_core, test_mod127);
  tcase_add_test(tc_core, test_mod128);
  tcase_add_test(tc_core, test_mod129);
  tcase_add_test(tc_core, test_mod130);
  tcase_add_test(tc_core, test_mod131);
  tcase_add_test(tc_core, test_mod132);
  tcase_add_test(tc_core, test_mod133);
  tcase_add_test(tc_core, test_mod134);
  tcase_add_test(tc_core, test_mod135);
  tcase_add_test(tc_core, test_mod136);
  tcase_add_test(tc_core, test_mod137);
  tcase_add_test(tc_core, test_mod138);
  tcase_add_test(tc_core, test_mod139);
  tcase_add_test(tc_core, test_mod140);
  tcase_add_test(tc_core, test_mod141);
  tcase_add_test(tc_core, test_mod142);
  tcase_add_test(tc_core, test_mod143);
  tcase_add_test(tc_core, test_mod144);
  tcase_add_test(tc_core, test_mod145);
  tcase_add_test(tc_core, test_mod146);
  tcase_add_test(tc_core, test_mod147);
  tcase_add_test(tc_core, test_mod148);
  tcase_add_test(tc_core, test_mod149);
  tcase_add_test(tc_core, test_mod150);
  tcase_add_test(tc_core, test_mod151);
  tcase_add_test(tc_core, test_mod152);
  tcase_add_test(tc_core, test_mod153);
  tcase_add_test(tc_core, test_mod154);
  tcase_add_test(tc_core, test_mod155);
  tcase_add_test(tc_core, test_mod156);
  tcase_add_test(tc_core, test_mod157);
  tcase_add_test(tc_core, test_mod158);
  tcase_add_test(tc_core, test_mod159);
  tcase_add_test(tc_core, test_mod160);
  tcase_add_test(tc_core, test_mod161);
  tcase_add_test(tc_core, test_mod162);
  tcase_add_test(tc_core, test_mod163);
  tcase_add_test(tc_core, test_mod164);
  tcase_add_test(tc_core, test_mod165);
  tcase_add_test(tc_core, test_mod166);
  tcase_add_test(tc_core, test_mod167);
  tcase_add_test(tc_core, test_mod168);
  tcase_add_test(tc_core, test_mod169);
  tcase_add_test(tc_core, test_mod170);
  tcase_add_test(tc_core, test_mod171);
  tcase_add_test(tc_core, test_mod172);
  tcase_add_test(tc_core, test_mod173);
  tcase_add_test(tc_core, test_mod174);
  tcase_add_test(tc_core, test_mod175);
  tcase_add_test(tc_core, test_mod176);
  tcase_add_test(tc_core, test_mod177);
  tcase_add_test(tc_core, test_mod178);
  tcase_add_test(tc_core, test_mod179);
  tcase_add_test(tc_core, test_mod180);
  tcase_add_test(tc_core, test_mod181);
  tcase_add_test(tc_core, test_mod182);
  tcase_add_test(tc_core, test_mod183);
  tcase_add_test(tc_core, test_mod184);
  tcase_add_test(tc_core, test_mod185);
  tcase_add_test(tc_core, test_mod186);
  tcase_add_test(tc_core, test_mod187);
  tcase_add_test(tc_core, test_mod188);
  tcase_add_test(tc_core, test_mod189);
  tcase_add_test(tc_core, test_mod190);
  tcase_add_test(tc_core, test_mod191);
  tcase_add_test(tc_core, test_mod192);
  tcase_add_test(tc_core, test_mod193);
  tcase_add_test(tc_core, test_mod194);
  tcase_add_test(tc_core, test_mod195);
  tcase_add_test(tc_core, test_mod196);
  tcase_add_test(tc_core, test_mod197);
  tcase_add_test(tc_core, test_mod198);
  tcase_add_test(tc_core, test_mod199);
  tcase_add_test(tc_core, test_mod200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *mod_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("mod0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_mod_fail_manual1);
  tcase_add_test(tc_core, test_mod_fail_manual2);
  tcase_add_test(tc_core, test_mod_fail_manual3);
  tcase_add_test(tc_core, test_mod_fail_manual4);
  tcase_add_test(tc_core, test_mod_fail_manual5);
  tcase_add_test(tc_core, test_mod_fail_manual6);
  tcase_add_test(tc_core, test_mod_fail_manual7);
  tcase_add_test(tc_core, test_mod_fail_manual8);
  tcase_add_test(tc_core, test_mod_fail_manual9);
  tcase_add_test(tc_core, test_mod_fail_manual10);
  tcase_add_test(tc_core, test_mod_fail_manual11);
  tcase_add_test(tc_core, test_mod_fail_manual12);
  tcase_add_test(tc_core, test_mod_fail_manual13);
  tcase_add_test(tc_core, test_mod_fail_manual14);
  tcase_add_test(tc_core, test_mod_fail_manual15);
  tcase_add_test(tc_core, test_mod_fail_manual16);
  tcase_add_test(tc_core, test_mod_fail_manual17);

  tcase_add_test(tc_core, test_mod_manual1);
  tcase_add_test(tc_core, test_mod_manual2);
  tcase_add_test(tc_core, test_mod_manual3);
  tcase_add_test(tc_core, test_mod_manual4);
  tcase_add_test(tc_core, test_mod_manual5);
  tcase_add_test(tc_core, test_mod_manual6);
  tcase_add_test(tc_core, test_mod_manual7);

  tcase_add_test(tc_core, test_mod_manual100);
  tcase_add_test(tc_core, test_mod_manual101);
  tcase_add_test(tc_core, test_mod_manual102);
  tcase_add_test(tc_core, test_mod_manual103);
  tcase_add_test(tc_core, test_mod_manual104);
  tcase_add_test(tc_core, test_mod_manual105);
  tcase_add_test(tc_core, test_mod_manual106);
  tcase_add_test(tc_core, test_mod_manual107);
  tcase_add_test(tc_core, test_mod_manual108);
  tcase_add_test(tc_core, test_mod_manual109);
  tcase_add_test(tc_core, test_mod_manual110);
  tcase_add_test(tc_core, test_mod_manual111);
  tcase_add_test(tc_core, test_mod_manual112);
  tcase_add_test(tc_core, test_mod_manual113);
  tcase_add_test(tc_core, test_mod_manual114);
  tcase_add_test(tc_core, test_mod_manual115);
  tcase_add_test(tc_core, test_mod_manual116);
  tcase_add_test(tc_core, test_mod_manual117);
  tcase_add_test(tc_core, test_mod_manual118);
  tcase_add_test(tc_core, test_mod_manual119);
  tcase_add_test(tc_core, test_mod_manual120);
  tcase_add_test(tc_core, test_mod_manual121);
  tcase_add_test(tc_core, test_mod_manual122);
  tcase_add_test(tc_core, test_mod_manual123);
  tcase_add_test(tc_core, test_mod_manual124);
  tcase_add_test(tc_core, test_mod_manual125);
  tcase_add_test(tc_core, test_mod_manual126);
  tcase_add_test(tc_core, test_mod_manual127);

  tcase_add_test(tc_core, test_mod_manual200);
  tcase_add_test(tc_core, test_mod_manual201);
  tcase_add_test(tc_core, test_mod_manual202);
  tcase_add_test(tc_core, test_mod_manual203);
  tcase_add_test(tc_core, test_mod_manual204);
  tcase_add_test(tc_core, test_mod_manual205);
  tcase_add_test(tc_core, test_mod_manual206);
  tcase_add_test(tc_core, test_mod_manual207);
  tcase_add_test(tc_core, test_mod_manual208);
  tcase_add_test(tc_core, test_mod_manual209);
  tcase_add_test(tc_core, test_mod_manual210);
  tcase_add_test(tc_core, test_mod_manual211);
  tcase_add_test(tc_core, test_mod_manual212);
  tcase_add_test(tc_core, test_mod_manual213);
  tcase_add_test(tc_core, test_mod_manual214);
  tcase_add_test(tc_core, test_mod_manual215);
  tcase_add_test(tc_core, test_mod_manual216);
  tcase_add_test(tc_core, test_mod_manual217);
  tcase_add_test(tc_core, test_mod_manual218);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_mod(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

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

void test_mod_fail(s21_decimal decimal1, s21_decimal decimal2, int code_check) {
  s21_decimal result;
  int code = s21_mod(decimal1, decimal2, &result);

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
