#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 1000
#define NUM_ALEAT 1000

// Algoritmo que utiliza a estratégia do selection sort para ordenar o vetor.
void selection_sort(int A[]) {
     int i, j, menor, aux;
     for (i=0; i< TAMANHO; i++) {
          menor  = i;
          for (j=i+1; j< TAMANHO; j++) {
            if (A[j] < A[menor])
              menor = j;
          }
          aux = A[menor];
          A[menor] = A[i];
          A[i] = aux;
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
    selection_sort(A);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f", diferenca/(CLOCKS_PER_SEC/1000));
    escreve_vetor(A, "VETOR ORDENADO");
}
