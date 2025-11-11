#include "matrix.h"


struct Matrix
{
    size_t rows;
    size_t columns;
    int **matrix;
};

void fill_matrix(matrix__t *matrix)
{
    const unsigned int min = 1;
    const unsigned int max = 100;
    
    unsigned int seed = time(0);
    
    for(size_t i = 0; i < matrix->rows; i++)
    {
        for(size_t j = 0; j < matrix->columns; j++)
        {
            matrix->matrix[i][j] = (rand_r(&seed) % (max - min + 1) + min);
        }
    }
}

matrix__t *get_matrix(const size_t rows, const size_t columns)
{
    assert(rows > 0 && columns > 0);
    matrix__t *matrix = (matrix__t *)malloc(sizeof(matrix__t));
    if(NULL != matrix)
    {
        matrix->rows = rows;
        matrix->columns = columns;
        matrix->matrix = calloc(rows, sizeof(int*));
        for(size_t i = 0; i < rows; i++)
        {
            matrix->matrix[i] = calloc(columns, sizeof(int));
        }
    }
    return matrix;
}

void display_matrix(matrix__t *matrix)
{
    if(NULL != matrix)
    {
        for(size_t i = 0; i < matrix->rows; i++)
        {
            printf("row-%lu:\t|\t",(i+1));
            for(size_t j = 0; j < matrix->columns; j++)
            {
                printf("%d\t", matrix->matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void destroy_matrix(matrix__t *matrix)
{
    if(NULL != matrix)
    {
        for(size_t i = 0 ; i < matrix->rows; i++)
        {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
        free(matrix);
    }
}

int main(int argc, char **argv)
{
    matrix__t *matrix = get_matrix(13, 13);
    fill_matrix(matrix);
    display_matrix(matrix);
    destroy_matrix(matrix);
    return 0;
}