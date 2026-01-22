#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = OK;

  if (result == NULL) return NOT_VALID_MATRIX;
  if (columns <= 0) return NOT_VALID_MATRIX;
  if (rows <= 0) return NOT_VALID_MATRIX;

  result->matrix = (double **)malloc(rows * sizeof(double *));
  result->columns = columns;
  result->rows = rows;
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = 0.0f;
    }
  }
  return error_code;
}
