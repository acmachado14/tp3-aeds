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

void quicksortRecursivo( int array[], int start, int end, int *copias, int *comparacoes)
{
    if( start < end ){
        int l = start + 1;
        int r = end;
        int p = array[start];
        while( l < r ){
            if( array[l] <= p ){
                (*comparacoes)++;
                l++;
            }else if( array[r] >= p ){
                (*comparacoes) +=2 ;
                r--;
            }else{
                swap( &array[l], &array[r] );
                (*copias) += 3;
                (*comparacoes) +=2;
            }
            (*comparacoes)++;
        }
        if( array[l] < p ){
            swap( &array[l], &array[start] );
            (*copias) += 3;
            l--;
        }else{
            l--;
            swap( &array[l], &array[start] );
            (*copias) += 3;
        }
        (*comparacoes)++;

        quicksortRecursivo( array, start, l , copias, comparacoes);
        quicksortRecursivo( array, r, end , copias, comparacoes);
    }
}

void exibir( int array[], int tam )
{
    int i = 0;
    for( i = 0; i < tam; i++ ){
        printf( "%s%d", (i>0)?", ":"", array[i] );
    }
    printf("\n");
    puts("----------------------------------------------------------------------------------");
}

int partition(int array[], int l, int h, int *copias, int *comparacoes)
{
    int x = array[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (array[j] <= x) {
            i++;
            swap(&array[i], &array[j]);
            (*copias) += 3;
        }
        (*comparacoes)++;
    }
    swap(&array[i + 1], &array[h]);
    (*copias) += 3;
    return (i + 1);
}


void quickSortIterative(int array[], int l, int h, int *copias, int *comparacoes)
{
    int k = h - l + 1;
    int stack[k];

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(array, l, h, copias, comparacoes);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }

        (*comparacoes) += 3;
    }
}



void insertionSort(int array[], int low, int n, int *copias, int *comparacoes)
{
    for(int i=low+1;i<n+1;i++){
        int val = array[i] ;
        int j = i ;
        while (j>low && array[j-1]>val){
            array[j]= array[j-1] ;
            j-= 1;
            (*comparacoes)++;
            (*copias)++;
        }
        array[j]= val ;
    }
}


void quickSortInsertion10(int array[], int low, int high, int *copias, int *comparacoes)
{
    while (low < high){
        if (high-low + 1 < 10){
            insertionSort(array, low, high, copias, comparacoes);
            (*comparacoes)++;
            break;
        }else{
            int pivot = partition(array, low, high, copias, comparacoes);

            if (pivot-low<high-pivot){
                quickSortInsertion10(array, low, pivot - 1, copias, comparacoes);
                low = pivot + 1;
            }else{
                quickSortInsertion10(array, pivot + 1, high, copias, comparacoes);
                high = pivot-1;
            }
            (*comparacoes) += 2;
        }

    }
}

void quickSortInsertion100(int array[], int low, int high, int *copias, int *comparacoes)
{
    while (low < high){
        if (high-low + 1 < 100){
            insertionSort(array, low, high, copias, comparacoes);
            (*comparacoes)++;
            break;
        }else{
            int pivot = partition(array, low, high, copias, comparacoes);

            if (pivot-low<high-pivot){
                quickSortInsertion100(array, low, pivot - 1, copias, comparacoes);
                low = pivot + 1;
            }
            else{
                quickSortInsertion100(array, pivot + 1, high, copias, comparacoes);
                high = pivot-1;
            }
            (*comparacoes) += 2;
        }
    }
}


int partitionDeTres(int array[], int inicio, int fim, int *copias, int *comparacoes)
{
    int meio = (inicio + fim) / 2;
    int a = array[inicio];
    int b = array[meio];
    int c = array[fim];
    int medianaIndice;

    (*comparacoes)++;
    if (a < b) {
        (*comparacoes)++;
        if (b < c) {
            medianaIndice = meio;
        } else {
            (*comparacoes)++;
            if (a < c) {
                medianaIndice = fim;
            } else {
                medianaIndice = inicio;
            }
        }
    } else {
        (*comparacoes)++;
        if (c < b) {
            medianaIndice = meio;
        } else {
            (*comparacoes)++;
            if (c < a) {
                medianaIndice = fim;
            } else {
                medianaIndice = inicio;
            }
        }
    }
    swap(&array[medianaIndice], &array[fim]);
    (*copias) += 3;

    int pivo = array[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        (*comparacoes)++;
        if (array[j] <= pivo) {
            i = i + 1;
            swap(&array[i], &array[j]);
            (*copias) += 3;
        }
    }

    swap(&array[i + 1], &array[fim]);
    (*copias) += 3;

    return i + 1;
}
//Quicksort mediana de três
void quicksortMedianaDeTres(int array[], int inicio, int fim, int *copias, int *comparacoes)
{
    if (inicio < fim) {
        //realiza a partição
        int q = partitionDeTres(array, inicio, fim, copias, comparacoes);
        //ordena a partição inicio
        quicksortMedianaDeTres(array, inicio, q - 1, copias, comparacoes);
        //ordena a partição fim
        quicksortMedianaDeTres(array, q + 1, fim, copias, comparacoes);
    }
}


