#include "quickSortsAlgoritmos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int main( int argc, char * argv[] )
{
    int numeros[16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, -8, 0 };

    printf("Array Desordenado: \n");
    exibir( numeros, 16 );
    puts("----------------------------------------------------------------------------------");

    printf("Array QuickSort: \n");
    quicksortRecursivo( numeros, 0, 16 );
    exibir( numeros, 16 );
    puts("----------------------------------------------------------------------------------");

    int numeros1[16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, -8, 0 };

    printf("Array QuickSort Iterativo: \n");
    quickSortIterative( numeros1, 0, 16 );
    exibir( numeros1, 16 );
    puts("----------------------------------------------------------------------------------");

    int numeros3[16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, -8, 0 };

    printf("Array QuickSort Insercao: \n");
    quickSortInsertion( numeros3, 0, 16 );
    exibir( numeros3, 15 );
    puts("----------------------------------------------------------------------------------");

    int numeros4[16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, -8, 0 };

    printf("Array QuickSort Mediana de Tres: \n");
    quicksortMedianaDeTres( numeros4, 0, 16 );
    exibir( numeros4, 15 );
    puts("----------------------------------------------------------------------------------");

    return 0;
}
