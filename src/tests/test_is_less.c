#include <stdio.h>

#include "./../my_decimal.h"
#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_is_less_ok1) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok2) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok3) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok4) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok5) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok6) {
  // 52818775009509558395695966890
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok7) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok8) {
  // -52818775009509558395695966890
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok9) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok10) {
  // 52818775009509558395695966891
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok11) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok12) {
  // -52818775009509558395695966891
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok13) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  my_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok14) {
  // 5.281877500950955839569596690
  my_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok15) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  my_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok16) {
  // -5.281877500950955839569596690
  my_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok17) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  my_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok18) {
  // 5281877500950955839569596689
  my_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok19) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  my_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok20) {
  // -5281877500950955839569596689
  my_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok21) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok22) {
  // 5281877500950955839569596689.0
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok23) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok24) {
  // -5281877500950955839569596689.0
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok25) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok26) {
  // 7922816251426433759354395033
  my_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok27) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok28) {
  // -7922816251426433759354395033
  my_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok29) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok30) {
  // 7922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok31) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok32) {
  // -7922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok33) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  my_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok34) {
  // 1.2297829382473034409
  my_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok35) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  my_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok36) {
  // -1.2297829382473034409
  my_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok37) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok38) {
  // 1.2297829382473034410
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok39) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok40) {
  // -1.2297829382473034410
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok41) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok42) {
  // 1.2297829382473034411
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok43) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok44) {
  // -1.2297829382473034411
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok45) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok46) {
  // 1
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok47) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok48) {
  // -1
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok49) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok50) {
  // 1.0
  my_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok51) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok52) {
  // -1.0
  my_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok53) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  my_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok54) {
  // 1.22
  my_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok55) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  my_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok56) {
  // -1.22
  my_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok57) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  my_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok58) {
  // 1.230001
  my_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok59) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  my_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok60) {
  // -1.230001
  my_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok61) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  my_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok62) {
  // 1.23000
  my_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok63) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  my_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok64) {
  // -1.23000
  my_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok65) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok66) {
  // 1431655765
  my_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok67) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok68) {
  // -1431655765
  my_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok69) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  my_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok70) {
  // 1431655765.00000
  my_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok71) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  my_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok72) {
  // -1431655765.00000
  my_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok73) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  my_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok74) {
  // 1431655765.000000000000000001
  my_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok75) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  my_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok76) {
  // -1431655765.000000000000000001
  my_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok77) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  my_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok78) {
  // 1431655764.999999999999999999
  my_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok79) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  my_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok80) {
  // -1431655764.999999999999999999
  my_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok81) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  my_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok82) {
  // 0.9999999999999999999999999999
  my_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok83) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  my_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok84) {
  // -0.9999999999999999999999999999
  my_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok85) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok86) {
  // 0.0000000000000000000000000001
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok87) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok88) {
  // -0.0000000000000000000000000001
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok89) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok90) {
  // 0
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok91) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok92) {
  // -0
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok93) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok94) {
  // -0.00000000000000
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok95) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok96) {
  // 0.00000000000000
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok97) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok98) {
  // -0.0000000000000000000000000000
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok99) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  my_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok100) {
  // 0.0000000000000000000000000000
  my_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok101) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -58391.31040040850204230282817
  my_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x80170000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok102) {
  // -58391.31040040850204230282817
  my_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x80170000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok103) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 58391.31040040850204230282817
  my_decimal decimal2 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok104) {
  // 58391.31040040850204230282817
  my_decimal decimal1 = {{0x9AA5EE41, 0xF3B5B959, 0x12DE0417, 0x170000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok105) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5596930204637261591.6377658369
  my_decimal decimal2 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0xA0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok106) {
  // 5596930204637261591.6377658369
  my_decimal decimal1 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0xA0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok107) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5596930204637261591.6377658369
  my_decimal decimal2 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0x800A0000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok108) {
  // -5596930204637261591.6377658369
  my_decimal decimal1 = {{0x9B10D401, 0x8F08DC74, 0xB4D8B8B7, 0x800A0000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok109) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 47209772988309285293.155713691
  my_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok110) {
  // 47209772988309285293.155713691
  my_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok111) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -47209772988309285293.155713691
  my_decimal decimal2 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x80090000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok112) {
  // -47209772988309285293.155713691
  my_decimal decimal1 = {{0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x80090000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok113) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok114) {
  // 79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok115) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok116) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok117) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966890
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok118) {
  // 52818775009509558395695966890
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok119) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966890
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok120) {
  // -52818775009509558395695966890
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok121) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 52818775009509558395695966891
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok122) {
  // 52818775009509558395695966891
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok123) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -52818775009509558395695966891
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok124) {
  // -52818775009509558395695966891
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok125) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5.281877500950955839569596690
  my_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok126) {
  // 5.281877500950955839569596690
  my_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok127) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5.281877500950955839569596690
  my_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok128) {
  // -5.281877500950955839569596690
  my_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok129) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689
  my_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok130) {
  // 5281877500950955839569596689
  my_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok131) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689
  my_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok132) {
  // -5281877500950955839569596689
  my_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok133) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5281877500950955839569596689.0
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok134) {
  // 5281877500950955839569596689.0
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok135) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5281877500950955839569596689.0
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok136) {
  // -5281877500950955839569596689.0
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok137) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok138) {
  // 7922816251426433759354395033
  my_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok139) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  my_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok140) {
  // -7922816251426433759354395033
  my_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok141) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok142) {
  // 7922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok143) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395034
  my_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok144) {
  // -7922816251426433759354395034
  my_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok145) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034409
  my_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok146) {
  // 1.2297829382473034409
  my_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok147) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034409
  my_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok148) {
  // -1.2297829382473034409
  my_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok149) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034410
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok150) {
  // 1.2297829382473034410
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok151) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034410
  my_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok152) {
  // -1.2297829382473034410
  my_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok153) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.2297829382473034411
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok154) {
  // 1.2297829382473034411
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok155) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.2297829382473034411
  my_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok156) {
  // -1.2297829382473034411
  my_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok157) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok158) {
  // 1
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok159) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok160) {
  // -1
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok161) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok162) {
  // 1.0
  my_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok163) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  my_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok164) {
  // -1.0
  my_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok165) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.22
  my_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok166) {
  // 1.22
  my_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok167) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.22
  my_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok168) {
  // -1.22
  my_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok169) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.230001
  my_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok170) {
  // 1.230001
  my_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok171) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.230001
  my_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok172) {
  // -1.230001
  my_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok173) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.23000
  my_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok174) {
  // 1.23000
  my_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok175) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.23000
  my_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok176) {
  // -1.23000
  my_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok177) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok178) {
  // 1431655765
  my_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok179) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765
  my_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok180) {
  // -1431655765
  my_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok181) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.00000
  my_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok182) {
  // 1431655765.00000
  my_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok183) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.00000
  my_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok184) {
  // -1431655765.00000
  my_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok185) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655765.000000000000000001
  my_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok186) {
  // 1431655765.000000000000000001
  my_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok187) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655765.000000000000000001
  my_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok188) {
  // -1431655765.000000000000000001
  my_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok189) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1431655764.999999999999999999
  my_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok190) {
  // 1431655764.999999999999999999
  my_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok191) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1431655764.999999999999999999
  my_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok192) {
  // -1431655764.999999999999999999
  my_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok193) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  my_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok194) {
  // 0.9999999999999999999999999999
  my_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok195) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  my_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok196) {
  // -0.9999999999999999999999999999
  my_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok197) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok198) {
  // 0.0000000000000000000000000001
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok199) {
  // -79228162514264337593543950335
  my_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  my_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = TEST_COMPARISON_TRUE;

  test_is_less(decimal1, decimal2, check);
}

