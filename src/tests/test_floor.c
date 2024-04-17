#include <stdio.h>
#include <stdlib.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_floor_fail1) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = my_floor(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_floor_fail2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_floor_fail9) {
  // Просто все единицы
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal result;

  int code = my_floor(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_floor_ok1) {
  // 79228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok2) {
  // -79228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok3) {
  // 7922816251426433759354395033.5
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok4) {
  // -7922816251426433759354395033.5
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  my_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok5) {
  // 792281625142643375935439503.35
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok6) {
  // -792281625142643375935439503.35
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439504
  my_decimal decimal_check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok7) {
  // 79228162514264337593543950.335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok8) {
  // -79228162514264337593543950.335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543951
  my_decimal decimal_check = {{0x9DB22D0F, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok9) {
  // 7922816251426433759354395.0335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok10) {
  // -7922816251426433759354395.0335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354396
  my_decimal decimal_check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok11) {
  // 792281625142643375935439.50335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok12) {
  // -792281625142643375935439.50335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok13) {
  // 79228162514264337593543.950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok14) {
  // -79228162514264337593543.950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok15) {
  // 7922816251426433759354.3950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok16) {
  // -7922816251426433759354.3950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759355
  my_decimal decimal_check = {{0xF485787B, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok17) {
  // 792281625142643375935.43950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok18) {
  // -792281625142643375935.43950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375936
  my_decimal decimal_check = {{0x1873BF40, 0xF31DC461, 0x2A, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok19) {
  // 79228162514264337593.543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok20) {
  // -79228162514264337593.543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok21) {
  // 7922816251426433759.3543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok22) {
  // -7922816251426433759.3543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433760
  my_decimal decimal_check = {{0x5EF6EAE0, 0x6DF37F67, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok23) {
  // 792281625142643375.93543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok24) {
  // -792281625142643375.93543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok25) {
  // 79228162514264337.593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok26) {
  // -79228162514264337.593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok27) {
  // 7922816251426433.7593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok28) {
  // -7922816251426433.7593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok29) {
  // 792281625142643.37593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok30) {
  // -792281625142643.37593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142644
  my_decimal decimal_check = {{0x70D42574, 0x2D093, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok31) {
  // 79228162514264.337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok32) {
  // -79228162514264.337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514265
  my_decimal decimal_check = {{0xBE7B9D59, 0x480E, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok33) {
  // 7922816251426.4337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok34) {
  // -7922816251426.4337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251427
  my_decimal decimal_check = {{0xACA5F623, 0x734, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok35) {
  // 792281625142.64337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok36) {
  // -792281625142.64337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok37) {
  // 79228162514.264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok38) {
  // -79228162514.264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162515
  my_decimal decimal_check = {{0x725DD1D3, 0x12, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok39) {
  // 7922816251.4264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok40) {
  // -7922816251.4264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816252
  my_decimal decimal_check = {{0xD83C94FC, 0x1, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok41) {
  // 792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok42) {
  // -792281625.14264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281626
  my_decimal decimal_check = {{0x2F39421A, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok43) {
  // 79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok44) {
  // -79228162.514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  my_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok45) {
  // 7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok46) {
  // -7922816.2514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922817
  my_decimal decimal_check = {{0x78E481, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok47) {
  // 792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok48) {
  // -792281.62514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  my_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok49) {
  // 79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok50) {
  // -79228.162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79229
  my_decimal decimal_check = {{0x1357D, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok51) {
  // 7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok52) {
  // -7922.8162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  my_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok53) {
  // 792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok54) {
  // -792.28162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -793
  my_decimal decimal_check = {{0x319, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok55) {
  // 79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok56) {
  // -79.228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -80
  my_decimal decimal_check = {{0x50, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok57) {
  // 7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok58) {
  // -7.9228162514264337593543950335
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok59) {
  // 79228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok60) {
  // -79228162514264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok61) {
  // 7922816251426433759354395033.4
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok62) {
  // -7922816251426433759354395033.4
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  my_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok63) {
  // 792281625142643375935439503.34
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok64) {
  // -792281625142643375935439503.34
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439504
  my_decimal decimal_check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok65) {
  // 79228162514264337593543950.334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok66) {
  // -79228162514264337593543950.334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543951
  my_decimal decimal_check = {{0x9DB22D0F, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok67) {
  // 7922816251426433759354395.0334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok68) {
  // -7922816251426433759354395.0334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354396
  my_decimal decimal_check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok69) {
  // 792281625142643375935439.50334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok70) {
  // -792281625142643375935439.50334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok71) {
  // 79228162514264337593543.950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok72) {
  // -79228162514264337593543.950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok73) {
  // 7922816251426433759354.3950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok74) {
  // -7922816251426433759354.3950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759355
  my_decimal decimal_check = {{0xF485787B, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok75) {
  // 792281625142643375935.43950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok76) {
  // -792281625142643375935.43950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375936
  my_decimal decimal_check = {{0x1873BF40, 0xF31DC461, 0x2A, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok77) {
  // 79228162514264337593.543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok78) {
  // -79228162514264337593.543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok79) {
  // 7922816251426433759.3543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok80) {
  // -7922816251426433759.3543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433760
  my_decimal decimal_check = {{0x5EF6EAE0, 0x6DF37F67, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok81) {
  // 792281625142643375.93543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok82) {
  // -792281625142643375.93543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok83) {
  // 79228162514264337.593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok84) {
  // -79228162514264337.593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok85) {
  // 7922816251426433.7593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok86) {
  // -7922816251426433.7593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok87) {
  // 792281625142643.37593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok88) {
  // -792281625142643.37593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142644
  my_decimal decimal_check = {{0x70D42574, 0x2D093, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok89) {
  // 79228162514264.337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok90) {
  // -79228162514264.337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514265
  my_decimal decimal_check = {{0xBE7B9D59, 0x480E, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok91) {
  // 7922816251426.4337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok92) {
  // -7922816251426.4337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251427
  my_decimal decimal_check = {{0xACA5F623, 0x734, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok93) {
  // 792281625142.64337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok94) {
  // -792281625142.64337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok95) {
  // 79228162514.264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok96) {
  // -79228162514.264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162515
  my_decimal decimal_check = {{0x725DD1D3, 0x12, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok97) {
  // 7922816251.4264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok98) {
  // -7922816251.4264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816252
  my_decimal decimal_check = {{0xD83C94FC, 0x1, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok99) {
  // 792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_floor(decimal, decimal_check);
}

START_TEST(test_floor_ok100) {
  // -792281625.14264337593543950334
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281626
  my_decimal decimal_check = {{0x2F39421A, 0x0, 0x0, 0x80000000}};

  test_floor(decimal, decimal_check);
}

Suite *floor_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("floor_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_floor_ok1);
  tcase_add_test(tc_core, test_floor_ok2);
  tcase_add_test(tc_core, test_floor_ok3);
  tcase_add_test(tc_core, test_floor_ok4);
  tcase_add_test(tc_core, test_floor_ok5);
  tcase_add_test(tc_core, test_floor_ok6);
  tcase_add_test(tc_core, test_floor_ok7);
  tcase_add_test(tc_core, test_floor_ok8);
  tcase_add_test(tc_core, test_floor_ok9);
  tcase_add_test(tc_core, test_floor_ok10);
  tcase_add_test(tc_core, test_floor_ok11);
  tcase_add_test(tc_core, test_floor_ok12);
  tcase_add_test(tc_core, test_floor_ok13);
  tcase_add_test(tc_core, test_floor_ok14);
  tcase_add_test(tc_core, test_floor_ok15);
  tcase_add_test(tc_core, test_floor_ok16);
  tcase_add_test(tc_core, test_floor_ok17);
  tcase_add_test(tc_core, test_floor_ok18);
  tcase_add_test(tc_core, test_floor_ok19);
  tcase_add_test(tc_core, test_floor_ok20);
  tcase_add_test(tc_core, test_floor_ok21);
  tcase_add_test(tc_core, test_floor_ok22);
  tcase_add_test(tc_core, test_floor_ok23);
  tcase_add_test(tc_core, test_floor_ok24);
  tcase_add_test(tc_core, test_floor_ok25);
  tcase_add_test(tc_core, test_floor_ok26);
  tcase_add_test(tc_core, test_floor_ok27);
  tcase_add_test(tc_core, test_floor_ok28);
  tcase_add_test(tc_core, test_floor_ok29);
  tcase_add_test(tc_core, test_floor_ok30);
  tcase_add_test(tc_core, test_floor_ok31);
  tcase_add_test(tc_core, test_floor_ok32);
  tcase_add_test(tc_core, test_floor_ok33);
  tcase_add_test(tc_core, test_floor_ok34);
  tcase_add_test(tc_core, test_floor_ok35);
  tcase_add_test(tc_core, test_floor_ok36);
  tcase_add_test(tc_core, test_floor_ok37);
  tcase_add_test(tc_core, test_floor_ok38);
  tcase_add_test(tc_core, test_floor_ok39);
  tcase_add_test(tc_core, test_floor_ok40);
  tcase_add_test(tc_core, test_floor_ok41);
  tcase_add_test(tc_core, test_floor_ok42);
  tcase_add_test(tc_core, test_floor_ok43);
  tcase_add_test(tc_core, test_floor_ok44);
  tcase_add_test(tc_core, test_floor_ok45);
  tcase_add_test(tc_core, test_floor_ok46);
  tcase_add_test(tc_core, test_floor_ok47);
  tcase_add_test(tc_core, test_floor_ok48);
  tcase_add_test(tc_core, test_floor_ok49);
  tcase_add_test(tc_core, test_floor_ok50);
  tcase_add_test(tc_core, test_floor_ok51);
  tcase_add_test(tc_core, test_floor_ok52);
  tcase_add_test(tc_core, test_floor_ok53);
  tcase_add_test(tc_core, test_floor_ok54);
  tcase_add_test(tc_core, test_floor_ok55);
  tcase_add_test(tc_core, test_floor_ok56);
  tcase_add_test(tc_core, test_floor_ok57);
  tcase_add_test(tc_core, test_floor_ok58);
  tcase_add_test(tc_core, test_floor_ok59);
  tcase_add_test(tc_core, test_floor_ok60);
  tcase_add_test(tc_core, test_floor_ok61);
  tcase_add_test(tc_core, test_floor_ok62);
  tcase_add_test(tc_core, test_floor_ok63);
  tcase_add_test(tc_core, test_floor_ok64);
  tcase_add_test(tc_core, test_floor_ok65);
  tcase_add_test(tc_core, test_floor_ok66);
  tcase_add_test(tc_core, test_floor_ok67);
  tcase_add_test(tc_core, test_floor_ok68);
  tcase_add_test(tc_core, test_floor_ok69);
  tcase_add_test(tc_core, test_floor_ok70);
  tcase_add_test(tc_core, test_floor_ok71);
  tcase_add_test(tc_core, test_floor_ok72);
  tcase_add_test(tc_core, test_floor_ok73);
  tcase_add_test(tc_core, test_floor_ok74);
  tcase_add_test(tc_core, test_floor_ok75);
  tcase_add_test(tc_core, test_floor_ok76);
  tcase_add_test(tc_core, test_floor_ok77);
  tcase_add_test(tc_core, test_floor_ok78);
  tcase_add_test(tc_core, test_floor_ok79);
  tcase_add_test(tc_core, test_floor_ok80);
  tcase_add_test(tc_core, test_floor_ok81);
  tcase_add_test(tc_core, test_floor_ok82);
  tcase_add_test(tc_core, test_floor_ok83);
  tcase_add_test(tc_core, test_floor_ok84);
  tcase_add_test(tc_core, test_floor_ok85);
  tcase_add_test(tc_core, test_floor_ok86);
  tcase_add_test(tc_core, test_floor_ok87);
  tcase_add_test(tc_core, test_floor_ok88);
  tcase_add_test(tc_core, test_floor_ok89);
  tcase_add_test(tc_core, test_floor_ok90);
  tcase_add_test(tc_core, test_floor_ok91);
  tcase_add_test(tc_core, test_floor_ok92);
  tcase_add_test(tc_core, test_floor_ok93);
  tcase_add_test(tc_core, test_floor_ok94);
  tcase_add_test(tc_core, test_floor_ok95);
  tcase_add_test(tc_core, test_floor_ok96);
  tcase_add_test(tc_core, test_floor_ok97);
  tcase_add_test(tc_core, test_floor_ok98);
  tcase_add_test(tc_core, test_floor_ok99);
  tcase_add_test(tc_core, test_floor_ok100);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *floor_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("floor_suite0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_floor_fail1);
  tcase_add_test(tc_core, test_floor_fail2);
  tcase_add_test(tc_core, test_floor_fail3);
  tcase_add_test(tc_core, test_floor_fail4);
  tcase_add_test(tc_core, test_floor_fail5);
  tcase_add_test(tc_core, test_floor_fail6);
  tcase_add_test(tc_core, test_floor_fail7);
  tcase_add_test(tc_core, test_floor_fail8);
  tcase_add_test(tc_core, test_floor_fail9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_floor(my_decimal decimal, my_decimal decimal_check) {
  my_decimal result;

  int code = my_floor(decimal, &result);
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
  ck_assert_int_eq(my_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
