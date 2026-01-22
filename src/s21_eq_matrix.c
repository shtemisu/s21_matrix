#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_is_valid_matrix(A) == NOT_VALID_MATRIX ||
      s21_is_valid_matrix(B) == NOT_VALID_MATRIX) {
    return FAILURE;
  }
  int error_code = SUCCESS;
  if (A->columns == B->columns && A->rows == B->rows) {
    int flag = 0;
    for (int i = 0; i < A->rows; i++) {
      if (flag) break;
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          flag = 1;
          error_code = FAILURE;
          break;
        }
      }
    }
  } else {
    error_code = FAILURE;
  }
  return error_code;
}