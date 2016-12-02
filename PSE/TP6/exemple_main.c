#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main() {
    SquareMatrix A, A2;

    input_square_matrix(&A);
    square_a_square_matrix(A, &A2);
    printf("The square is: \n");
    print_square_matrix(A2);

    free_square_matrix(&A);
    free_square_matrix(&A2);
    
    return 0;
}



















