#include <stdio.h>
#include <string.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main() {
  int n;
  scanf("%d\n",&n);

  char classi[10];
  int k=0;
  for (int i=0;i<10;i++){//le o tipo de classificação que o professor vai pedir
    //printf("%d",i);
    if(k==0){
      scanf("%c",&classi[i]);
      //printf("%d",i);
      if (classi[i]=='\n'){
        k=1;
      }
    }
  }
  char lista[100][30];



  for (int i=0;i<n;i++){//ler a lista de nomes
    int k=0;
    for (int j=0;j<30;j++){//le cada nome
      if(k==0){
        scanf("%c",&lista[i][j]);
        if (lista[i][j]=='\n'){//identifica quando um nome acabou
          k=1;
          lista[i][j]='\0';
        }
      }

    }
  }

  for (int i=0;i<n;i++){//ordena lista
    for (int j=1;j<n-i;j++){
      if(strcmp(lista[i],lista[i+j])>0){
        char aux[30];
        for (int o=0;o<2+MAX(strlen(lista[i]),strlen(lista[i+j]));o++){
          aux[o]=lista[i][o];
          lista[i][o]=lista[i+j][o];
          lista[i+j][o]=aux[o];
        }
      }
    }
  }

  int tamanhos[100][2];
  for (int i=0;i<n+1;i++){
    int tamn[100];
    int tams[100];
    for (int j=0;j<30;j++){

      if (lista[i][j]=='_'){
        tams[i]=strlen(lista[i])-tamn[i]-1;
        j=30;
        //printf("%d %d %d\n",tamn[i],tams[i],k);
      }
      else{
        tamn[i]=j+1;
      }
    }
    tamanhos[i][0]=tamn[i];
    tamanhos[i][1]=tams[i];
  }

  int homo[100];
  for (int i=0;i<n+1;i++){
    homo[i]=0;
  }

  if (classi[0]=='h'){//classifica homonimos
    for (int i=0;i<n+1;i++){//nome a ser comparado
      for (int l=1;l<n+1-i;l++){//nomes para comparar
        int cont=0;
        for (int j=0;j<tamanhos[i][0];j++){
          if(lista[i][j]==lista[i+l][j]){//letras a serem comparadas
            cont=cont+1;
            if(cont==tamanhos[i][0]){
              homo[i]=1;
              homo[i+l]=1;
            }
          }



        }
      }
    }
  }



  for (int i=0;i<n;i++){//imprime nomes
    int k=0;
    if(homo[i]==1){
      for (int j=0;j<30;j++){
        if(k==0){
          if (lista[i][j]=='\0'){
            k=1;
            printf("\n");
          }
          else{
            printf("%c",lista[i][j]);
          }


        }
      }
    }


  }
}
