#pragma once

#include "common.h"


typedef struct Matrix matrix__t;

bool is_valid_matrix(matrix__t *matrix);
matrix__t* get_matrix(const size_t rows, const size_t columns);
void fill_matrix(matrix__t *matrix);
void display_matrix(matrix__t *matrix);
void destroy_matrix(matrix__t *matrix);
matrix__t* matrix_transpose(matrix__t* matrix);
matrix__t* sum_matrix(matrix__t *matrix1, matrix__t *matrix2);
matrix__t* difference_matrix(matrix__t *matrix1, matrix__t *matrix2);
matrix__t* multiply_matrix(matrix__t *matrix1, matrix__t *matrix2);