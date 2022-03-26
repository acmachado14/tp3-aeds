#include "quickSortsAlgoritmos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void randonArray(int array[], int tamanho){
    int numero;
    for (int i = 0; i < tamanho; i++){
        numero = (rand() % 100);
        array[i] = numero;
    }
}

double calcularTempo(clock_t t)
{
    double timeUsed;
    clock_t end = clock();
    timeUsed = ((double) (end - t)) / CLOCKS_PER_SEC;
    return timeUsed;
}


int main( int argc, char * argv[] )
{
    int tamanho;
    scanf("%d", &tamanho);

    int numeros[tamanho];

    FILE *fp;
    FILE *fpSaida;
    char* str1 = "../resultados/quicksort";
    char* str3 = "saida_semente1.txt";
    char buffer[50];

    char num[20];

    clock_t t;

    //Itoa nao é aceito em alguns ambientes, caso isso aconteca exclua a linha abaixo
    //e a outra com um * na frente e descomente a debaixo
    itoa(tamanho,num,10);

    strcat(strcpy(buffer, str1), num);

    strcat(buffer, str3);

    fpSaida = fopen(buffer,"w");//*
    //fpSaida = fopen("seItoaNaoFuncionar.txt","w");

    randonArray(numeros,tamanho);

    int copias = 0;
    int comparacoes = 0;
    double tempo;

    randonArray(numeros,tamanho);

    t = clock();
    quicksortRecursivo( numeros, 0, tamanho - 1, &copias, &comparacoes );
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo QuickSort \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);

    t = clock();
    quickSortIterative( numeros, 0, tamanho - 1, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo Iterative \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);

    t = clock();
    quickSortInsertion10( numeros, 0, tamanho - 1, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo Insercao 10 \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);
    t = clock();
    quickSortInsertion100( numeros, 0, tamanho - 1, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo Insercao 100 \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);
    t = clock();
    quicksortMedianaDeTres( numeros, 0, tamanho - 1, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo Mediana de Tres \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);
    t = clock();
    quicksortMedianaDeCinco(0, tamanho -1, numeros, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo Mediana de Cinco \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");

    copias = 0;
    comparacoes = 0;

    randonArray(numeros,tamanho);
    t = clock();
    quickSortEmpilha( numeros, 0, tamanho - 1, &copias, &comparacoes);
    tempo = calcularTempo(t);

    fprintf(fpSaida, "Algoritmo QuickSort Empilha \n");
    fprintf(fpSaida, "Tempo de Execucao: %f Numero de Copias: %d Numero de Comparacoes: %d \n", tempo, copias, comparacoes);
    fprintf(fpSaida, "--------------------------------------------------------------------------------------------------\n");
    fclose(fpSaida);
    return 0;
}
