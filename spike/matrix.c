#include "matrix.h"

#define SEPARATOR printf("\n")
#define GREEN_START printf("\033[0;32m")
#define GREEN_END printf("\033[0m")
struct Matrix
{
    size_t rows;
    size_t columns;
    int **matrix;
};

bool is_valid_matrix(matrix__t *matrix)
{
    bool isValid = false;
    if (
        NULL != matrix &&
        matrix->rows > 0 &&
        matrix->columns > 0 &&
        NULL != matrix->matrix)
    {
        isValid = true;
    }
    return isValid;
}

void fill_matrix(matrix__t *matrix)
{
    const unsigned int min = 1;
    const unsigned int max = 100;

    srand(time(NULL));

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            matrix->matrix[i][j] = (rand() % (max - min + 1) + min);
        }
    }
}

matrix__t *get_matrix(const size_t rows, const size_t columns)
{
    assert(rows > 0 && columns > 0);
    matrix__t *matrix = (matrix__t *)malloc(sizeof(matrix__t));
    if (NULL != matrix)
    {
        matrix->rows = rows;
        matrix->columns = columns;
        matrix->matrix = calloc(rows, sizeof(int *));
        for (size_t i = 0; i < rows; i++)
        {
            matrix->matrix[i] = calloc(columns, sizeof(int));
        }
    }
    return matrix;
}

void display_matrix(matrix__t *matrix)
{
    if (NULL != matrix)
    {
        for (size_t i = 0; i < matrix->rows; i++)
        {
            printf("row-%lu:\t|\t", (i + 1));
            for (size_t j = 0; j < matrix->columns; j++)
            {
                printf("%d\t", matrix->matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void destroy_matrix(matrix__t *matrix)
{
    if (NULL != matrix)
    {
        for (size_t i = 0; i < matrix->rows; i++)
        {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
        free(matrix);
    }
}

matrix__t *matrix_transpose(matrix__t *matrix)
{
    matrix__t *mat = NULL;
    if (NULL != matrix)
    {
        mat = get_matrix(matrix->columns, matrix->rows);

        for (size_t i = 0; i < mat->rows; i++)
        {
            for (size_t j = 0; j < mat->columns; j++)
            {
                mat->matrix[i][j] = matrix->matrix[j][i];
            }
        }
    }
    return mat;
}

matrix__t *sum_matrix(matrix__t *matrix1, matrix__t *matrix2)
{
    matrix__t *matrix3 = NULL;
    if (is_valid_matrix(matrix1) && is_valid_matrix(matrix2) && (matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns))
    {
        matrix3 = get_matrix(matrix1->rows, matrix1->columns);
        if (NULL != matrix3)
        {
            for (size_t i = 0; i < matrix3->rows; i++)
            {
                for (size_t j = 0; j < matrix3->columns; j++)
                {
                    matrix3->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
                }
            }
        }
    }
    return matrix3;
}

matrix__t *difference_matrix(matrix__t *matrix1, matrix__t *matrix2)
{
    matrix__t *matrix3 = NULL;
    if (is_valid_matrix(matrix1) && is_valid_matrix(matrix2) && (matrix1->rows == matrix2->rows && matrix1->columns == matrix2->columns))
    {
        matrix3 = get_matrix(matrix1->rows, matrix1->columns);
        if (NULL != matrix3)
        {
            for (size_t i = 0; i < matrix3->rows; i++)
            {
                for (size_t j = 0; j < matrix3->columns; j++)
                {
                    matrix3->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
                }
            }
        }
    }
    return matrix3;
}

matrix__t *multiply_matrix(matrix__t *matrix1, matrix__t *matrix2)
{
    matrix__t *result = NULL;
    if(is_valid_matrix(matrix1) && is_valid_matrix(matrix2) && matrix1->columns == matrix2->rows)
    {
        result = get_matrix(matrix1->rows, matrix2->columns);
        if(NULL != result)
        {
            for(size_t i = 0; i < result->rows; i++)
            {
                for(size_t j = 0; j < result->columns; j++)
                {
                    result->matrix[i][j] = 0;
                    for(size_t k = 0; k < result->columns; k++)
                    {
                        result->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
                    }
                }
            }
        }
    }
    return result;
}
/*
int main(int argc, char **argv)
{
    // matrix__t *matrix1 = get_matrix(3, 3);
    // fill_matrix(matrix1);
    // display_matrix(matrix1);
    // SEPARATOR;
    // // matrix__t *transpose = matrix_transpose(matrix1);
    // // display_matrix(transpose);
    // // SEPARATOR;
    // sleep(1);
    // matrix__t *matrix2 = get_matrix(3, 3);
    // fill_matrix(matrix2);
    // display_matrix(matrix2);
    // SEPARATOR;

    // matrix__t *matrix3 = sum_matrix(matrix1, matrix2);
    // display_matrix(matrix3);
    // SEPARATOR;

    // matrix__t *matrix4 = difference_matrix(matrix1, matrix2);
    // display_matrix(matrix4);
    // SEPARATOR;

    // destroy_matrix(matrix1);
    // destroy_matrix(matrix2);
    // destroy_matrix(matrix3);
    // destroy_matrix(matrix4);
    // //destroy_matrix(transpose);
    // matrix__t *matrix = get_matrix(1000, 1000);
    // if (NULL != matrix)
    // {
    //     fill_matrix(matrix);
    //     GREEN_START;
    //     display_matrix(matrix);
    //     GREEN_END;
    //     destroy_matrix(matrix);
    // }

    matrix__t *matrix1 = get_matrix(3, 3);
    fill_matrix(matrix1);
    display_matrix(matrix1);
    SEPARATOR;
    sleep(1);
    matrix__t *matrix2 = get_matrix(3, 3);
    fill_matrix(matrix2);
    display_matrix(matrix2);
    SEPARATOR;
    sleep(1);
    matrix__t * matrix3 = multiply_matrix(matrix1, matrix2);
    display_matrix(matrix3);
    SEPARATOR;
    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    destroy_matrix(matrix3);
    return 0;
}
*/