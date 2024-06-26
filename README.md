# C-AlgoritmosOrdenacao
Implementação de alguns algoritmos de ordenação na linguagem C

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

## *Quick Sort:*
- O algorimo Quick Sort utiliza o paradigma de programação de dividir para conquistar
- O vetor é particionado em subvetores a partir do elemento pivô
- O elemento pivô pode ser o primeiro elemento do vetor, por exemplo
```
pivo = v[0];
```
- O elemento pivô deve ser posicionado, de tal forma que, os elementos menores que ele sejam
posicionados no lado esquerdo e os elementos maiores que o pivô sejam mantidos do lado
direito
- Utilizamos duas variáveis para percorrer o vetor. A variável início e a variável fim
```
inicio = 1;
fim = tamanho - 1;
```
- Percorremos o vetor da esquerda para direira até encontrar elemento maior que o pivô
```
while(inicio < tamanho && v[inicio] <= pivo) inicio++;
```
- Depois percorremos o vetor da direita para esquerda até encontrar elemento menor que o pivô
```
while(v[fim] > pivo) fim--;
```
- Verificamos se inicio é menor que fim, caso sim trocamos as duas posições
        }
```
if(inicio < fim) {
    int temp = v[inicio];
    v[inicio] = v[fim];
    v[fim] = temp;
    inicio++;
    fim--;
}
```
- Realizamos esses passos até o incio ser maior que o fim, ou seja, a posição do vetor estar definida
- Realizamos a troca do vetor
```
    v[0] = v[fim];
    v[fim] = pivo;
```
- Fizemos duas chamadas recursivas da função. As chamadas recursivas irão realizar os mesmos passos acima até o tamanho do vetor ser um ou zero, ou seja, até o subvetor estar totalmente ordenado
```
quick_sort(v, fim);
quick_sort(&v[inicio], tamanho - inicio);
```
- No final o algoritmo fica assim:
```
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
        //percorre vetor da esquerda para direira até encontrar elemento maior que o pivô
        while(inicio < tamanho && v[inicio] <= pivo) inicio++;
        //Percorre vetor da direita para esquerda até encontrar elemento menor que o pivô
        while(v[fim] > pivo) fim--;
        if(inicio < fim){
            int temp = v[inicio];
            v[inicio] = v[fim];
            v[fim] = temp;
            inicio++;
            fim--;
        }
    }while (inicio < fim);

    //troca pivô
    v[0] = v[fim];
    v[fim] = pivo;

    //chamadas recursivas da função
    quick_sort(v, fim);
    quick_sort(&v[inicio], tamanho - inicio);
    }
}
```

## *Merge Sort*
- O algoritmo utiliza o paradigma de programação de dividir para conquistar
- Primeiro chamamos a função merge_sort que vai dividir o meu vetor em listas menores, até termos vetores de uma unidade
```
void merge_sort(int A[], int p, int r) {
  int q;
  q = (p+r)/2;
  if (p < r) {
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    merge(A,p,q,r);
  }
}
```
- A[] = vetor
- p = posição incial
- q = meio
- r = posição final
- Depois vem o passo de junção desses vetores unitários, através da função merge
```
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
```
- O primeiro for pega os primeiros elementos e coloca no vetor L
- O segundo for pega os demais elementos e coloca no vetor R
- Colocamos o infinito na ultima posição dos vetores
- Comparamos os valores dos dois vetores e ordenamos os elementos

