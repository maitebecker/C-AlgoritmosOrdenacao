# C-AlgoritmosOrdenacao

## *Bubble Sort:*
- Sempre vou olhar para o elemento de indice j e para o elemento de indice j+1. Quero saber se o valor da posição j é maior que o valor da posição j+1, ou seja, se o proxímo elemento é maior que o anterior.

  ``` if (A[j]>A[j+1]) ```
- Caso sim, trocamos esses elementos de lugar, utilizando uma variável auxiliar
  ```
   aux = A[j];
   A[j] = A[j+1];
   A[j+1] = aux;
  ```
- Caso não, incrementamos o indice j e verificamos a posição seguinte
- Realizamos esse passo para todas as posições do vetor. Nessa primeira varredura garantimos que o último elemento é o maior elemento do vetor.
- Não temos como garantir que os outros elementos estão na posição correta, então realizamos esse mesmo processo outras vezes
- Fazemos isso através de outra estrutura de repetição que é realizada até não precisarmos fazer mais nenhuma troca, ou seja, paramos quando o vetor já está ordenado
  ```
  void bubble_sort(int A[]) {
    int i,j,aux;
    for (i=1; i < TAMANHO; i++) {
       for (j=0; j< TAMANHO-i;j++) {
          if (A[j]>A[j+1]) {
             aux = A[j];
             A[j] = A[j+1];
             A[j+1] = aux;
          }
       }
   }
  }
  ```
- Na primeira vez que a estrutura de repetição externa é executada, garantimos que o último elemento está posição correta, na terceira vez o peníltimo e assim em diante...

## *Selection Sort:*
- Nesse algoritmo de ordenação temos uma variável "menor". No incicio da execução, consideramos que a primeira posição do vetor é o menor valor
- Depois testamos se o índice j é menor que a posição da variável menor
   ```
   if (A[j] < A[menor])
       menor = j;
   ```
- Caso for menor, verificamos que a primeira posição não é o menor elemento do vetor e atualizamos o valor da variável para o novo indice
- Continuamos incrementando o valor do índice j e verificamos se essa posição do vetor é menor que o valor do índice da variável menor
  ```
  for (i=0; i< TAMANHO; i++) {
      for (j=i+1; j< TAMANHO; j++) {
        if (A[j] < A[menor])
          menor = j;
      }
  ```
- Quando percorremos todas as posições do vetor, descobrimos o índice do menor elemento do vetor
- Então trocamos o menor valor com o valor que está no índice zero do vetor. Assim garantimos que o menor elemento estará na primeira posição
  ```
   aux = A[menor];
   A[menor] = A[i];
   A[i] = aux;
  ```
- Depois de realizar esses passos, executamos novamente essa estratégia através de um laço de repetição externo
  ```
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
  ```
- Na próxima execução do laço, o valor da variável menor será 1, pois o valor de indice 0 já estará ordenado
- Realizamos esses passos até o vetor estar totalmente ordenado

## *Insertion Sort:*
- Nesse algoritmo temos uma variável key que sempre começa com o valor do indice 1 do vetor.
- Ordenamos o que está a esquerda da variável key
- Depois verificamos qual a posição correta da variável key
- Verificamos se o valor a esquerda é maior que o valor da variável key
- Caso sim, realizamos a troca de valores
- Na proxima varredura do laço de repetição externo o valor da variável key será o indice 2
- Sabendo que o que está a esquerda da variável já esta ordenado, verificamos então novamente qual a posição correta da key
- Realizamos esses passos até o vetor estar totalmente ordenado
```
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
```
