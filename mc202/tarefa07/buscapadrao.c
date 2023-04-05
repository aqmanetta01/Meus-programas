#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void le_txt(char *txt,int n) {
  for (int i=0;i<n;i++){
    scanf("%c",&txt[i]);
  }
  scanf("\n");
}
void le_pa(char *pa,int m){
  for (int i=0;i<m;i++){
    scanf("%c",&pa[i]);
  }
}

void imp_oco(char *txt,char *pa,int n,int m){
  int aux1,aux2;
  aux2=0;
  for (int i=0;i<n-m+1;i++){
    aux1=0;
    for (int j=0;j<m;j++){
      if (pa[j]==txt[i+j]){
        aux1=aux1+1;
        if (aux1==m){
          if (aux2>0)
            printf(",%d",i+1);
          else 
            printf("%d",i+1);
          aux2=aux2+1;
        }
      }
    }
  }
  if (aux2>0)
    printf(".");
  else
    printf("padrão não ocorre no texto.");
}
  
int main(){
  int n,m;
  scanf("%d\n",&n);
  scanf("%d\n",&m);
  char *txt;
  txt = malloc(n*sizeof(char));
  if ( txt == NULL ) {
    printf (" Nao ha memoria suficente !\n");
    exit (1) ;
  }
  char *pa;
  pa = malloc(m*sizeof(char));
  if ( pa == NULL ) {
    printf (" Nao ha memoria suficente !\n");
    exit (1) ;
  }
  le_txt(txt, n);
  le_pa(pa, m);
  imp_oco(txt, pa, n, m);
  free(txt);
  free(pa);
  return 0;      
}