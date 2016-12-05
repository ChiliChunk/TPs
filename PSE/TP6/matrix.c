#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include <pthread.h>

void input_square_matrix(SquareMatrix * matrix) {
    char flush[1024];
    int i;

    printf("Enter the matrix size:\n");
    while(scanf("%d", & matrix->size)<1) {
            printf("retry with a number\n");
            /* flush input */
            scanf("%s",flush);
    }

    // alouer la matrice
    matrix->elements = (double*)malloc(matrix->size * matrix->size * sizeof(double));

    printf("Enter the matrix row by row:\n");
    for(i = 0; i<matrix->size * matrix->size; i++) {
        if(scanf("%lf", matrix->elements + i)<1) {
            printf("retry with a number\n");
            i--;
            /* flush input */
            scanf("%s",flush);
        }
    }
}

void square_a_square_matrix(SquareMatrix matrix, SquareMatrix* result) {
    result->elements = (double*)malloc(matrix.size * matrix.size * sizeof(double));
    result->size = matrix.size;
    int row, col, i;


    for(row = 0; row<matrix.size; row++)
        for(col = 0; col<matrix.size; col++) {
            // calculer l'element (row,col)
            M_ELEMENT(*result,row,col) = 0;
            for(i = 0; i<matrix.size; i++)
                M_ELEMENT(*result,row,col) += M_ELEMENT(matrix,row,i)*M_ELEMENT(matrix, i, col);
        }

}

void print_square_matrix(SquareMatrix matrix) {
    int row, col;

    for(row = 0; row<matrix.size; row++) {
        for(col = 0; col<matrix.size; col++) {
            printf("%8lf ", M_ELEMENT(matrix,row,col));
        }
        printf("\n");
    }
    fflush(stdout);
}

void free_square_matrix(SquareMatrix * matrix) {
    if(matrix->elements) {
        free(matrix->elements);
        matrix->elements = NULL;
    }
}

void pack_matrix(SquareMatrix matrix, SquareMatrix* addr) {

    addr->size = matrix.size;
    addr->elements = (double*) (addr+1);  // pointer to the next memory cell after the struct.
    memcpy(addr->elements, matrix.elements, matrix.size*matrix.size*sizeof(double));
}

void unpack_matrix(SquareMatrix* addr) {
    // Re-initialize it to point to the next memory cell after the struct.
    addr->elements = (double*) (addr+1);
}
