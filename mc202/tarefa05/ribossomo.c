#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct altera {
  char dna[14];
  char rna[14];
} ;

void le_altera(struct altera *alt){
  scanf("%s",alt->dna);
  scanf("%s",alt->rna);
}

void le_dna(char *dna,char *rna,int *id,int n){
  int i;

  //printf("n=%d\n",n);
  for(i=0;i<n;i++){
    scanf("%c",&dna[i]);
    //printf("%c\n",dna[i]);
    //printf("%d\n",i);
    int cont=0;
    for (int j=0;j<i;j++){
      //printf("%d %d\n",i,j);
      if(dna[i]==dna[i-j-1]){
        cont=cont+1;

      }
    }
    id[i]=cont;
    //printf("cont=%d\n",cont);
  }

}

void sintetiza(char *dna,char *rna,struct altera alt,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<13;j++){
      //printf("%d %d\n",i,j);
      //printf("%d\n",n);
      //printf("%c",dna[i]);
      //printf("%c",alt.rna[i]);
      if(dna[i]==alt.dna[j]){
        //printf("%c",alt.rna[i]);
        rna[i]=alt.rna[j];
      }
      //printf("%d %d\n",i,j);
    }

  }
}

void imprime_trans(char *dna,char *rna,int *id,int n){
  int i;
  //printf("%d",n);
  printf("ID: ");
  for(i=0;i<n;i++){
    printf("\t%d",id[i]);
  }
  printf("\n");
  printf("DNA:");
  for(i=0;i<n;i++){
    printf("\t%c",dna[i]);
  }
  printf("\n");
  printf("    ");
  for(i=0;i<n;i++){
    printf("\t|");
  }
  printf("\n");
  printf("RNA:");
  for(i=0;i<n;i++){
    printf("\t%c",rna[i]);
  }
  printf("\n");
}

int main() {
  char *dna,*rna;
  int *id,n;
  struct altera alt;
  le_altera(&alt);
  //printf("%s",alt.dna);
  //printf("%s",alt.rna);
  scanf("%d\n",&n);
  dna= malloc((n)*sizeof(char));
  rna= malloc((n)*sizeof(char));
  id = malloc((n)*sizeof(int));
  le_dna(dna,rna,id,n);
  sintetiza(dna,rna,alt,n);
  imprime_trans(dna,rna,id,n);
  free(dna);
  free(rna);
  free(id);
}
