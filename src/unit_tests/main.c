#include "s21_tests.h"

int main() {
  int number_failed = 0;
  SRunner* create_suite_runner = srunner_create(create_remove_suite());
  SRunner* sum_suite_runner = srunner_create(sum_suite());
  SRunner* sub_suite_runner = srunner_create(sub_suite());
  SRunner* mult_num_suite_runner = srunner_create(mult_num_suite());
  SRunner* eq_suite_runner = srunner_create(equal_suite());
  SRunner* mult_matrix_suite_runner = srunner_create(mult_matrix_suite());
  SRunner* transpose_suite_runner = srunner_create(transpose_suite());
  SRunner* determinant_suite_runner = srunner_create(det_suite());
  SRunner* calc_suite_runner = srunner_create(calc_suite());
  SRunner* inverse_suite_runner = srunner_create(inverse_suite());

  srunner_run_all(create_suite_runner, CK_NORMAL);
  srunner_run_all(sum_suite_runner, CK_NORMAL);
  srunner_run_all(sub_suite_runner, CK_NORMAL);
  srunner_run_all(mult_num_suite_runner, CK_NORMAL);
  srunner_run_all(eq_suite_runner, CK_NORMAL);
  srunner_run_all(mult_matrix_suite_runner, CK_NORMAL);
  srunner_run_all(transpose_suite_runner, CK_NORMAL);
  srunner_run_all(determinant_suite_runner, CK_NORMAL);
  srunner_run_all(calc_suite_runner, CK_NORMAL);
  srunner_run_all(inverse_suite_runner, CK_NORMAL);

  number_failed += srunner_ntests_failed(create_suite_runner);
  number_failed += srunner_ntests_failed(sum_suite_runner);
  number_failed += srunner_ntests_failed(sub_suite_runner);
  number_failed += srunner_ntests_failed(mult_num_suite_runner);
  number_failed += srunner_ntests_failed(eq_suite_runner);
  number_failed += srunner_ntests_failed(mult_matrix_suite_runner);
  number_failed += srunner_ntests_failed(transpose_suite_runner);
  number_failed += srunner_ntests_failed(determinant_suite_runner);
  number_failed += srunner_ntests_failed(calc_suite_runner);
  number_failed += srunner_ntests_failed(inverse_suite_runner);
  srunner_free(create_suite_runner);
  srunner_free(sum_suite_runner);
  srunner_free(sub_suite_runner);
  srunner_free(mult_num_suite_runner);
  srunner_free(eq_suite_runner);
  srunner_free(mult_matrix_suite_runner);
  srunner_free(transpose_suite_runner);
  srunner_free(determinant_suite_runner);
  srunner_free(calc_suite_runner);
  srunner_free(inverse_suite_runner);
  return (number_failed == 0) ? 0 : 1;
}