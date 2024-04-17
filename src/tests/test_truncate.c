#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_truncate_fail1) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = my_truncate(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_truncate_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail9) {
  // Просто все единицы
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_truncate_ok1) {
  // 79228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok2) {
  // -79228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok3) {
  // 7922816251426433759354395033.5
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok4) {
  // -7922816251426433759354395033.5
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok5) {
  // 792281625142643375935439503.35
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok6) {
  // -792281625142643375935439503.35
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok7) {
  // 79228162514264337593543950.335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok8) {
  // -79228162514264337593543950.335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok9) {
  // 7922816251426433759354395.0335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok10) {
  // -7922816251426433759354395.0335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok11) {
  // 792281625142643375935439.50335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok12) {
  // -792281625142643375935439.50335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok13) {
  // 79228162514264337593543.950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok14) {
  // -79228162514264337593543.950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok15) {
  // 7922816251426433759354.3950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok16) {
  // -7922816251426433759354.3950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok17) {
  // 792281625142643375935.43950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok18) {
  // -792281625142643375935.43950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok19) {
  // 79228162514264337593.543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok20) {
  // -79228162514264337593.543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok21) {
  // 7922816251426433759.3543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok22) {
  // -7922816251426433759.3543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok23) {
  // 792281625142643375.93543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok24) {
  // -792281625142643375.93543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok25) {
  // 79228162514264337.593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok26) {
  // -79228162514264337.593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok27) {
  // 7922816251426433.7593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok28) {
  // -7922816251426433.7593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok29) {
  // 792281625142643.37593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok30) {
  // -792281625142643.37593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok31) {
  // 79228162514264.337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok32) {
  // -79228162514264.337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok33) {
  // 7922816251426.4337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok34) {
  // -7922816251426.4337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok35) {
  // 792281625142.64337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok36) {
  // -792281625142.64337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok37) {
  // 79228162514.264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok38) {
  // -79228162514.264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok39) {
  // 7922816251.4264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok40) {
  // -7922816251.4264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok41) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok42) {
  // -792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok43) {
  // 79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok44) {
  // -79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228162
  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok45) {
  // 7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok46) {
  // -7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok47) {
  // 792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok48) {
  // -792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792281
  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok49) {
  // 79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok50) {
  // -79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok51) {
  // 7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok52) {
  // -7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7922
  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok53) {
  // 792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok54) {
  // -792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok55) {
  // 79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok56) {
  // -79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok57) {
  // 7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok58) {
  // -7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7
  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok59) {
  // 79228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok60) {
  // -79228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok61) {
  // 7922816251426433759354395033.4
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok62) {
  // -7922816251426433759354395033.4
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok63) {
  // 792281625142643375935439503.34
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok64) {
  // -792281625142643375935439503.34
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok65) {
  // 79228162514264337593543950.334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok66) {
  // -79228162514264337593543950.334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok67) {
  // 7922816251426433759354395.0334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok68) {
  // -7922816251426433759354395.0334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok69) {
  // 792281625142643375935439.50334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok70) {
  // -792281625142643375935439.50334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok71) {
  // 79228162514264337593543.950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok72) {
  // -79228162514264337593543.950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok73) {
  // 7922816251426433759354.3950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok74) {
  // -7922816251426433759354.3950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok75) {
  // 792281625142643375935.43950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok76) {
  // -792281625142643375935.43950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok77) {
  // 79228162514264337593.543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok78) {
  // -79228162514264337593.543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok79) {
  // 7922816251426433759.3543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok80) {
  // -7922816251426433759.3543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok81) {
  // 792281625142643375.93543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok82) {
  // -792281625142643375.93543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok83) {
  // 79228162514264337.593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok84) {
  // -79228162514264337.593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok85) {
  // 7922816251426433.7593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok86) {
  // -7922816251426433.7593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok87) {
  // 792281625142643.37593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok88) {
  // -792281625142643.37593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok89) {
  // 79228162514264.337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok90) {
  // -79228162514264.337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok91) {
  // 7922816251426.4337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok92) {
  // -7922816251426.4337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok93) {
  // 792281625142.64337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok94) {
  // -792281625142.64337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok95) {
  // 79228162514.264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok96) {
  // -79228162514.264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok97) {
  // 7922816251.4264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok98) {
  // -7922816251.4264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok99) {
  // 792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok100) {
  // -792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok101) {
  // 79228162.514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok102) {
  // -79228162.514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228162
  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok103) {
  // 7922816.2514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok104) {
  // -7922816.2514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok105) {
  // 792281.62514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok106) {
  // -792281.62514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792281
  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok107) {
  // 79228.162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok108) {
  // -79228.162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok109) {
  // 7922.8162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok110) {
  // -7922.8162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7922
  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok111) {
  // 792.28162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok112) {
  // -792.28162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok113) {
  // 79.228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok114) {
  // -79.228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok115) {
  // 7.9228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok116) {
  // -7.9228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7
  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok117) {
  // 52818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 52818775009509558395695966890
  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok118) {
  // -52818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -52818775009509558395695966890
  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok119) {
  // 5281877500950955839569596689.0
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839569596689
  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok120) {
  // -5281877500950955839569596689.0
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839569596689
  my_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok121) {
  // 5281877500950955.8395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // 5281877500950955
  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok122) {
  // -5281877500950955.8395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // -5281877500950955
  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok123) {
  // 5.2818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // 5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok124) {
  // -5.2818775009509558395695966890
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // -5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok125) {
  // 52818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 52818775009509558392832655360
  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok126) {
  // -52818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -52818775009509558392832655360
  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok127) {
  // 5281877500950955839283265536.0
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839283265536
  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok128) {
  // -5281877500950955839283265536.0
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839283265536
  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok129) {
  // 5281877500950955.8392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};
  // 5281877500950955
  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok130) {
  // -5281877500950955.8392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};
  // -5281877500950955
  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok131) {
  // 5.2818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  // 5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok132) {
  // -5.2818775009509558392832655360
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  // -5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok133) {
  // 52818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  // 52818774997211729016086244010
  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok134) {
  // -52818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  // -52818774997211729016086244010
  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok135) {
  // 5281877499721172901608624401.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  // 5281877499721172901608624401
  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok136) {
  // -5281877499721172901608624401.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  // -5281877499721172901608624401
  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok137) {
  // 5281877499721172.9016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};
  // 5281877499721172
  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok138) {
  // -5281877499721172.9016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // -5281877499721172
  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok139) {
  // 5.2818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // 5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok140) {
  // -5.2818774997211729016086244010
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // -5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok141) {
  // 52818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};
  // 52818774997211729013222932480
  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok142) {
  // -52818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};
  // -52818774997211729013222932480
  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok143) {
  // 5281877499721172901322293248.0
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};
  // 5281877499721172901322293248
  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok144) {
  // -5281877499721172901322293248.0
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};
  // -5281877499721172901322293248
  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok145) {
  // 5281877499721172.9013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};
  // 5281877499721172
  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok146) {
  // -5281877499721172.9013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};
  // -5281877499721172
  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok147) {
  // 5.2818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  // 5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok148) {
  // -5.2818774997211729013222932480
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  // -5
  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok149) {
  // 12297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};
  // 12297829382473034410
  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok150) {
  // -12297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};
  // -12297829382473034410
  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok151) {
  // 1229782938247303441.0
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};
  // 1229782938247303441
  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok152) {
  // -1229782938247303441.0
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};
  // -1229782938247303441
  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok153) {
  // 122978293.82473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  // 122978293
  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok154) {
  // -122978293.82473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // -122978293
  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok155) {
  // 1.2297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 1
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok156) {
  // -1.2297829382473034410
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok157) {
  // 12297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};
  // 12297829379609722880
  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok158) {
  // -12297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};
  // -12297829379609722880
  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok159) {
  // 1229782937960972288.0
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};
  // 1229782937960972288
  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok160) {
  // -1229782937960972288.0
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};
  // -1229782937960972288
  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok161) {
  // 122978293.79609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  // 122978293
  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok162) {
  // -122978293.79609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  // -122978293
  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok163) {
  // 1.2297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  // 1
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok164) {
  // -1.2297829379609722880
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -1
  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok165) {
  // 2863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};
  // 2863311530
  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok166) {
  // -2863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};
  // -2863311530
  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok167) {
  // 286331153.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  // 286331153
  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok168) {
  // -286331153.0
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  // -286331153
  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok169) {
  // 286331.1530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  // 286331
  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok170) {
  // -286331.1530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  // -286331
  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok171) {
  // 2.863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  // 2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok172) {
  // -2.863311530
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  // -2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok173) {
  // 26409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok174) {
  // -26409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok175) {
  // 2640938750475477919784798344.5
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};
  // 2640938750475477919784798344
  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok176) {
  // -2640938750475477919784798344.5
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};
  // -2640938750475477919784798344
  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok177) {
  // 2640938750475477.9197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};
  // 2640938750475477
  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok178) {
  // -2640938750475477.9197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};
  // -2640938750475477
  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok179) {
  // 2.6409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  // 2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok180) {
  // -2.6409387504754779197847983445
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  // -2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok181) {
  // 26409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779196416327680
  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok182) {
  // -26409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779196416327680
  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok183) {
  // 2640938750475477919641632768.0
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};
  // 2640938750475477919641632768
  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok184) {
  // -2640938750475477919641632768.0
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};
  // -2640938750475477919641632768
  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok185) {
  // 2640938750475477.9196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};
  // 2640938750475477
  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok186) {
  // -2640938750475477.9196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};
  // -2640938750475477
  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok187) {
  // 2.6409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  // 2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok188) {
  // -2.6409387504754779196416327680
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  // -2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok189) {
  // 26409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};
  // 26409387498605864508043122005
  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok190) {
  // -26409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864508043122005
  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok191) {
  // 2640938749860586450804312200.5
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};
  // 2640938749860586450804312200
  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok192) {
  // -2640938749860586450804312200.5
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};
  // -2640938749860586450804312200
  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok193) {
  // 2640938749860586.4508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};
  // 2640938749860586
  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok194) {
  // -2640938749860586.4508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};
  // -2640938749860586
  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok195) {
  // 2.6409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  // 2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok196) {
  // -2.6409387498605864508043122005
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  // -2
  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok197) {
  // 26409387498605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};
  // 26409387498605864506611466240
  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok198) {
  // -26409387498605864506611466240
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};
  // -26409387498605864506611466240
  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok199) {
  // 2640938749860586450661146624.0
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};
  // 2640938749860586450661146624
  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok200) {
  // -2640938749860586450661146624.0
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};
  // -2640938749860586450661146624
  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