START_TEST(test_is_less_ok200) {
  // -0.0000000000000000000000000001
  my_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -79228162514264337593543950335
  my_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = TEST_COMPARISON_FALSE;

  test_is_less(decimal1, decimal2, check);
}

Suite *is_less_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("is_less_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_is_less_ok1);
  tcase_add_test(tc_core, test_is_less_ok2);
  tcase_add_test(tc_core, test_is_less_ok3);
  tcase_add_test(tc_core, test_is_less_ok4);
  tcase_add_test(tc_core, test_is_less_ok5);
  tcase_add_test(tc_core, test_is_less_ok6);
  tcase_add_test(tc_core, test_is_less_ok7);
  tcase_add_test(tc_core, test_is_less_ok8);
  tcase_add_test(tc_core, test_is_less_ok9);
  tcase_add_test(tc_core, test_is_less_ok10);
  tcase_add_test(tc_core, test_is_less_ok11);
  tcase_add_test(tc_core, test_is_less_ok12);
  tcase_add_test(tc_core, test_is_less_ok13);
  tcase_add_test(tc_core, test_is_less_ok14);
  tcase_add_test(tc_core, test_is_less_ok15);
  tcase_add_test(tc_core, test_is_less_ok16);
  tcase_add_test(tc_core, test_is_less_ok17);
  tcase_add_test(tc_core, test_is_less_ok18);
  tcase_add_test(tc_core, test_is_less_ok19);
  tcase_add_test(tc_core, test_is_less_ok20);
  tcase_add_test(tc_core, test_is_less_ok21);
  tcase_add_test(tc_core, test_is_less_ok22);
  tcase_add_test(tc_core, test_is_less_ok23);
  tcase_add_test(tc_core, test_is_less_ok24);
  tcase_add_test(tc_core, test_is_less_ok25);
  tcase_add_test(tc_core, test_is_less_ok26);
  tcase_add_test(tc_core, test_is_less_ok27);
  tcase_add_test(tc_core, test_is_less_ok28);
  tcase_add_test(tc_core, test_is_less_ok29);
  tcase_add_test(tc_core, test_is_less_ok30);
  tcase_add_test(tc_core, test_is_less_ok31);
  tcase_add_test(tc_core, test_is_less_ok32);
  tcase_add_test(tc_core, test_is_less_ok33);
  tcase_add_test(tc_core, test_is_less_ok34);
  tcase_add_test(tc_core, test_is_less_ok35);
  tcase_add_test(tc_core, test_is_less_ok36);
  tcase_add_test(tc_core, test_is_less_ok37);
  tcase_add_test(tc_core, test_is_less_ok38);
  tcase_add_test(tc_core, test_is_less_ok39);
  tcase_add_test(tc_core, test_is_less_ok40);
  tcase_add_test(tc_core, test_is_less_ok41);
  tcase_add_test(tc_core, test_is_less_ok42);
  tcase_add_test(tc_core, test_is_less_ok43);
  tcase_add_test(tc_core, test_is_less_ok44);
  tcase_add_test(tc_core, test_is_less_ok45);
  tcase_add_test(tc_core, test_is_less_ok46);
  tcase_add_test(tc_core, test_is_less_ok47);
  tcase_add_test(tc_core, test_is_less_ok48);
  tcase_add_test(tc_core, test_is_less_ok49);
  tcase_add_test(tc_core, test_is_less_ok50);
  tcase_add_test(tc_core, test_is_less_ok51);
  tcase_add_test(tc_core, test_is_less_ok52);
  tcase_add_test(tc_core, test_is_less_ok53);
  tcase_add_test(tc_core, test_is_less_ok54);
  tcase_add_test(tc_core, test_is_less_ok55);
  tcase_add_test(tc_core, test_is_less_ok56);
  tcase_add_test(tc_core, test_is_less_ok57);
  tcase_add_test(tc_core, test_is_less_ok58);
  tcase_add_test(tc_core, test_is_less_ok59);
  tcase_add_test(tc_core, test_is_less_ok60);
  tcase_add_test(tc_core, test_is_less_ok61);
  tcase_add_test(tc_core, test_is_less_ok62);
  tcase_add_test(tc_core, test_is_less_ok63);
  tcase_add_test(tc_core, test_is_less_ok64);
  tcase_add_test(tc_core, test_is_less_ok65);
  tcase_add_test(tc_core, test_is_less_ok66);
  tcase_add_test(tc_core, test_is_less_ok67);
  tcase_add_test(tc_core, test_is_less_ok68);
  tcase_add_test(tc_core, test_is_less_ok69);
  tcase_add_test(tc_core, test_is_less_ok70);
  tcase_add_test(tc_core, test_is_less_ok71);
  tcase_add_test(tc_core, test_is_less_ok72);
  tcase_add_test(tc_core, test_is_less_ok73);
  tcase_add_test(tc_core, test_is_less_ok74);
  tcase_add_test(tc_core, test_is_less_ok75);
  tcase_add_test(tc_core, test_is_less_ok76);
  tcase_add_test(tc_core, test_is_less_ok77);
  tcase_add_test(tc_core, test_is_less_ok78);
  tcase_add_test(tc_core, test_is_less_ok79);
  tcase_add_test(tc_core, test_is_less_ok80);
  tcase_add_test(tc_core, test_is_less_ok81);
  tcase_add_test(tc_core, test_is_less_ok82);
  tcase_add_test(tc_core, test_is_less_ok83);
  tcase_add_test(tc_core, test_is_less_ok84);
  tcase_add_test(tc_core, test_is_less_ok85);
  tcase_add_test(tc_core, test_is_less_ok86);
  tcase_add_test(tc_core, test_is_less_ok87);
  tcase_add_test(tc_core, test_is_less_ok88);
  tcase_add_test(tc_core, test_is_less_ok89);
  tcase_add_test(tc_core, test_is_less_ok90);
  tcase_add_test(tc_core, test_is_less_ok91);
  tcase_add_test(tc_core, test_is_less_ok92);
  tcase_add_test(tc_core, test_is_less_ok93);
  tcase_add_test(tc_core, test_is_less_ok94);
  tcase_add_test(tc_core, test_is_less_ok95);
  tcase_add_test(tc_core, test_is_less_ok96);
  tcase_add_test(tc_core, test_is_less_ok97);
  tcase_add_test(tc_core, test_is_less_ok98);
  tcase_add_test(tc_core, test_is_less_ok99);
  tcase_add_test(tc_core, test_is_less_ok100);
  tcase_add_test(tc_core, test_is_less_ok101);
  tcase_add_test(tc_core, test_is_less_ok102);
  tcase_add_test(tc_core, test_is_less_ok103);
  tcase_add_test(tc_core, test_is_less_ok104);
  tcase_add_test(tc_core, test_is_less_ok105);
  tcase_add_test(tc_core, test_is_less_ok106);
  tcase_add_test(tc_core, test_is_less_ok107);
  tcase_add_test(tc_core, test_is_less_ok108);
  tcase_add_test(tc_core, test_is_less_ok109);
  tcase_add_test(tc_core, test_is_less_ok110);
  tcase_add_test(tc_core, test_is_less_ok111);
  tcase_add_test(tc_core, test_is_less_ok112);
  tcase_add_test(tc_core, test_is_less_ok113);
  tcase_add_test(tc_core, test_is_less_ok114);
  tcase_add_test(tc_core, test_is_less_ok115);
  tcase_add_test(tc_core, test_is_less_ok116);
  tcase_add_test(tc_core, test_is_less_ok117);
  tcase_add_test(tc_core, test_is_less_ok118);
  tcase_add_test(tc_core, test_is_less_ok119);
  tcase_add_test(tc_core, test_is_less_ok120);
  tcase_add_test(tc_core, test_is_less_ok121);
  tcase_add_test(tc_core, test_is_less_ok122);
  tcase_add_test(tc_core, test_is_less_ok123);
  tcase_add_test(tc_core, test_is_less_ok124);
  tcase_add_test(tc_core, test_is_less_ok125);
  tcase_add_test(tc_core, test_is_less_ok126);
  tcase_add_test(tc_core, test_is_less_ok127);
  tcase_add_test(tc_core, test_is_less_ok128);
  tcase_add_test(tc_core, test_is_less_ok129);
  tcase_add_test(tc_core, test_is_less_ok130);
  tcase_add_test(tc_core, test_is_less_ok131);
  tcase_add_test(tc_core, test_is_less_ok132);
  tcase_add_test(tc_core, test_is_less_ok133);
  tcase_add_test(tc_core, test_is_less_ok134);
  tcase_add_test(tc_core, test_is_less_ok135);
  tcase_add_test(tc_core, test_is_less_ok136);
  tcase_add_test(tc_core, test_is_less_ok137);
  tcase_add_test(tc_core, test_is_less_ok138);
  tcase_add_test(tc_core, test_is_less_ok139);
  tcase_add_test(tc_core, test_is_less_ok140);
  tcase_add_test(tc_core, test_is_less_ok141);
  tcase_add_test(tc_core, test_is_less_ok142);
  tcase_add_test(tc_core, test_is_less_ok143);
  tcase_add_test(tc_core, test_is_less_ok144);
  tcase_add_test(tc_core, test_is_less_ok145);
  tcase_add_test(tc_core, test_is_less_ok146);
  tcase_add_test(tc_core, test_is_less_ok147);
  tcase_add_test(tc_core, test_is_less_ok148);
  tcase_add_test(tc_core, test_is_less_ok149);
  tcase_add_test(tc_core, test_is_less_ok150);
  tcase_add_test(tc_core, test_is_less_ok151);
  tcase_add_test(tc_core, test_is_less_ok152);
  tcase_add_test(tc_core, test_is_less_ok153);
  tcase_add_test(tc_core, test_is_less_ok154);
  tcase_add_test(tc_core, test_is_less_ok155);
  tcase_add_test(tc_core, test_is_less_ok156);
  tcase_add_test(tc_core, test_is_less_ok157);
  tcase_add_test(tc_core, test_is_less_ok158);
  tcase_add_test(tc_core, test_is_less_ok159);
  tcase_add_test(tc_core, test_is_less_ok160);
  tcase_add_test(tc_core, test_is_less_ok161);
  tcase_add_test(tc_core, test_is_less_ok162);
  tcase_add_test(tc_core, test_is_less_ok163);
  tcase_add_test(tc_core, test_is_less_ok164);
  tcase_add_test(tc_core, test_is_less_ok165);
  tcase_add_test(tc_core, test_is_less_ok166);
  tcase_add_test(tc_core, test_is_less_ok167);
  tcase_add_test(tc_core, test_is_less_ok168);
  tcase_add_test(tc_core, test_is_less_ok169);
  tcase_add_test(tc_core, test_is_less_ok170);
  tcase_add_test(tc_core, test_is_less_ok171);
  tcase_add_test(tc_core, test_is_less_ok172);
  tcase_add_test(tc_core, test_is_less_ok173);
  tcase_add_test(tc_core, test_is_less_ok174);
  tcase_add_test(tc_core, test_is_less_ok175);
  tcase_add_test(tc_core, test_is_less_ok176);
  tcase_add_test(tc_core, test_is_less_ok177);
  tcase_add_test(tc_core, test_is_less_ok178);
  tcase_add_test(tc_core, test_is_less_ok179);
  tcase_add_test(tc_core, test_is_less_ok180);
  tcase_add_test(tc_core, test_is_less_ok181);
  tcase_add_test(tc_core, test_is_less_ok182);
  tcase_add_test(tc_core, test_is_less_ok183);
  tcase_add_test(tc_core, test_is_less_ok184);
  tcase_add_test(tc_core, test_is_less_ok185);
  tcase_add_test(tc_core, test_is_less_ok186);
  tcase_add_test(tc_core, test_is_less_ok187);
  tcase_add_test(tc_core, test_is_less_ok188);
  tcase_add_test(tc_core, test_is_less_ok189);
  tcase_add_test(tc_core, test_is_less_ok190);
  tcase_add_test(tc_core, test_is_less_ok191);
  tcase_add_test(tc_core, test_is_less_ok192);
  tcase_add_test(tc_core, test_is_less_ok193);
  tcase_add_test(tc_core, test_is_less_ok194);
  tcase_add_test(tc_core, test_is_less_ok195);
  tcase_add_test(tc_core, test_is_less_ok196);
  tcase_add_test(tc_core, test_is_less_ok197);
  tcase_add_test(tc_core, test_is_less_ok198);
  tcase_add_test(tc_core, test_is_less_ok199);
  tcase_add_test(tc_core, test_is_less_ok200);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_is_less(my_decimal decimal1, my_decimal decimal2, int check) {
  int code = my_is_less(decimal1, decimal2);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("Tests:\n");
  my_print_decimal_bits(decimal1);
  my_print_decimal_string(decimal1);
  my_print_decimal_bits(decimal2);
  my_print_decimal_string(decimal2);
  printf("Check: %d\n", check);
  printf("Result: %d\n", code);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(code, check);
}
