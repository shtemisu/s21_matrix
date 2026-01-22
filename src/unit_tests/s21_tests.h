#ifndef S21_TESTS_H
#define S21_TESTS_H
#include <check.h>
#include "../s21_matrix.h"
Suite* create_remove_suite(void);
Suite* mult_num_suite(void);
Suite* mult_matrix_suite(void);
Suite* sum_suite(void);
Suite* sub_suite(void);
Suite* det_suite(void);
Suite* calc_suite(void);
Suite* inverse_suite(void);
Suite* transpose_suite(void);
Suite* equal_suite(void);

#endif