#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minecraft.h"

int **calcularAltitudes(int m, int n, int seed){
  int **alt =malloc(m*sizeof(int*));
  for (int i=0;i<m;i++){
    alt[i]=malloc(n*sizeof(int));
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      alt[i][j]=(seed*(i+j+202)+12345+i+j)%256;
    }
  }
  return alt;
}

Bloco ***criarMundo(int m, int n, int **alt, int seed){
  Bloco ***blocos=malloc(m*sizeof(Bloco**));
  for (int i=0;i<m;i++){
    blocos[i]=malloc(n*sizeof(Bloco*));
    for (int j=0;j<n;j++){
      blocos[i][j]=malloc(256*sizeof(Bloco));
    }
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      for (int k=0;k<256;k++){
        if (k>alt[i][j]){
          blocos[i][j][k].M=21;
          blocos[i][j][k].x=i;
          blocos[i][j][k].z=j;
          blocos[i][j][k].y=k;
        }
        else{
          blocos[i][j][k].M=(seed*(i+j+k+202)+i+j+k)%33;
          blocos[i][j][k].x=i;
          blocos[i][j][k].z=j;
          blocos[i][j][k].y=k;
        }
      }
    }
  }
  return blocos;

}

void le_entrada(int *m,int *n,int *seed,double *t){
  scanf("%d %d\n",m,n);
  scanf("%d\n",seed);
  scanf("%lf",t);
}

double explorarMundo(Bloco ***blocos, int m, int n, int **alt, double t,int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos){
  double tempo_total;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<256;k++){
        if(blocos[i][j][k].M==0 ){
          *qtdDiamante=*qtdDiamante+1;
          tempo_total=tempo_total+t;
          *qtdBlocos=*qtdBlocos+1;
        }
        else if(blocos[i][j][k].M==1 || blocos[i][j][k].M==2 ){
          *qtdOuro=*qtdOuro+1;
          tempo_total=tempo_total+t;
          *qtdBlocos=*qtdBlocos+1;
        }
        else if(blocos[i][j][k].M==3 || blocos[i][j][k].M==4 || blocos[i][j][k].M==5 ){
          *qtdFerro=*qtdFerro+1;
          *qtdBlocos=*qtdBlocos+1;
          tempo_total=tempo_total+t;
        }
        else if(blocos[i][j][k].M>5 && blocos[i][j][k].M<12){
          tempo_total=tempo_total+t;
          *qtdBlocos=*qtdBlocos+1;
        }
        else if(blocos[i][j][k].M>11 && blocos[i][j][k].M<21){
          tempo_total=tempo_total+t;
          *qtdBlocos=*qtdBlocos+1;
        }
      }
    }
  }
  return tempo_total;
}

void imprime( double tempo_total,int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos){
  printf("Total de Blocos: %d\n",*qtdBlocos);
  printf("Tempo total: %.2lfs\n",tempo_total);
  printf("Diamantes: %d\n",*qtdDiamante);
  printf("Ouros: %d\n",*qtdOuro);
  printf("Ferros: %d\n",*qtdFerro);
}

int main() {
  int m,n,seed;
  m=n=0;
  int qtdDiamante=0,qtdOuro=0,qtdFerro=0,qtdBlocos=0;
  double tempo_total,t;
  tempo_total=0;
  le_entrada(&m,&n,&seed,&t);
  int **alt;
  alt =calcularAltitudes( m, n,seed);
  Bloco ***blocos;
  blocos=criarMundo( m, n, alt, seed);
  tempo_total=explorarMundo(blocos, m, n, alt, t,&qtdDiamante, &qtdOuro, &qtdFerro, &qtdBlocos);
  imprime( tempo_total,&qtdDiamante, &qtdOuro, &qtdFerro, &qtdBlocos);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      free(blocos[i][j]);
    }
    free(blocos[i]);
  }
  free(blocos);
  for(int i=0;i<m;i++){
    free(alt[i]);
  }
  free(alt);
}
