#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quickSortsAlgoritmos.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksortRecursivo( int array[], int start, int end )
{
    if( start < end ){
        int l = start + 1;
        int r = end;
        int p = array[start];
        while( l < r ){
            if( array[l] <= p ){
                l++;
            }else if( array[r] >= p ){
                r--;
            }else{
                swap( &array[l], &array[r] );
            }
        }
        if( array[l] < p ){
            swap( &array[l], &array[start] );
            l--;
        }else{
            l--;
            swap( &array[l], &array[start] );
        }
        quicksortRecursivo( array, start, l );
        quicksortRecursivo( array, r, end );
    }
}

void exibir( int array[], int tam )
{
    int i = 0;
    for( i = 0; i < tam; i++ ){
        printf( "%s%d", (i>0)?", ":"", array[i] );
    }
    printf("\n");
}

int partition(int array[], int l, int h)
{
    int x = array[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (array[j] <= x) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[h]);
    return (i + 1);
}


void quickSortIterative(int array[], int l, int h)
{
    int k = h - l + 1;
    int stack[k];

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(array, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}



void insertionSort(int array[], int low, int n)
{
    for(int i=low+1;i<n+1;i++){
        int val = array[i] ;
        int j = i ;
        while (j>low && array[j-1]>val){
            array[j]= array[j-1] ;
            j-= 1;
        }
        array[j]= val ;
    }
}


void quickSortInsertion(int array[], int low, int high)
{
    while (low < high){
        if (high-low + 1 < 10){
            insertionSort(array, low, high);
            break;
        }else{
            int pivot = partition(array, low, high) ;

            if (pivot-low<high-pivot){
                quickSortInsertion(array, low, pivot - 1);
                low = pivot + 1;
            }
            else{
                quickSortInsertion(array, pivot + 1, high);
                high = pivot-1;
            }
        }
    }
}


int partitionDeTres(int array[], int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    int a = array[inicio];
    int b = array[meio];
    int c = array[fim];
    int medianaIndice; //índice da mediana
    //array sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(&array[medianaIndice], &array[fim]);

    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = array[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (array[j] <= pivo) {
            i = i + 1;
            swap(&array[i], &array[j]);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(&array[i], &array[fim]);
    return i + 1; //retorna a posição do pivô
}


void quicksortMedianaDeTres(int array[], int inicio, int fim)
{
    if (inicio < fim) {

        int q = partitionDeTres(array, inicio, fim);

        quicksortMedianaDeTres(array, inicio, q - 1);

        quicksortMedianaDeTres(array, q + 1, fim);
    }
}