Suite *truncate_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_ok1);
  tcase_add_test(tc_core, test_truncate_ok2);
  tcase_add_test(tc_core, test_truncate_ok3);
  tcase_add_test(tc_core, test_truncate_ok4);
  tcase_add_test(tc_core, test_truncate_ok5);
  tcase_add_test(tc_core, test_truncate_ok6);
  tcase_add_test(tc_core, test_truncate_ok7);
  tcase_add_test(tc_core, test_truncate_ok8);
  tcase_add_test(tc_core, test_truncate_ok9);
  tcase_add_test(tc_core, test_truncate_ok10);
  tcase_add_test(tc_core, test_truncate_ok11);
  tcase_add_test(tc_core, test_truncate_ok12);
  tcase_add_test(tc_core, test_truncate_ok13);
  tcase_add_test(tc_core, test_truncate_ok14);
  tcase_add_test(tc_core, test_truncate_ok15);
  tcase_add_test(tc_core, test_truncate_ok16);
  tcase_add_test(tc_core, test_truncate_ok17);
  tcase_add_test(tc_core, test_truncate_ok18);
  tcase_add_test(tc_core, test_truncate_ok19);
  tcase_add_test(tc_core, test_truncate_ok20);
  tcase_add_test(tc_core, test_truncate_ok21);
  tcase_add_test(tc_core, test_truncate_ok22);
  tcase_add_test(tc_core, test_truncate_ok23);
  tcase_add_test(tc_core, test_truncate_ok24);
  tcase_add_test(tc_core, test_truncate_ok25);
  tcase_add_test(tc_core, test_truncate_ok26);
  tcase_add_test(tc_core, test_truncate_ok27);
  tcase_add_test(tc_core, test_truncate_ok28);
  tcase_add_test(tc_core, test_truncate_ok29);
  tcase_add_test(tc_core, test_truncate_ok30);
  tcase_add_test(tc_core, test_truncate_ok31);
  tcase_add_test(tc_core, test_truncate_ok32);
  tcase_add_test(tc_core, test_truncate_ok33);
  tcase_add_test(tc_core, test_truncate_ok34);
  tcase_add_test(tc_core, test_truncate_ok35);
  tcase_add_test(tc_core, test_truncate_ok36);
  tcase_add_test(tc_core, test_truncate_ok37);
  tcase_add_test(tc_core, test_truncate_ok38);
  tcase_add_test(tc_core, test_truncate_ok39);
  tcase_add_test(tc_core, test_truncate_ok40);
  tcase_add_test(tc_core, test_truncate_ok41);
  tcase_add_test(tc_core, test_truncate_ok42);
  tcase_add_test(tc_core, test_truncate_ok43);
  tcase_add_test(tc_core, test_truncate_ok44);
  tcase_add_test(tc_core, test_truncate_ok45);
  tcase_add_test(tc_core, test_truncate_ok46);
  tcase_add_test(tc_core, test_truncate_ok47);
  tcase_add_test(tc_core, test_truncate_ok48);
  tcase_add_test(tc_core, test_truncate_ok49);
  tcase_add_test(tc_core, test_truncate_ok50);
  tcase_add_test(tc_core, test_truncate_ok51);
  tcase_add_test(tc_core, test_truncate_ok52);
  tcase_add_test(tc_core, test_truncate_ok53);
  tcase_add_test(tc_core, test_truncate_ok54);
  tcase_add_test(tc_core, test_truncate_ok55);
  tcase_add_test(tc_core, test_truncate_ok56);
  tcase_add_test(tc_core, test_truncate_ok57);
  tcase_add_test(tc_core, test_truncate_ok58);
  tcase_add_test(tc_core, test_truncate_ok59);
  tcase_add_test(tc_core, test_truncate_ok60);
  tcase_add_test(tc_core, test_truncate_ok61);
  tcase_add_test(tc_core, test_truncate_ok62);
  tcase_add_test(tc_core, test_truncate_ok63);
  tcase_add_test(tc_core, test_truncate_ok64);
  tcase_add_test(tc_core, test_truncate_ok65);
  tcase_add_test(tc_core, test_truncate_ok66);
  tcase_add_test(tc_core, test_truncate_ok67);
  tcase_add_test(tc_core, test_truncate_ok68);
  tcase_add_test(tc_core, test_truncate_ok69);
  tcase_add_test(tc_core, test_truncate_ok70);
  tcase_add_test(tc_core, test_truncate_ok71);
  tcase_add_test(tc_core, test_truncate_ok72);
  tcase_add_test(tc_core, test_truncate_ok73);
  tcase_add_test(tc_core, test_truncate_ok74);
  tcase_add_test(tc_core, test_truncate_ok75);
  tcase_add_test(tc_core, test_truncate_ok76);
  tcase_add_test(tc_core, test_truncate_ok77);
  tcase_add_test(tc_core, test_truncate_ok78);
  tcase_add_test(tc_core, test_truncate_ok79);
  tcase_add_test(tc_core, test_truncate_ok80);
  tcase_add_test(tc_core, test_truncate_ok81);
  tcase_add_test(tc_core, test_truncate_ok82);
  tcase_add_test(tc_core, test_truncate_ok83);
  tcase_add_test(tc_core, test_truncate_ok84);
  tcase_add_test(tc_core, test_truncate_ok85);
  tcase_add_test(tc_core, test_truncate_ok86);
  tcase_add_test(tc_core, test_truncate_ok87);
  tcase_add_test(tc_core, test_truncate_ok88);
  tcase_add_test(tc_core, test_truncate_ok89);
  tcase_add_test(tc_core, test_truncate_ok90);
  tcase_add_test(tc_core, test_truncate_ok91);
  tcase_add_test(tc_core, test_truncate_ok92);
  tcase_add_test(tc_core, test_truncate_ok93);
  tcase_add_test(tc_core, test_truncate_ok94);
  tcase_add_test(tc_core, test_truncate_ok95);
  tcase_add_test(tc_core, test_truncate_ok96);
  tcase_add_test(tc_core, test_truncate_ok97);
  tcase_add_test(tc_core, test_truncate_ok98);
  tcase_add_test(tc_core, test_truncate_ok99);
  tcase_add_test(tc_core, test_truncate_ok100);
  tcase_add_test(tc_core, test_truncate_ok101);
  tcase_add_test(tc_core, test_truncate_ok102);
  tcase_add_test(tc_core, test_truncate_ok103);
  tcase_add_test(tc_core, test_truncate_ok104);
  tcase_add_test(tc_core, test_truncate_ok105);
  tcase_add_test(tc_core, test_truncate_ok106);
  tcase_add_test(tc_core, test_truncate_ok107);
  tcase_add_test(tc_core, test_truncate_ok108);
  tcase_add_test(tc_core, test_truncate_ok109);
  tcase_add_test(tc_core, test_truncate_ok110);
  tcase_add_test(tc_core, test_truncate_ok111);
  tcase_add_test(tc_core, test_truncate_ok112);
  tcase_add_test(tc_core, test_truncate_ok113);
  tcase_add_test(tc_core, test_truncate_ok114);
  tcase_add_test(tc_core, test_truncate_ok115);
  tcase_add_test(tc_core, test_truncate_ok116);
  tcase_add_test(tc_core, test_truncate_ok117);
  tcase_add_test(tc_core, test_truncate_ok118);
  tcase_add_test(tc_core, test_truncate_ok119);
  tcase_add_test(tc_core, test_truncate_ok120);
  tcase_add_test(tc_core, test_truncate_ok121);
  tcase_add_test(tc_core, test_truncate_ok122);
  tcase_add_test(tc_core, test_truncate_ok123);
  tcase_add_test(tc_core, test_truncate_ok124);
  tcase_add_test(tc_core, test_truncate_ok125);
  tcase_add_test(tc_core, test_truncate_ok126);
  tcase_add_test(tc_core, test_truncate_ok127);
  tcase_add_test(tc_core, test_truncate_ok128);
  tcase_add_test(tc_core, test_truncate_ok129);
  tcase_add_test(tc_core, test_truncate_ok130);
  tcase_add_test(tc_core, test_truncate_ok131);
  tcase_add_test(tc_core, test_truncate_ok132);
  tcase_add_test(tc_core, test_truncate_ok133);
  tcase_add_test(tc_core, test_truncate_ok134);
  tcase_add_test(tc_core, test_truncate_ok135);
  tcase_add_test(tc_core, test_truncate_ok136);
  tcase_add_test(tc_core, test_truncate_ok137);
  tcase_add_test(tc_core, test_truncate_ok138);
  tcase_add_test(tc_core, test_truncate_ok139);
  tcase_add_test(tc_core, test_truncate_ok140);
  tcase_add_test(tc_core, test_truncate_ok141);
  tcase_add_test(tc_core, test_truncate_ok142);
  tcase_add_test(tc_core, test_truncate_ok143);
  tcase_add_test(tc_core, test_truncate_ok144);
  tcase_add_test(tc_core, test_truncate_ok145);
  tcase_add_test(tc_core, test_truncate_ok146);
  tcase_add_test(tc_core, test_truncate_ok147);
  tcase_add_test(tc_core, test_truncate_ok148);
  tcase_add_test(tc_core, test_truncate_ok149);
  tcase_add_test(tc_core, test_truncate_ok150);
  tcase_add_test(tc_core, test_truncate_ok151);
  tcase_add_test(tc_core, test_truncate_ok152);
  tcase_add_test(tc_core, test_truncate_ok153);
  tcase_add_test(tc_core, test_truncate_ok154);
  tcase_add_test(tc_core, test_truncate_ok155);
  tcase_add_test(tc_core, test_truncate_ok156);
  tcase_add_test(tc_core, test_truncate_ok157);
  tcase_add_test(tc_core, test_truncate_ok158);
  tcase_add_test(tc_core, test_truncate_ok159);
  tcase_add_test(tc_core, test_truncate_ok160);
  tcase_add_test(tc_core, test_truncate_ok161);
  tcase_add_test(tc_core, test_truncate_ok162);
  tcase_add_test(tc_core, test_truncate_ok163);
  tcase_add_test(tc_core, test_truncate_ok164);
  tcase_add_test(tc_core, test_truncate_ok165);
  tcase_add_test(tc_core, test_truncate_ok166);
  tcase_add_test(tc_core, test_truncate_ok167);
  tcase_add_test(tc_core, test_truncate_ok168);
  tcase_add_test(tc_core, test_truncate_ok169);
  tcase_add_test(tc_core, test_truncate_ok170);
  tcase_add_test(tc_core, test_truncate_ok171);
  tcase_add_test(tc_core, test_truncate_ok172);
  tcase_add_test(tc_core, test_truncate_ok173);
  tcase_add_test(tc_core, test_truncate_ok174);
  tcase_add_test(tc_core, test_truncate_ok175);
  tcase_add_test(tc_core, test_truncate_ok176);
  tcase_add_test(tc_core, test_truncate_ok177);
  tcase_add_test(tc_core, test_truncate_ok178);
  tcase_add_test(tc_core, test_truncate_ok179);
  tcase_add_test(tc_core, test_truncate_ok180);
  tcase_add_test(tc_core, test_truncate_ok181);
  tcase_add_test(tc_core, test_truncate_ok182);
  tcase_add_test(tc_core, test_truncate_ok183);
  tcase_add_test(tc_core, test_truncate_ok184);
  tcase_add_test(tc_core, test_truncate_ok185);
  tcase_add_test(tc_core, test_truncate_ok186);
  tcase_add_test(tc_core, test_truncate_ok187);
  tcase_add_test(tc_core, test_truncate_ok188);
  tcase_add_test(tc_core, test_truncate_ok189);
  tcase_add_test(tc_core, test_truncate_ok190);
  tcase_add_test(tc_core, test_truncate_ok191);
  tcase_add_test(tc_core, test_truncate_ok192);
  tcase_add_test(tc_core, test_truncate_ok193);
  tcase_add_test(tc_core, test_truncate_ok194);
  tcase_add_test(tc_core, test_truncate_ok195);
  tcase_add_test(tc_core, test_truncate_ok196);
  tcase_add_test(tc_core, test_truncate_ok197);
  tcase_add_test(tc_core, test_truncate_ok198);
  tcase_add_test(tc_core, test_truncate_ok199);
  tcase_add_test(tc_core, test_truncate_ok200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *truncate_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_fail1);
  tcase_add_test(tc_core, test_truncate_fail2);
  tcase_add_test(tc_core, test_truncate_fail3);
  tcase_add_test(tc_core, test_truncate_fail4);
  tcase_add_test(tc_core, test_truncate_fail5);
  tcase_add_test(tc_core, test_truncate_fail6);
  tcase_add_test(tc_core, test_truncate_fail7);
  tcase_add_test(tc_core, test_truncate_fail8);
  tcase_add_test(tc_core, test_truncate_fail9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_truncate(my_decimal decimal, my_decimal decimal_check) {
  my_decimal result;

  int code = my_truncate(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  my_print_decimal_bits(decimal);
  my_print_decimal_string(decimal);
  printf("\ncheck:\n");
  my_print_decimal_bits(decimal_check);
  my_print_decimal_string(decimal_check);
  printf("sign = %d\n", sign_check);
  printf("\nres:\n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
  printf("sign = %d\n", sign_result);
  printf("---------------------------------\n\n\n\n");
#endif

  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
