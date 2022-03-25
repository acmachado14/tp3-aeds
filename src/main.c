#include "quickSortsAlgoritmos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void randonArray(int array[], int tamanho){
    int numero;
    for (int i = 0; i < tamanho; i++){
        numero = (rand() % 1000);
        array[i] = numero;
    }
}

void tempo(clock_t t)
{
    double timeUsed;
    clock_t end = clock();
    timeUsed = ((double) (end - t)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f \n", timeUsed);
    puts("----------------------------------------------------------------------------------");
}

int main( int argc, char * argv[] )
{
    int tamanho;
    scanf("%d", &tamanho);

    int numeros[tamanho];

    clock_t t;

    randonArray(numeros,tamanho);
    printf("Array Desordenado: \n");
    //exibir( numeros, tamanho );

    t = clock();
    int copias = 0;
    int comparacoes = 0;

    randonArray(numeros,tamanho);
    printf("Array QuickSort: \n");
    quicksortRecursivo( numeros, 0, tamanho - 1, &copias, &comparacoes );
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);

    copias = 0;
    comparacoes = 0;

    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Iterativo: \n");
    quickSortIterative( numeros, 0, tamanho - 1, &copias, &comparacoes);
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);

    copias = 0;
    comparacoes = 0;
    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Insercao 10: \n");
    quickSortInsertion10( numeros, 0, tamanho - 1, &copias, &comparacoes);
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);

    copias = 0;
    comparacoes = 0;

    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Insercao 100: \n");
    quickSortInsertion100( numeros, 0, tamanho - 1, &copias, &comparacoes);
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);

    copias = 0;
    comparacoes = 0;
    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Mediana de Tres: \n");
    quicksortMedianaDeTres( numeros, 0, tamanho - 1, &copias, &comparacoes);
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);


    copias = 0;
    comparacoes = 0;
    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Mediana de Cinco: \n");
    MedianaDeCinco(0, tamanho -1, numeros);
    //exibir( numeros, tamanho );
    tempo(t);
    return 0;


    copias = 0;
    comparacoes = 0;
    t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Empilha: \n");
    quickSortEmpilha( numeros, 0, tamanho - 1, &copias, &comparacoes);
    //exibir( numeros, tamanho );
    printf("Numero de copias: %d \n", copias);
    printf("Numero de comparacoes: %d \n", comparacoes);
    tempo(t);

    /*t = clock();
    randonArray(numeros,tamanho);
    printf("Array QuickSort Mediana Teste: \n");
    quickSortMedianaTeste( numeros, 0, tamanho - 1, 0, 0);
    exibir( numeros, tamanho );
    tempo(t);*/


}
