#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 200000
#define NUM_ALEAT 1000000

// Algoritmo que utiliza a estrat�gia do quick sort para ordenar o vetor.
void quick_sort(int *v, int tamanho)
{
    int pivo;
    int inicio;
    int fim;
    if(tamanho<=1)
        return;
    else{
        pivo = v[0];
        inicio = 1;
        fim = tamanho - 1;
    do{
        //percorre vetor da esquerda para direira at� encontrar elemento maior que o piv�
        while(inicio < tamanho && v[inicio] <= pivo) inicio++;
        //Percorre vetor da direita para esquerda at� encontrar elemento menor que o piv�
        while(v[fim] > pivo) fim--;
        if(inicio < fim){
            int temp = v[inicio];
            v[inicio] = v[fim];
            v[fim] = temp;
            inicio++;
            fim--;
        }
    }while (inicio < fim);

    //troca piv�
    v[0] = v[fim];
    v[fim] = pivo;

    //chamadas recursivas da fun��o
    quick_sort(v, fim);
    quick_sort(&v[inicio], tamanho - inicio);
    }
}

// Fun��o que cria os valores de modo aleat�rio para o vetor que deseja-se ordenar
void monta_vetor(int *v) {
    int i;
    srand(123);
    for (i=0; i<TAM; i++)
        v[i] = rand()%(NUM_ALEAT+1);
}

// Fun��o que imprime os valores do vetor
void imprimir_vetor(int *v, char *msg) {
    int i;
    printf("*********** %s ***********\n", msg);
    for (i=0; i<TAM; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    clock_t inicio, fim;
    double diferenca;
    int vetor[TAM];
    monta_vetor(vetor);
    //imprimir_vetor(vetor, "VETOR DESORDENADO");
    inicio = clock();
    quick_sort(vetor, TAM);
    fim = clock();
    diferenca = fim - inicio;
    printf("Tempo em ms: %10.4f\n", diferenca/(CLOCKS_PER_SEC/1000));
    //imprimir_vetor(vetor, "VETOR ORDENADO");
    return 0;
}
