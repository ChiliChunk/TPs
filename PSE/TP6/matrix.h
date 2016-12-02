#ifndef _MATRIX_H_
#define _MATRIX_H_


typedef struct SquareMatrix {
    int size;
    double * elements;
} SquareMatrix;

#define M_ELEMENT(m,i,j) (m).elements[(i * (m).size) + j]


/*
 Saisie d'une matrice carree au stdin.
 Le tableau matrix->elements sera alloue dynamiquement (malloc) par cette fonction.
 */
void input_square_matrix(SquareMatrix * matrix);


/*
 Calcule le carre d'une matrice.
 Le tableau result->elements sera alloué dynamiquement (malloc) par cette fonction.
 */
void square_a_square_matrix(SquareMatrix matrix, SquareMatrix* result);


/*
 Affiche une matrice carree au stdout.
 */
void print_square_matrix(SquareMatrix matrix);


/*
 Libère matrix->elements.
 */
void free_square_matrix(SquareMatrix * matrix);


/*
 Copie une matrice (matrix) dans une zone contigue de memoire à l'adresse addr.
 La structure SquareMatrix sera stockee a l'adresse addr, et les elements de la matrice 
 seront stockes a partir de l'adresse qui suit (addr+1).
 */
void pack_matrix(SquareMatrix matrix, SquareMatrix* addr);


/*
 Reinitialise le pointeur elements d'une matrice stockee dans une zone contigue 
 de memoire à l'adresse addr. Ceci est necessaire lorsque la matrice est ecrite dans 
 un espace d'adresses et elle est lue dans un autre  (exercice 6.2). Dans ce cas le
 pointeur initial n'est plus valide.
 */
void unpack_matrix(SquareMatrix* addr);

#endif


















