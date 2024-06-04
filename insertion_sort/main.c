#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 200
#define NUM_ALEAT 1000000

// Algoritmo que utiliza a estratégia do insertion sort para ordenar o vetor.
void insertion_sort(int A[]) {
    int i,j,key;
    for (j=1; j<TAMANHO; j++) {
      key = A[j];
      i = j-1;
      while (i >= 0 && A[i] > key) {
        A[i+1] = A[i];
        i = i-1;
      }
      A[i+1] = key;
    }
}

// Função que cria os valores de modo aleatório para o vetor que deseja-se ordenar
void monta_vetor(int A[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<TAMANHO; i++)
        A[i] = rand()%(NUM_ALEAT+1);
}

// Função que imprime os valores do vetor
void escreve_vetor(int A[], char *msg) {
    int i;
    printf("*********** %s ***********\n", msg);
    for (i=0; i<TAMANHO; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main () {
    clock_t inicio, fim;
    double diferenca;
    int A[TAMANHO];
    monta_vetor(A);
    escreve_vetor(A, "VETOR DESORDENADO");
    inicio = clock();
    insertion_sort(A);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    escreve_vetor(A, "VETOR ORDENADO");
}
