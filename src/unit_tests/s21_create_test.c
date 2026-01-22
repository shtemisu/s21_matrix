#include "s21_tests.h"

START_TEST(test_all_good) {
  matrix_t a;
  int error_code = s21_create_matrix(4, 4, &a);
  ck_assert_int_eq(error_code, OK);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_zero_rows) {
  matrix_t a;
  int error_code = s21_create_matrix(0, 0, &a);
  ck_assert_int_eq(error_code, NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_null_pointer_test) {
  int error_code = s21_create_matrix(0, 4, NULL);
  ck_assert_int_eq(error_code, NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_negative_test) {
  matrix_t matrix;
  int error_code = s21_create_matrix(-213, 4, &matrix);
  ck_assert_int_eq(error_code, NOT_VALID_MATRIX);
}
END_TEST

Suite* create_remove_suite() {
  Suite* suite;
  TCase* tcase_core;
  suite = suite_create("s21_create_matrix");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_all_good);
  tcase_add_test(tcase_core, test_negative_test);
  tcase_add_test(tcase_core, test_null_pointer_test);
  tcase_add_test(tcase_core, test_zero_rows);
  suite_add_tcase(suite, tcase_core);
  return suite;
}