#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10
#define NUM_ALEAT 1000000

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

// Algoritmo que utiliza a estratégia do bubble sort para ordenar o vetor.
void bubble_sort(int A[]) {
    int i,j,aux,flag;
    for (i=1; i < TAMANHO; i++) {
       flag = 0;
       for (j=0; j< TAMANHO-i;j++) {
          if (A[j]>A[j+1]) {
             aux = A[j];
             A[j] = A[j+1];
             A[j+1] = aux;
             flag = 1;
          }
       }
       if (!flag) return;
   }
}

int main () {
    int A[TAMANHO] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(A);
    escreve_vetor(A, "VETOR ORDENADO");
}
