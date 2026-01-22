#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_is_valid_matrix(A) == NOT_VALID_MATRIX) return NOT_VALID_MATRIX;
  if (result == NULL) return NOT_VALID_MATRIX;

  if (A->rows != A->columns) return CALC_ERROR;

  double det = 0.0f;
  int error_code = OK;
  error_code = s21_determinant(A, &det);
  if (error_code != OK) {
    error_code = CALC_ERROR;
  } else if (det != 0) {
    matrix_t minor_matrix;
    matrix_t transpose_minor_matrix;
    s21_calc_complements(A, &minor_matrix);
    s21_transpose(&minor_matrix, &transpose_minor_matrix);
    s21_remove_matrix(&minor_matrix);
    s21_mult_number(&transpose_minor_matrix, 1.0 / det, result);
    s21_remove_matrix(&transpose_minor_matrix);
  } else {
    error_code = CALC_ERROR;
  }
  return error_code;
}