#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//realiza a troca
void swap(int* a, int* b);

//quicksortRecursivo
void quicksortRecursivo( int array[], int start, int end );

//exibe o array
void exibir( int array[], int tam );

//QuickSortIterative
void quickSortIterative(int array[], int l, int h);

//Realiza a particao
int partition(int array[], int l, int h);

//Orenacao com insercao
void insertionSort(int array[], int low, int n);

//QuickSort com insercao
void quickSortInsertion(int array[], int low, int high);

//QuickSort com Mediana
void quicksortMedianaDeTres(int array[], int inicio, int fim);

//Particao para quick Sort Mediana de Tres
int partitionDeTres(int array[], int inicio, int fim);