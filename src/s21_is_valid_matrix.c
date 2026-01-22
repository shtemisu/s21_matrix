#include "s21_matrix.h"
int s21_is_valid_matrix(matrix_t *A) {
  if (A == NULL) return NOT_VALID_MATRIX;
  if (A->matrix == NULL) return NOT_VALID_MATRIX;
  if (A->rows <= 0) return NOT_VALID_MATRIX;
  if (A->columns <= 0) return NOT_VALID_MATRIX;

  return OK;
}