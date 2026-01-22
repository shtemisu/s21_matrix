#include "s21_tests.h"

START_TEST(test_mult_num_valid) {
  matrix_t a, result;
  s21_create_matrix(2, 2, &a);

  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = -2.5;
  a.matrix[1][0] = 3.0;
  a.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_mult_number(&a, 100, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 100.0);
  ck_assert_double_eq(result.matrix[0][1], -250.0);
  ck_assert_double_eq(result.matrix[1][0], 300.0);
  ck_assert_double_eq(result.matrix[1][1], 400.0);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_num_negative_sizes) {
  matrix_t a, result;
  a.columns = 2;
  a.rows = -3;
  a.matrix = NULL;
  ck_assert_int_eq(s21_mult_number(&a, 2, &result), NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_null_pointer) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);

  ck_assert_int_eq(s21_mult_number(&a, 2, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_null_pointer_a) {
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(NULL, 2, &result), NOT_VALID_MATRIX);
}
END_TEST

Suite *mult_num_suite(void) {
  Suite *suite;
  TCase *tcase_core;
  suite = suite_create("s21_mult_num_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_mult_num_negative_sizes);
  tcase_add_test(tcase_core, test_mult_num_valid);
  tcase_add_test(tcase_core, test_null_pointer);
  tcase_add_test(tcase_core, test_null_pointer_a);
  suite_add_tcase(suite, tcase_core);
  return suite;
}