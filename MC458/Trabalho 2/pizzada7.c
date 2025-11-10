#include <stdio.h>
#include <stdlib.h>

typedef struct pizza {
  int s, t, r;
} pizza;

// Função para intercalar dois subarrays
void intercalar(pizza arr[], int inicio, int meio, int fim) {
  int tamanho_esq = meio - inicio + 1;
  int tamanho_dir = fim - meio;

  // Arrays auxiliares para armazenar temporariamente os valores
  pizza esquerda[tamanho_esq];
  pizza direita[tamanho_dir];

  // Copiando dados para os arrays auxiliares
  for (int i = 0; i < tamanho_esq; i++) {
    esquerda[i] = arr[inicio + i];
  }
  for (int j = 0; j < tamanho_dir; j++) {
    direita[j] = arr[meio + 1 + j];
  }

  int i = 0, j = 0, k = inicio;

  // Intercalando os subarrays de volta ao array original em ordem decrescente
  while (i < tamanho_esq && j < tamanho_dir) {
    double razao_esq = esquerda[i].r / (1.0 * esquerda[i].t);
    double razao_dir = direita[j].r / (1.0 * direita[j].t);
    if (razao_esq >= razao_dir) {
      arr[k] = esquerda[i];
      i++;
    } else {
      arr[k] = direita[j];
      j++;
    }
    k++;
  }

  // Copiando os elementos restantes, se houver, da primeira metade
  while (i < tamanho_esq) {
    arr[k] = esquerda[i];
    i++;
    k++;
  }

  // Copiando os elementos restantes, se houver, da segunda metade
  while (j < tamanho_dir) {
    arr[k] = direita[j];
    j++;
    k++;
  }
}

// Função recursiva para ordenar o array usando Mergesort
void mergesort_decrescente(pizza arr[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;

    // Ordenando recursivamente a metade esquerda e direita
    mergesort_decrescente(arr, inicio, meio);
    mergesort_decrescente(arr, meio + 1, fim);

    // Mesclando as duas metades ordenadas
    intercalar(arr, inicio, meio, fim);
  }
}


int solve(pizza *pizzas, int N, int T) { 
  int **Z;
  Z = malloc ((N+1) * sizeof (int*)) ;
  for (int i=0; i < N+1; i++)
    Z[i] = malloc ((T+1) * sizeof (int)) ;
  for (int j=0;j<T+1;j++){
    Z[0][j]=0;
  }
  for (int i=0;i<N+1;i++){
    Z[i][0]=0;
  }
  
  for (int i=1;i<N+1;i++){
    //printf("P%d ",pizzas[i-1].r);
    for (int j=1;j<T+1;j++){
      if(j>=pizzas[i-1].t){
        Z[i][j]=pizzas[i-1].s-pizzas[i-1].r*j;
          if (Z[i][j]+Z[i-1][j-pizzas[i-1].t]>Z[i][pizzas[i-1].t]){
            Z[i][j]=Z[i][j]+Z[i-1][j-pizzas[i-1].t];
            
          }
          else{
            Z[i][j]=Z[i][pizzas[i-1].t];
          }
          if (Z[i][j]<Z[i][j-1])
              Z[i][j]=Z[i][j-1];
          if (Z[i][j]<Z[i-1][j])
            Z[i][j]=Z[i-1][j];

      }
      else{
        Z[i][j]=Z[i-1][j];
      }
      //if (j%5==0)
        //printf ("%d ",Z[i][j]);
    }
    //printf("\n");
  }
  int valor = Z[N][T];
  // libera a memória da matriz
  for (int i=0; i < N+1; i++)
   free (Z[i]) ;
  free (Z) ;
  return valor; 
}


int main() {

  int N, T;
  scanf("%d %d", &N, &T);
  
  pizza pizzas[N];
  for (int i = 0; i < N; ++i)
    scanf("%d %d %d", &pizzas[i].s, &pizzas[i].t, &pizzas[i].r);
  mergesort_decrescente(pizzas, 0, N - 1);
  printf("%d\n", solve(pizzas, N, T));
  return 0;
}

//80 25 1
//70 20 2
//60 15 3
  
