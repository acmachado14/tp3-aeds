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


//-----Função para encontrar mediana com k=3-----//
int PivoMediana(int n1, int n2,int n3)
{
    int a=n1,b=n2,c=n3;
    int mediana;
    //array sequência de if...else verifica qual valor é menor que um e maior que outro
    if (a<b){
        if (b<c) //a < b && b < c
            mediana=b;
        else{
            if (a<c) //a < c && c <= b
                mediana=c;
            else //c <= a && a < b
                mediana=a;
        }
    }
    else{
        if (c<b) //c < b && b <= a
            mediana=b;
        else {
            if (c<a) //b <= c && c < a
                mediana=c;
            else //b <= a && a <= c
                mediana=a;
        }
    }
    return mediana;
}

//-----Função para encontrar mediana com k=5-----//
int PivoMediana5(int *array, int inicio,int fim)
{
    int n1=array[inicio], rep=(fim+1)/5;
    int n2=array[inicio+rep],n3=array[inicio+(2*rep)],n4=array[inicio+(3*rep)],n5=array[inicio+(4*rep)];
    int vet_aux[5]={n1,n2,n3,n4,n5};
    int med;
    //Usa o Shellsort para ordenar o vetor e escolhe a mediana
    int aux, h=1;
    do h=h*3+1;while(h<5);
    do{
        h=h/3;
        for(int i=h;i<5;i++){
            aux=vet_aux[i];
            int j=i;
            while(vet_aux[j-h]>aux){
                vet_aux[j]=vet_aux[j-h];
                j-=h;
                if(j<h)break;
            }
            vet_aux[j]=aux;
        }
    }while(h!=1);
    med=vet_aux[2];
    return med;
}

void ParticaoMED(int Esq, int Dir,int *i,int *j, int *array,int p)
{
    int pivo,aux;
    *i=Esq,*j=Dir;
    pivo=p;
    do{
        while(pivo>array[*i])
            (*i)++;
        while(pivo<array[*j])
            (*j)--;
        if(*i<=*j){
            aux=array[*i];
            array[*i]=array[*j];
            array[*j]=aux;
            (*i)++;
            (*j)--;
        }
    }
    while(*i<=*j);
}

void MedianaDeTres(int Esq, int Dir,int *array)
{
    int i,j,meio=Dir/2;
    int p=PivoMediana(array[Esq],array[meio],array[Dir]);
    ParticaoMED(Esq,Dir,&i,&j,array,p);
    if(Esq<j)
        MedianaDeTres(Esq,j,array);
    if(i<Dir)
        MedianaDeTres(i,Dir,array);
}

void MedianaDeCinco(int Esq, int Dir,int *array)
{
    int i,j;
    int p=PivoMediana5(array,Esq,Dir);
    ParticaoMED(Esq,Dir,&i,&j,array,p);
    if(Esq<j){
        MedianaDeTres(Esq,j,array);
    }
    if(i<Dir){
        MedianaDeTres(i,Dir,array);
    }
}