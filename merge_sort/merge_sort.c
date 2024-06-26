#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 200000
#define NUM_ALEAT 10000

// Algoritmo que utiliza a estratégia do merge para ordenar o vetor.
void merge(int A[], int p, int q, int r) {
  int i,j,k,n1,n2;
  n1 = q - p + 1;
  n2 = r - q;

  int L[n1+1];
  int R[n2+1];

  for (i=0; i<n1; i++)
    L[i] = A[p+i];

  for (j=0; j<n2; j++)
    R[j] = A[q+j+1];

  L[n1] = 999999;
  R[n2] = 999999;

  i = 0; j = 0;
  for (k=p; k<=r; k++) {
    if (L[i] <= R[j]) {
        A[k] = L[i];
        i++;
    }
    else {
        A[k] = R[j];
        j++;
    }
  }
}

// Função que faz as chamadas recursivas para a função merge_sort e aplica a função merge quando necessário
void merge_sort(int A[], int p, int r) {
  int q;
  q = (p+r)/2;
  if (p < r) {
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    merge(A,p,q,r);
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
    //escreve_vetor(A, "VETOR DESORDENADO");
    inicio = clock();
    merge_sort(A, 0, TAMANHO-1);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f\n", diferenca/(CLOCKS_PER_SEC/1000));
    //escreve_vetor(A, "VETOR ORDENADO");
}
