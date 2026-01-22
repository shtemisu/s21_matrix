#include "s21_tests.h"

START_TEST(test_sum_matrix_valid) {
  matrix_t mat1, mat2, result;
  s21_create_matrix(2, 2, &mat1);
  s21_create_matrix(2, 2, &mat2);

  mat1.matrix[0][0] = 1.0;
  mat1.matrix[0][1] = 2.0;
  mat1.matrix[1][0] = 3.0;
  mat1.matrix[1][1] = 4.0;

  mat2.matrix[0][0] = 5.0;
  mat2.matrix[0][1] = 6.0;
  mat2.matrix[1][0] = 7.0;
  mat2.matrix[1][1] = 8.0;

  ck_assert_int_eq(s21_sum_matrix(&mat1, &mat2, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 6.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 12.0);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix_diff_sizes) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(3, 2, &b);

  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), CALC_ERROR);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_null_pointer_result) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  ck_assert_int_eq(s21_sum_matrix(&a, &b, NULL), NOT_VALID_MATRIX);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_null_pointer_a_b) {
  matrix_t result;
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

Suite *sum_suite(void) {
  Suite *suite;
  TCase *tcase_core;
  suite = suite_create("s21_sum_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_sum_matrix_diff_sizes);
  tcase_add_test(tcase_core, test_sum_matrix_valid);
  tcase_add_test(tcase_core, test_null_pointer_result);
  tcase_add_test(tcase_core, test_null_pointer_a_b);
  suite_add_tcase(suite, tcase_core);
  return suite;
}