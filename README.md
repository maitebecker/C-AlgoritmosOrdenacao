# C-AlgoritmosOrdenacao

### BubbleSort:
```
void bubble_sort(int A[]) {
    int i,j,aux,flag;
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
- Sempre vou olhar para o elemento de indice j e para o elemento de indice j+1. Quero saber se o valor da posição i é maior que o valor da posição i+1, ou seja, se o proxímo elemento é maior que o anterior.

  ``` if (A[j]>A[j+1]) ```
- Caso sim, trocamos esses elementos de lugar, utilizando uma variável auxiliar
  ```
   aux = A[j];
   A[j] = A[j+1];
   A[j+1] = aux;
  ```
- Caso não, incrementamos o indice j e verificamos a posição seguinte
- Realizamos esse passo para todas as posições do vetor. Nessa primeira varredura garantimos que o último elemento está na posição correta.
- Esses passos estarão dentro de outra estrutura de repetição que é realizada até não precisarmos realizar mais nenhuma troca, ou seja, paramos quando o vetor já está ordenado

###