void quickSortEmpilha(int array[], int low, int high, int *copias, int *comparacoes)
{
	while (low < high){
		int pi = partition(array, low, high, copias, comparacoes);

		quickSortEmpilha(array, low, pi - 1, copias, comparacoes);

		low = pi+1;

        (*comparacoes)++;
	}
}




void geraMediana(int Vnumero[], int k, int inicio, int fim){
    int numero;
    int verificador, cont = 0;
    while(cont < k){
        numero = (inicio + (rand() % (fim-inicio)));
        verificador = 0;
        for (int j = 0; j < k; j++){
            if (Vnumero[cont] == numero){
                verificador = 1;
            }
        }
        if (verificador == 0){
            Vnumero[cont] = numero;
            cont++;
        }
    }
}

int partitionDeCinco(int array[], int inicio, int fim) {
    //encontrando a mediana de 5 elementos

    int medianaIndice;
    int indice0 = inicio;
    int indice1 = (fim-inicio)/4;
    int indice2 = (fim-inicio)/2;
    int indice3 = 3*(fim-inicio)/4;
    int indice4 = fim;

    int vetor[5] = {array[indice0], array[indice1], array[indice2], array[indice3], array[indice4]};
    int indices[5] = {indice0, indice1, indice2, indice3, indice4};
    int aux, auxInd;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            if (vetor[j] > vetor[j + 1]) {
                aux= vetor[j];
                vetor[j]= vetor[j + 1];
                vetor[j + 1] = aux;

                auxInd= indices[j];
                indices[j]= indices[j + 1];
                indices[j + 1] = auxInd;
            }
        }
    }

    exibir(vetor,5);
    puts("------------dadasdasdasda****");
    medianaIndice = indices[2];

    swap(&array[medianaIndice], &array[fim]);

    int pivo = array[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        if (array[j] <= pivo) {
            i = i + 1;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[fim]);
    return i + 1;
}



void quicksortMedianaDeCinco(int array[], int inicio, int fim)
{
    if (inicio < fim) {

        int q = partitionDeCinco(array, inicio, fim);

        quicksortMedianaDeCinco(array, inicio, q - 1);

        quicksortMedianaDeCinco(array, q + 1, fim);
    }
}

void quickSortMedianaTeste(int array[], int inicio, int fim, int *copias, int *comparacoes)
{

    int Vnumero[5];
    int mediana;
    geraMediana(Vnumero,5,inicio,fim);

    int indice0 = Vnumero[0];
    int indice1 = Vnumero[1];
    int indice2 = Vnumero[2];
    int indice3 = Vnumero[3];
    int indice4 = Vnumero[4];

    int vetor[5] = {array[indice0], array[indice1], array[indice2], array[indice3], array[indice4]};
    int indices[5] = {indice0, indice1, indice2, indice3, indice4};
    int aux, auxInd;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            if (vetor[j] > vetor[j + 1]) {
                aux= vetor[j];
                vetor[j]= vetor[j + 1];
                vetor[j + 1] = aux;

                auxInd= indices[j];
                indices[j]= indices[j + 1];
                indices[j + 1] = auxInd;
            }
        }
    }
    puts("------------pint INCIO testes-----------------------\n");
    exibir(vetor,5);
    puts("------------pint FIM testes-----------------------\n");
    mediana = indices[2];

    while (inicio <= fim){
        while (array[inicio] < array[mediana] && inicio < fim){
            //(*comparacoes)++;
            inicio++;
        }

        while (array[fim] > array[mediana] && fim > inicio){
            //(*comparacoes)++;
            fim--;
        }

        if (inicio <= fim){
            swap(&array[inicio],&array[fim]);
            copias++;
            inicio++;
            fim--;
        }
    }

    if (fim > inicio){
        quickSortMedianaTeste(array, inicio, fim, copias, comparacoes);
    }

    if (inicio < fim){
        quickSortMedianaTeste(array, inicio, fim, copias, comparacoes);
    }
}
//------------------------------------------------------------------------------------