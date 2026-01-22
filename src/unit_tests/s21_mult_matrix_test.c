#include "s21_tests.h"

START_TEST(test_valid_matrixes) {
  matrix_t a, b, result, expected;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 2, &b);
  int num1 = 1;
  int num2 = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = num1++;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      b.matrix[i][j] = num2++;
    }
  }
  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 22;
  expected.matrix[0][1] = 28;
  expected.matrix[1][0] = 49;
  expected.matrix[1][1] = 64;
  expected.matrix[2][0] = 76;
  expected.matrix[2][1] = 100;
  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_null_pointer_1) {
  matrix_t a, b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  ck_assert_int_eq(s21_mult_matrix(&a, &b, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_null_pointer_2) {
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

Suite *mult_matrix_suite(void) {
  Suite *suite;
  TCase *tcase_core;
  suite = suite_create("s21_mult_matrix_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrixes);
  tcase_add_test(tcase_core, test_null_pointer_1);
  tcase_add_test(tcase_core, test_null_pointer_2);
  suite_add_tcase(suite, tcase_core);
  return suite;
}