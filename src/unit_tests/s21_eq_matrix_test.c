#include "s21_tests.h"

START_TEST(test_valid_matrixes) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = 1.23;
  a.matrix[1][0] = 53.2;
  a.matrix[1][1] = 4.2;
  b.matrix[0][0] = 1.0;
  b.matrix[0][1] = 1.23;
  b.matrix[1][0] = 53.2;
  b.matrix[1][1] = 4.2;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_valid_matrixes_1) {
  matrix_t a, b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = 1.23;
  a.matrix[1][0] = 53.2;
  a.matrix[1][1] = 4.2;
  b.matrix[0][0] = 2.423;
  b.matrix[0][1] = 1.23;
  b.matrix[1][0] = 53.2;
  b.matrix[1][1] = 4.2;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_null_pointers) {
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);
}
END_TEST

START_TEST(test_diff_sizes) {
  matrix_t a, b;
  s21_create_matrix(1, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = 1.23;
  b.matrix[0][0] = 2.423;
  b.matrix[0][1] = 1.23;
  b.matrix[1][0] = 53.2;
  b.matrix[1][1] = 4.2;
  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST
Suite *equal_suite(void) {
  Suite *suite;
  TCase *tcase_core;
  suite = suite_create("s21_eq_matrix.c");
  tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_valid_matrixes);
  tcase_add_test(tcase_core, test_valid_matrixes_1);
  tcase_add_test(tcase_core, test_null_pointers);
  tcase_add_test(tcase_core, test_diff_sizes);
  suite_add_tcase(suite, tcase_core);
  return suite;
}