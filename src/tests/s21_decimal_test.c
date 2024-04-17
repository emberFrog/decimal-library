#include "./../my_decimal.h"

#include <stdlib.h>

#include "./test.h"

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(NULL);
  srunner_add_suite(sr, add_suite0());
  srunner_add_suite(sr, add_suite1());

  srunner_add_suite(sr, sub_suite0());
  srunner_add_suite(sr, sub_suite1());

  srunner_add_suite(sr, mul_suite0());
  // srunner_add_suite(sr, mul_suite1());

  srunner_add_suite(sr, div_suite0());
  srunner_add_suite(sr, div_suite1());

  srunner_add_suite(sr, mod_suite0());
  srunner_add_suite(sr, mod_suite1());

  srunner_add_suite(sr, is_less_suite1());

  srunner_add_suite(sr, is_equal_suite1());

  srunner_add_suite(sr, is_less_or_equal_suite1());

  srunner_add_suite(sr, is_greater_suite1());

  srunner_add_suite(sr, is_greater_or_equal_suite1());

  srunner_add_suite(sr, is_not_equal_suite1());

  srunner_add_suite(sr, from_int_to_decimal_suite());

  srunner_add_suite(sr, from_float_to_decimal_suite0());
  srunner_add_suite(sr, from_float_to_decimal_suite1());

  srunner_add_suite(sr, from_decimal_to_int_suite0());
  srunner_add_suite(sr, from_decimal_to_int_suite1());

  srunner_add_suite(sr, from_decimal_to_float_suite0());
  srunner_add_suite(sr, from_decimal_to_float_suite1());

  srunner_add_suite(sr, floor_suite0());
  srunner_add_suite(sr, floor_suite1());

  srunner_add_suite(sr, round_suite0());
  srunner_add_suite(sr, round_suite1());

  srunner_add_suite(sr, truncate_suite0());
  srunner_add_suite(sr, truncate_suite1());

  srunner_add_suite(sr, negate_suite0());
  srunner_add_suite(sr, negate_suite1());

  srunner_add_suite(sr, debug0());
  srunner_add_suite(sr, debug1());
  srunner_add_suite(sr, debug2());
  srunner_add_suite(sr, debug3());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "-");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
