#include "./test_from_float_to_decimal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../s21_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на ненормальные float
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal2) {
  float f = -0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  int code = s21_from_float_to_decimal(f, &result);

  int sign_check = test_decimal_get_sign(check);
  int sign_result = test_decimal_get_sign(result);

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_incorrect1) {
  float f = 1.0f;
  int code = s21_from_float_to_decimal(f, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big) {
  float f = fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big_negate) {
  float f = -fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small) {
  float f = fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small_negate) {
  float f = -fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_ok1) {
  // 2.28401628E-19
  int f = 545706772;
  // 0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2) {
  // -2.28401628E-19
  int f = -1601776876;
  // -0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok3) {
  // 5.92141241E+23
  int f = 1727711253;
  // 592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok4) {
  // -5.92141241E+23
  int f = -419772395;
  // -592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok5) {
  // 2.1349025E-18
  int f = 572360491;
  // 0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok6) {
  // -2.1349025E-18
  int f = -1575123157;
  // -0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok7) {
  // 2.38582807E-08
  int f = 852291818;
  // 0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok8) {
  // -2.38582807E-08
  int f = -1295191830;
  // -0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok9) {
  // 7.91617864E+11
  int f = 1396199450;
  // 791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok10) {
  // -7.91617864E+11
  int f = -751284198;
  // -791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok11) {
  // 1.99102057E+21
  int f = 1658314220;
  // 1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok12) {
  // -1.99102057E+21
  int f = -489169428;
  // -1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok13) {
  // 9.29209423E+24
  int f = 1760949678;
  // 9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok14) {
  // -9.29209423E+24
  int f = -386533970;
  // -9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok15) {
  // 0.000115481133
  int f = 955395702;
  // 0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok16) {
  // -0.000115481133
  int f = -1192087946;
  // -0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok17) {
  // 8.66900895E-23
  int f = 449944209;
  // 0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok18) {
  // -8.66900895E-23
  int f = -1697539439;
  // -0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok19) {
  // 3.91406387E+11
  int f = 1387676487;
  // 391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok20) {
  // -3.91406387E+11
  int f = -759807161;
  // -391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok21) {
  // 1.54636995E-16
  int f = 624052425;
  // 0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok22) {
  // -1.54636995E-16
  int f = -1523431223;
  // -0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok23) {
  // 1.05583253E-13
  int f = 703447194;
  // 0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok24) {
  // -1.05583253E-13
  int f = -1444036454;
  // -0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok25) {
  // 4882.71582
  int f = 1167627706;
  // 4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok26) {
  // -4882.71582
  int f = -979855942;
  // -4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok27) {
  // 1.9929916E-26
  int f = 348479575;
  // 0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok28) {
  // -1.9929916E-26
  int f = -1799004073;
  // -0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok29) {
  // 3574.10864
  int f = 1163878845;
  // 3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok30) {
  // -3574.10864
  int f = -983604803;
  // -3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok31) {
  // 3.62930687E-13
  int f = 718032851;
  // 0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok32) {
  // -3.62930687E-13
  int f = -1429450797;
  // -0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok33) {
  // 2.1409382E-19
  int f = 545047011;
  // 0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok34) {
  // -2.1409382E-19
  int f = -1602436637;
  // -0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok35) {
  // 241.244507
  int f = 1131495064;
  // 241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok36) {
  // -241.244507
  int f = -1015988584;
  // -241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok37) {
  // 802580.063
  int f = 1229189441;
  // 802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok38) {
  // -802580.063
  int f = -918294207;
  // -802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok39) {
  // 8.38680669E+16
  int f = 1536490184;
  // 83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok40) {
  // -8.38680669E+16
  int f = -610993464;
  // -83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok41) {
  // 3.93541897E-17
  int f = 607485242;
  // 0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok42) {
  // -3.93541897E-17
  int f = -1539998406;
  // -0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok43) {
  // 1.45764168E-20
  int f = 512338845;
  // 0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok44) {
  // -1.45764168E-20
  int f = -1635144803;
  // -0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok45) {
  // 1.34647118E+20
  int f = 1625920341;
  // 134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok46) {
  // -1.34647118E+20
  int f = -521563307;
  // -134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok47) {
  // 2.20958198E-20
  int f = 516993130;
  // 0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok48) {
  // -2.20958198E-20
  int f = -1630490518;
  // -0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok49) {
  // 5.36623235E-09
  int f = 834167265;
  // 0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok50) {
  // -5.36623235E-09
  int f = -1313316383;
  // -0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok51) {
  // 4.71008997E+17
  int f = 1557212038;
  // 471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok52) {
  // -4.71008997E+17
  int f = -590271610;
  // -471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok53) {
  // 2.36363464E-11
  int f = 768600146;
  // 0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok54) {
  // -2.36363464E-11
  int f = -1378883502;
  // -0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok55) {
  // 0.0255207196
  int f = 1020334292;
  // 0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok56) {
  // -0.0255207196
  int f = -1127149356;
  // -0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok57) {
  // 3.9575282E-24
  int f = 412686710;
  // 0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok58) {
  // -3.9575282E-24
  int f = -1734796938;
  // -0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok59) {
  // 0.00399137754
  int f = 998427162;
  // 0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok60) {
  // -0.00399137754
  int f = -1149056486;
  // -0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok61) {
  // 1.95127377E-05
  int f = 933474121;
  // 0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok62) {
  // -1.95127377E-05
  int f = -1214009527;
  // -0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok63) {
  // 1.26745242E-20
  int f = 510618173;
  // 0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok64) {
  // -1.26745242E-20
  int f = -1636865475;
  // -0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok65) {
  // 0.0764362067
  int f = 1033669270;
  // 0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok66) {
  // -0.0764362067
  int f = -1113814378;
  // -0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok67) {
  // 1.19421885E-18
  int f = 565197904;
  // 0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok68) {
  // -1.19421885E-18
  int f = -1582285744;
  // -0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok69) {
  // 7.93902012E-16
  int f = 644141985;
  // 0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok70) {
  // -7.93902012E-16
  int f = -1503341663;
  // -0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok71) {
  // 5.86327048E-15
  int f = 668155680;
  // 0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok72) {
  // -5.86327048E-15
  int f = -1479327968;
  // -0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok73) {
  // 8.52215659E-11
  int f = 784033658;
  // 0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok74) {
  // -8.52215659E-11
  int f = -1363449990;
  // -0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok75) {
  // 9.61645806E-28
  int f = 311976189;
  // 0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok76) {
  // -9.61645806E-28
  int f = -1835507459;
  // -0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok77) {
  // 46282560
  int f = 1278250448;
  // 46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok78) {
  // -46282560
  int f = -869233200;
  // -46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok79) {
  // 1.15109615E-12
  int f = 732037276;
  // 0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok80) {
  // -1.15109615E-12
  int f = -1415446372;
  // -0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok81) {
  // 2.83794689E-11
  int f = 771334370;
  // 0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok82) {
  // -2.83794689E-11
  int f = -1376149278;
  // -0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok83) {
  // 8.43187742E-10
  int f = 812107280;
  // 0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok84) {
  // -8.43187742E-10
  int f = -1335376368;
  // -0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok85) {
  // 9.83161032E+17
  int f = 1566199356;
  // 983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok86) {
  // -9.83161032E+17
  int f = -581284292;
  // -983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok87) {
  // 5010.18115
  int f = 1167888755;
  // 5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok88) {
  // -5010.18115
  int f = -979594893;
  // -5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok89) {
  // 5.82704236E-25
  int f = 389306006;
  // 0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok90) {
  // -5.82704236E-25
  int f = -1758177642;
  // -0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok91) {
  // 5.07265574E+16
  int f = 1530148745;
  // 50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok92) {
  // -5.07265574E+16
  int f = -617334903;
  // -50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok93) {
  // 1.35639493E+19
  int f = 1597783252;
  // 13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok94) {
  // -1.35639493E+19
  int f = -549700396;
  // -13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok95) {
  // 1.2867606E+27
  int f = 1820658757;
  // 1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok96) {
  // -1.2867606E+27
  int f = -326824891;
  // -1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok97) {
  // 9.07980924E+20
  int f = 1648681745;
  // 907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok98) {
  // -9.07980924E+20
  int f = -498801903;
  // -907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok99) {
  // 15372566
  int f = 1265275158;
  // 15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok100) {
  // -15372566
  int f = -882208490;
  // -15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok101) {
  // 9.85001198E-23
  int f = 451815583;
  // 0.0000000000000000000000985001
  s21_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok102) {
  // -9.85001198E-23
  int f = -1695668065;
  // -0.0000000000000000000000985001
  s21_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok103) {
  // 4.58205132E-12
  int f = 748762995;
  // 0.000000000004582051
  s21_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok104) {
  // -4.58205132E-12
  int f = -1398720653;
  // -0.000000000004582051
  s21_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok105) {
  // 6.88863376E-12
  int f = 754081612;
  // 0.000000000006888634
  s21_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok106) {
  // -6.88863376E-12
  int f = -1393402036;
  // -0.000000000006888634
  s21_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok107) {
  // 1.94770514E+10
  int f = 1351687559;
  // 19477050000
  s21_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok108) {
  // -1.94770514E+10
  int f = -795796089;
  // -19477050000
  s21_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok109) {
  // 0.000745483907
  int f = 977497236;
  // 0.0007454839
  s21_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok110) {
  // -0.000745483907
  int f = -1169986412;
  // -0.0007454839
  s21_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok111) {
  // 7.85835969E+18
  int f = 1591352577;
  // 7858360000000000000
  s21_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok112) {
  // -7.85835969E+18
  int f = -556131071;
  // -7858360000000000000
  s21_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok113) {
  // 4.39337262E+21
  int f = 1668164171;
  // 4393373000000000000000
  s21_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok114) {
  // -4.39337262E+21
  int f = -479319477;
  // -4393373000000000000000
  s21_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok115) {
  // 4.8940947E+19
  int f = 1613352011;
  // 48940950000000000000
  s21_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok116) {
  // -4.8940947E+19
  int f = -534131637;
  // -48940950000000000000
  s21_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok117) {
  // 2.1753997E+18
  int f = 1576109204;
  // 2175400000000000000
  s21_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok118) {
  // -2.1753997E+18
  int f = -571374444;
  // -2175400000000000000
  s21_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok119) {
  // 8.42251829E+11
  int f = 1396972063;
  // 842251800000
  s21_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok120) {
  // -8.42251829E+11
  int f = -750511585;
  // -842251800000
  s21_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok121) {
  // 4.26393967E-07
  int f = 887417636;
  // 0.000000426394
  s21_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok122) {
  // -4.26393967E-07
  int f = -1260066012;
  // -0.000000426394
  s21_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok123) {
  // 1.84532337E-12
  int f = 738318948;
  // 0.000000000001845323
  s21_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok124) {
  // -1.84532337E-12
  int f = -1409164700;
  // -0.000000000001845323
  s21_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok125) {
  // 7.70974401E-20
  int f = 532023947;
  // 0.00000000000000000007709744
  s21_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok126) {
  // -7.70974401E-20
  int f = -1615459701;
  // -0.00000000000000000007709744
  s21_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok127) {
  // 0.0104842195
  int f = 1009501697;
  // 0.01048422
  s21_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok128) {
  // -0.0104842195
  int f = -1137981951;
  // -0.01048422
  s21_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok129) {
  // 1.98140566E-22
  int f = 460294537;
  // 0.0000000000000000000001981406
  s21_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok130) {
  // -1.98140566E-22
  int f = -1687189111;
  // -0.0000000000000000000001981406
  s21_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok131) {
  // 1.17932588E+22
  int f = 1679807510;
  // 11793260000000000000000
  s21_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok132) {
  // -1.17932588E+22
  int f = -467676138;
  // -11793260000000000000000
  s21_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok133) {
  // 356700.438
  int f = 1219373966;
  // 356700.4
  s21_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok134) {
  // -356700.438
  int f = -928109682;
  // -356700.4
  s21_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok135) {
  // 4.27844415E-17
  int f = 608521972;
  // 0.00000000000000004278444
  s21_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok136) {
  // -4.27844415E-17
  int f = -1538961676;
  // -0.00000000000000004278444
  s21_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok137) {
  // 12419649
  int f = 1262322241;
  // 12419650
  s21_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok138) {
  // -12419649
  int f = -885161407;
  // -12419650
  s21_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok139) {
  // 3.08497797E-21
  int f = 493426727;
  // 0.000000000000000000003084978
  s21_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok140) {
  // -3.08497797E-21
  int f = -1654056921;
  // -0.000000000000000000003084978
  s21_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok141) {
  // 4.18459603E+15
  int f = 1500372451;
  // 4184596000000000
  s21_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok142) {
  // -4.18459603E+15
  int f = -647111197;
  // -4184596000000000
  s21_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok143) {
  // 1.16865436E+26
  int f = 1791055472;
  // 116865400000000000000000000
  s21_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok144) {
  // -1.16865436E+26
  int f = -356428176;
  // -116865400000000000000000000
  s21_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok145) {
  // 2.70840103E+12
  int f = 1411229266;
  // 2708401000000
  s21_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok146) {
  // -2.70840103E+12
  int f = -736254382;
  // -2708401000000
  s21_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok147) {
  // 6.74712444E-21
  int f = 503244335;
  // 0.000000000000000000006747124
  s21_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok148) {
  // -6.74712444E-21
  int f = -1644239313;
  // -0.000000000000000000006747124
  s21_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok149) {
  // 5.64592297E-11
  int f = 779636593;
  // 0.00000000005645923
  s21_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok150) {
  // -5.64592297E-11
  int f = -1367847055;
  // -0.00000000005645923
  s21_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok151) {
  // 4.58151199E+10
  int f = 1361751220;
  // 45815120000
  s21_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok152) {
  // -4.58151199E+10
  int f = -785732428;
  // -45815120000
  s21_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok153) {
  // 1.48573706E-20
  int f = 512512747;
  // 0.00000000000000000001485737
  s21_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok154) {
  // -1.48573706E-20
  int f = -1634970901;
  // -0.00000000000000000001485737
  s21_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok155) {
  // 1.40592974E-22
  int f = 455735147;
  // 0.000000000000000000000140593
  s21_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok156) {
  // -1.40592974E-22
  int f = -1691748501;
  // -0.000000000000000000000140593
  s21_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok157) {
  // 1.83958331E+22
  int f = 1685671774;
  // 18395830000000000000000
  s21_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok158) {
  // -1.83958331E+22
  int f = -461811874;
  // -18395830000000000000000
  s21_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok159) {
  // 1.04831784E-07
  int f = 870391778;
  // 0.0000001048318
  s21_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok160) {
  // -1.04831784E-07
  int f = -1277091870;
  // -0.0000001048318
  s21_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok161) {
  // 3.40432057E+16
  int f = 1525802043;
  // 34043210000000000
  s21_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok162) {
  // -3.40432057E+16
  int f = -621681605;
  // -34043210000000000
  s21_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok163) {
  // 4.44212428E-21
  int f = 497537431;
  // 0.000000000000000000004442124
  s21_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok164) {
  // -4.44212428E-21
  int f = -1649946217;
  // -0.000000000000000000004442124
  s21_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok165) {
  // 2.77922045E-05
  int f = 938025806;
  // 0.0000277922
  s21_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok166) {
  // -2.77922045E-05
  int f = -1209457842;
  // -0.0000277922
  s21_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok167) {
  // 2.47787305E-13
  int f = 713784810;
  // 0.0000000000002477873
  s21_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok168) {
  // -2.47787305E-13
  int f = -1433698838;
  // -0.0000000000002477873
  s21_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok169) {
  // 8.1853854E-19
  int f = 561092358;
  // 0.0000000000000000008185385
  s21_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok170) {
  // -8.1853854E-19
  int f = -1586391290;
  // -0.0000000000000000008185385
  s21_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok171) {
  // 2.11021068E+24
  int f = 1742695776;
  // 2110211000000000000000000
  s21_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok172) {
  // -2.11021068E+24
  int f = -404787872;
  // -2110211000000000000000000
  s21_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok173) {
  // 1.82873229E+09
  int f = 1322909819;
  // 1828732000
  s21_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok174) {
  // -1.82873229E+09
  int f = -824573829;
  // -1828732000
  s21_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok175) {
  // 3807398.25
  int f = 1248354969;
  // 3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok176) {
  // -3807398.25
  int f = -899128679;
  // -3807398
  s21_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok177) {
  // 807.082397
  int f = 1145685318;
  // 807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok178) {
  // -807.082397
  int f = -1001798330;
  // -807.0824
  s21_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok179) {
  // 1.00471938E-16
  int f = 619162666;
  // 0.0000000000000001004719
  s21_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok180) {
  // -1.00471938E-16
  int f = -1528320982;
  // -0.0000000000000001004719
  s21_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok181) {
  // 1.31486965E-18
  int f = 566364767;
  // 0.00000000000000000131487
  s21_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok182) {
  // -1.31486965E-18
  int f = -1581118881;
  // -0.00000000000000000131487
  s21_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok183) {
  // 8.47554286E-13
  int f = 728666297;
  // 0.0000000000008475543
  s21_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok184) {
  // -8.47554286E-13
  int f = -1418817351;
  // -0.0000000000008475543
  s21_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok185) {
  // 2.07975469E-28
  int f = 293851635;
  // 0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok186) {
  // -2.07975469E-28
  int f = -1853632013;
  // -0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok187) {
  // 2.76817269E+13
  int f = 1439263036;
  // 27681730000000
  s21_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok188) {
  // -2.76817269E+13
  int f = -708220612;
  // -27681730000000
  s21_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok189) {
  // 2.64643858E+12
  int f = 1410992898;
  // 2646439000000
  s21_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok190) {
  // -2.64643858E+12
  int f = -736490750;
  // -2646439000000
  s21_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok191) {
  // 7.66456801E+18
  int f = 1591000072;
  // 7664568000000000000
  s21_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok192) {
  // -7.66456801E+18
  int f = -556483576;
  // -7664568000000000000
  s21_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok193) {
  // 2.76005793E+27
  int f = 1829679376;
  // 2760058000000000000000000000
  s21_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok194) {
  // -2.76005793E+27
  int f = -317804272;
  // -2760058000000000000000000000
  s21_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok195) {
  // 4.72614865E-19
  int f = 554401221;
  // 0.0000000000000000004726149
  s21_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok196) {
  // -4.72614865E-19
  int f = -1593082427;
  // -0.0000000000000000004726149
  s21_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok197) {
  // 1.22559799E-13
  int f = 705297781;
  // 0.0000000000001225598
  s21_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok198) {
  // -1.22559799E-13
  int f = -1442185867;
  // -0.0000000000001225598
  s21_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok199) {
  // 4.67068756E+27
  int f = 1836152841;
  // 4670688000000000000000000000
  s21_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok200) {
  // -4.67068756E+27
  int f = -311330807;
  // -4670688000000000000000000000
  s21_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

Suite *from_float_to_decimal_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok5);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok6);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok7);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok8);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok9);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok10);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok11);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok12);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok13);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok14);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok15);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok16);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok17);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok18);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok19);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok20);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok21);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok22);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok23);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok24);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok25);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok26);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok27);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok28);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok29);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok30);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok31);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok32);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok33);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok34);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok35);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok36);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok37);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok38);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok39);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok40);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok41);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok42);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok43);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok44);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok45);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok46);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok47);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok48);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok49);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok50);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok51);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok52);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok53);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok54);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok55);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok56);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok57);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok58);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok59);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok60);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok61);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok62);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok63);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok64);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok65);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok66);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok67);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok68);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok69);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok70);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok71);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok72);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok73);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok74);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok75);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok76);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok77);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok78);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok79);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok80);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok81);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok82);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok83);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok84);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok85);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok86);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok87);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok88);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok89);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok90);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok91);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok92);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok93);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok94);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok95);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok96);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok97);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok98);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok99);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok100);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok101);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok102);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok103);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok104);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok105);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok106);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok107);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok108);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok109);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok110);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok111);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok112);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok113);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok114);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok115);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok116);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok117);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok118);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok119);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok120);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok121);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok122);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok123);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok124);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok125);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok126);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok127);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok128);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok129);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok130);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok131);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok132);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok133);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok134);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok135);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok136);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok137);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok138);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok139);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok140);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok141);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok142);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok143);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok144);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok145);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok146);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok147);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok148);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok149);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok150);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok151);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok152);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok153);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok154);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok155);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok156);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok157);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok158);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok159);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok160);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok161);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok162);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok163);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok164);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok165);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok166);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok167);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok168);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok169);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok170);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok171);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok172);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok173);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok174);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok175);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok176);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok177);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok178);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok179);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok180);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok181);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok182);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok183);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok184);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok185);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok186);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok187);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok188);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok189);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok190);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok191);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok192);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok193);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok194);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok195);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok196);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok197);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok198);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok199);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal0");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_big, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_big_negate, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_small, 0,
                      sizeof(fails_small) / sizeof(*fails_small));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_small_negate, 0,
                      sizeof(fails_small) / sizeof(*fails_small));

  tcase_add_test(tc_core, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal2);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal6);

  suite_add_tcase(s, tc_core);

  return s;
}

void test_from_float_to_decimal(int f, s21_decimal decimal_check) {
  s21_decimal result;

  float_cast_test cast_float;
  cast_float.int32_bytes = f;

  int code = s21_from_float_to_decimal(cast_float.f, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("Float:   %.28f\n", cast_float.f);
  printf("Decimal_check: \n");
  s21_print_decimal_bits(decimal_check);
  s21_print_decimal_string(decimal_check);
  printf("Decimal_result: \n");
  s21_print_decimal_bits(result);
  s21_print_decimal_string(result);
#endif

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
