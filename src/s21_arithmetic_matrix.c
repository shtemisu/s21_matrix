#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_valid_matrix(A) != OK || s21_is_valid_matrix(B) != OK) {
    return NOT_VALID_MATRIX;
  }

  if (A->columns != B->columns || B->rows != A->rows) {
    return CALC_ERROR;
  }
  if (s21_create_matrix(A->rows, B->columns, result) != OK) {
    return NOT_VALID_MATRIX;
  }
  int columns = A->columns, rows = A->rows;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_valid_matrix(A) != OK || s21_is_valid_matrix(B) != OK) {
    return NOT_VALID_MATRIX;
  }

  if (A->columns != B->columns || A->rows != B->rows) return CALC_ERROR;
  if (s21_create_matrix(A->rows, A->columns, result) == NOT_VALID_MATRIX) {
    return NOT_VALID_MATRIX;
  }
  int columns = A->columns, rows = A->rows;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_is_valid_matrix(A) != OK) {
    return NOT_VALID_MATRIX;
  }
  if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return NOT_VALID_MATRIX;
  }
  int columns = A->columns, rows = A->rows;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_valid_matrix(A) != OK || s21_is_valid_matrix(B) != OK) {
    return NOT_VALID_MATRIX;
  }
  if (A->columns != B->rows) return CALC_ERROR;
  if (s21_create_matrix(A->rows, B->columns, result) == NOT_VALID_MATRIX) {
    return NOT_VALID_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_is_valid_matrix(A) == NOT_VALID_MATRIX) return NOT_VALID_MATRIX;
  if (result == NULL) return NOT_VALID_MATRIX;
  int old_columns = A->columns, old_rows = A->rows;
  if (s21_create_matrix(old_columns, old_rows, result) == NOT_VALID_MATRIX) {
    return NOT_VALID_MATRIX;
  }
  for (int i = 0; i < old_rows; i++) {
    for (int j = 0; j < old_columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = OK;
  if (s21_is_valid_matrix(A) == NOT_VALID_MATRIX) return NOT_VALID_MATRIX;
  if (A->rows != A->columns) return CALC_ERROR;
  int rows = A->rows;
  int columns = A->columns;
  if (rows == 1 && columns == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1;
  } else {
    matrix_t minor;
    if (s21_create_matrix(rows, columns, result) == NOT_VALID_MATRIX) {
      error_code = NOT_VALID_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          s21_create_matrix(rows - 1, columns - 1, &minor);
          int mi = 0;
          for (int si = 0; si < rows; si++) {
            if (si == i) continue;
            int mj = 0;
            for (int sj = 0; sj < columns; sj++) {
              if (sj == j) continue;
              minor.matrix[mi][mj] = A->matrix[si][sj];
              mj++;
            }
            mi++;
          }
          double det = 0.0f;
          s21_determinant(&minor, &det);
          result->matrix[i][j] = pow(-1, i + j) * det;
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return error_code;
}

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_valid_matrix(A) == NOT_VALID_MATRIX || result == NULL)
    return NOT_VALID_MATRIX;
  int error_code = OK;
  *result = 0.0f;
  int rows = A->rows, columns = A->columns;
  if (rows != columns) return CALC_ERROR;
  if (rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (rows == 1) {
    *result = A->matrix[0][0];
  } else {
    matrix_t submatrix;
    for (int j = 0; j < columns; j++) {
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &submatrix) ==
          NOT_VALID_MATRIX) {
        error_code = NOT_VALID_MATRIX;
        break;
      }
      for (int i = 1, sub_i = 0; i < rows;
           i++, sub_i++) {  // итерация со второй строки матрицы
        for (int k = 0, sub_k = 0; k < columns; k++) {
          if (k == j) continue;
          submatrix.matrix[sub_i][sub_k++] = A->matrix[i][k];
        }
      }
      double det_submatrix = 0.0f;
      if (s21_determinant(&submatrix, &det_submatrix) != OK) {
        s21_remove_matrix(&submatrix);
        error_code = NOT_VALID_MATRIX;
        break;
      } else {
        *result += A->matrix[0][j] * pow(-1, j) *
                   det_submatrix;  // дополнить формулу разложения Лапласа
      }
      s21_remove_matrix(&submatrix);
    }
  }
  return error_code;
}