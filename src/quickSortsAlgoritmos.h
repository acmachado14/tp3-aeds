#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//realiza a troca
void swap(int* a, int* b);

//quicksortRecursivo
void quicksortRecursivo( int array[], int start, int end, int *copias, int *comparacoes);

//exibe o array
void exibir( int array[], int tam );

//QuickSortIterative
void quickSortIterative(int array[], int l, int h, int *copias, int *comparacoes);

//Realiza a particao
int partition(int array[], int l, int h, int *copias, int *comparacoes);

//Orenacao com insercao
void insertionSort(int array[], int low, int n, int *copias, int *comparacoes);

//QuickSort com insercao10
void quickSortInsertion10(int array[], int low, int high, int *copias, int *comparacoes);

//QuickSort com insercao100
void quickSortInsertion100(int array[], int low, int high, int *copias, int *comparacoes);

//QuickSort com Mediana
void quicksortMedianaDeTres(int array[], int inicio, int fim, int *copias, int *comparacoes);

//Particao para quick Sort Mediana de Tres
int partitionDeTres(int array[], int inicio, int fim, int *copias, int *comparacoes);

//QuickSort Empilha
void quickSortEmpilha(int array[], int low, int high,int *copias, int *comparacoes);

//Gera vetor com indeces aleatorios
void geraMediana(int Vnumero[], int k, int inicio, int fim);

//Pivo Mediana
int pivoMediana(int n1, int n2,int n3, int *copias, int *comparacoes);

//Particao da Mediana
void particaoMediana(int inicio, int fim,int *i,int *j, int *array,int p, int *copias, int *comparacoes);

//Pivo mediana de 5
int pivoMedianaCinco(int *array, int inicio,int fim,int *copias, int *comparacoes);

//QuickSort Mediana de Cinco
void quicksortMedianaDeCinco(int inicio, int fim,int *array,int *copias, int *comparacoes);