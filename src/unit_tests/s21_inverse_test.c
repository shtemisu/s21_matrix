#include "s21_tests.h"

START_TEST(test_valid_matrix_3x3) {
  matrix_t a, result, expected;
  s21_create_matrix(3, 3, &expected);
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 2.0f;
  a.matrix[0][1] = 5.0f;
  a.matrix[0][2] = 7.0f;
  a.matrix[1][0] = 6.0f;
  a.matrix[1][1] = 3.0f;
  a.matrix[1][2] = 4.0f;
  a.matrix[2][0] = 5.0f;
  a.matrix[2][1] = -2.0f;
  a.matrix[2][2] = -3.0f;

  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = -1.0;
  expected.matrix[0][2] = 1.0;
  expected.matrix[1][0] = -38.0;
  expected.matrix[1][1] = 41.0;
  expected.matrix[1][2] = -34.0;
  expected.matrix[2][0] = 27.0;
  expected.matrix[2][1] = -29.0;
  expected.matrix[2][2] = 24.0;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_valid_matrix_2x2) {
  matrix_t a, result, expected;

  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2.0f;
  a.matrix[0][1] = 5.0f;
  a.matrix[1][0] = 6.0f;
  a.matrix[1][1] = 3.0f;

  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -0.125;
  expected.matrix[0][1] = 5.0f / 24.0f;

  expected.matrix[1][0] = 0.25;
  expected.matrix[1][1] = -1.0f / 12.0f;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_valid_matrix_1x1) {
  matrix_t a, result, expected;

  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 2.0f;

  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 0.5f;

  ck_assert_int_eq(s21_inverse_matrix(&a, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_null_pointer_1) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  ck_assert_int_eq(s21_inverse_matrix(&a, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_null_pointer_2) {
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_determ_is_zero) {
  matrix_t a, result;
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][0] = 2;
  a.matrix[0][0] = 3;
  a.matrix[0][0] = 4;
  a.matrix[0][0] = 5;
  a.matrix[0][0] = 6;
  a.matrix[0][0] = 7;
  a.matrix[0][0] = 8;
  a.matrix[0][0] = 9;
  ck_assert_int_eq(s21_inverse_matrix(&a, &result), CALC_ERROR);
  s21_remove_matrix(&a);
}

Suite* inverse_suite(void) {
  Suite* suite;
  TCase* tcase_core;
  suite = suite_create("s21_inverse_test.c");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrix_3x3);
  tcase_add_test(tcase_core, test_valid_matrix_2x2);
  tcase_add_test(tcase_core, test_valid_matrix_1x1);
  tcase_add_test(tcase_core, test_null_pointer_1);
  tcase_add_test(tcase_core, test_null_pointer_2);
  tcase_add_test(tcase_core, test_determ_is_zero);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
