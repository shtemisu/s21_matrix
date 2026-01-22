#include "s21_tests.h"

START_TEST(test_valid_matrix_2x2_size) {
  double result = 0.0f;
  matrix_t a;
  int num1 = 1;
  s21_create_matrix(2, 2, &a);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = num1++;
    }
  }
  ck_assert_int_eq(s21_determinant(&a, &result), OK);
  ck_assert_double_eq_tol(result, -2.0f, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_valid_matrix_1x1_size) {
  double result = 0.0f;
  matrix_t a;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 23;
  ck_assert_int_eq(s21_determinant(&a, &result), OK);
  ck_assert_double_eq_tol(result, 23.0f, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_valid_matrix_1x2_size) {
  double result = 0.0f;
  matrix_t a;
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_determinant(&a, &result), CALC_ERROR);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_valid_matrix_3x3_size) {
  double result = 0.0f;
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 4;
  a.matrix[0][2] = 6;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = 11;
  a.matrix[1][2] = 12;
  a.matrix[2][0] = 14;
  a.matrix[2][1] = 16;
  a.matrix[2][2] = 18;
  ck_assert_int_eq(s21_determinant(&a, &result), OK);
  ck_assert_double_eq_tol(result, -48.0f, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST
START_TEST(test_valid_matrix_4x4_size) {
  double result = 0.0f;
  matrix_t a;
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 2;
  a.matrix[0][1] = 4;
  a.matrix[0][2] = 6;
  a.matrix[0][3] = 1;
  a.matrix[1][0] = 8;
  a.matrix[1][1] = 11;
  a.matrix[1][2] = 12;
  a.matrix[1][3] = 2;
  a.matrix[2][0] = 14;
  a.matrix[2][1] = 16;
  a.matrix[2][2] = 18;
  a.matrix[2][3] = 3;
  a.matrix[3][0] = 6;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 9;
  a.matrix[3][3] = 4;
  ck_assert_int_eq(s21_determinant(&a, &result), OK);
  ck_assert_double_eq_tol(result, -120.0f, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(test_null_pointer_1) {
  double result = 0.0f;
  ck_assert_int_eq(s21_determinant(NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_null_pointer_2) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  ck_assert_int_eq(s21_determinant(&a, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST
Suite* det_suite(void) {
  Suite* suite;
  TCase* tcase_core;
  suite = suite_create("s21_determinant_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrix_2x2_size);
  tcase_add_test(tcase_core, test_valid_matrix_1x1_size);
  tcase_add_test(tcase_core, test_valid_matrix_1x2_size);
  tcase_add_test(tcase_core, test_valid_matrix_3x3_size);
  tcase_add_test(tcase_core, test_valid_matrix_4x4_size);
  tcase_add_test(tcase_core, test_null_pointer_1);
  tcase_add_test(tcase_core, test_null_pointer_2);
  suite_add_tcase(suite, tcase_core);
  return suite;
}