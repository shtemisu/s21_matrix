#include "s21_tests.h"

START_TEST(test_valid_matrix_1x1) {
  matrix_t a, result, expected;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &expected);
  ck_assert_int_eq(s21_calc_complements(&a, &result), OK);
  expected.matrix[0][0] = 1.0f;
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_valid_matrix_2x2) {
  matrix_t a, result, expected;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &expected);

  a.matrix[0][0] = 4.0f;
  a.matrix[0][1] = 2.0f;
  a.matrix[1][0] = 3.0f;
  a.matrix[1][1] = 2.0f;
  ck_assert_int_eq(s21_calc_complements(&a, &result), OK);

  expected.matrix[0][0] = 2.0f;
  expected.matrix[0][1] = -3.0f;
  expected.matrix[1][0] = -2.0f;
  expected.matrix[1][1] = 4.0f;

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_valid_matrix_3x3) {
  matrix_t a, result, expected;

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &expected);

  a.matrix[0][0] = 2.0f;
  a.matrix[0][1] = 5.0f;
  a.matrix[0][2] = 1.0f;
  a.matrix[1][0] = 2.0f;
  a.matrix[1][1] = 1.0f;
  a.matrix[1][2] = 3.0f;
  a.matrix[2][0] = 2.0f;
  a.matrix[2][1] = 1.0f;
  a.matrix[2][2] = 3.0f;

  ck_assert_int_eq(s21_calc_complements(&a, &result), OK);

  expected.matrix[0][0] = 0.0f;
  expected.matrix[0][1] = 0.0f;
  expected.matrix[0][2] = 0.0f;
  expected.matrix[1][0] = -14.0f;
  expected.matrix[1][1] = 4.0f;
  expected.matrix[1][2] = 8.0f;
  expected.matrix[2][0] = 14.0f;
  expected.matrix[2][1] = -4.0f;
  expected.matrix[2][2] = -8.0f;

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_null_pointer_1) {
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_null_pointer_2) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  ck_assert_int_eq(s21_calc_complements(&a, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_no_square_matrix) {
  matrix_t a, result;
  s21_create_matrix(2, 3, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &result), CALC_ERROR);
  s21_remove_matrix(&a);
}

Suite* calc_suite(void) {
  Suite* suite;
  TCase* tcase_core;
  suite = suite_create("s21_calc_complements_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrix_1x1);
  tcase_add_test(tcase_core, test_valid_matrix_2x2);
  tcase_add_test(tcase_core, test_valid_matrix_3x3);
  tcase_add_test(tcase_core, test_null_pointer_1);
  tcase_add_test(tcase_core, test_null_pointer_2);
  tcase_add_test(tcase_core, test_no_square_matrix);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
