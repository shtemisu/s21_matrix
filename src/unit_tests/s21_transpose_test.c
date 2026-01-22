#include "s21_tests.h"

START_TEST(test_valid_matrix) {
  matrix_t a, result, expected;
  s21_create_matrix(2, 3, &a);
  int num1 = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = num1++;
    }
  }

  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[1][0] = 2;
  expected.matrix[2][0] = 3;
  expected.matrix[0][1] = 4;
  expected.matrix[1][1] = 5;
  expected.matrix[2][1] = 6;

  ck_assert_int_eq(s21_transpose(&a, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_null_pointer_1) {
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, &result), NOT_VALID_MATRIX);
}
END_TEST

START_TEST(test_null_pointer_2) {
  matrix_t a;
  s21_create_matrix(3, 2, &a);
  ck_assert_int_eq(s21_transpose(&a, NULL), NOT_VALID_MATRIX);
  s21_remove_matrix(&a);
}
END_TEST

Suite* transpose_suite(void) {
  Suite* suite;
  TCase* tcase_core;
  suite = suite_create("s21_transpose_test");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrix);
  tcase_add_test(tcase_core, test_null_pointer_1);
  tcase_add_test(tcase_core, test_null_pointer_2);
  suite_add_tcase(suite, tcase_core);
  return suite;
}