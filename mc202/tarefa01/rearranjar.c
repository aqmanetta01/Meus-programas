#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int lista[10001];
    int j;
    for (j=0;j<n;j++){
        lista[j]=j+1;
    }
    int m;
    scanf("%d",&m);
    int i;
    int t;
    int ini;
    int fim;
    int c;
    for (i=0;i<m;i++){
      fim=0;
      ini=0;
      t=0;
      c=0;
        scanf("%d %d %d",&t, &ini, &fim);
        if (t==1){

            int k;
            for (k=0;k<n;k++){
              //printf("ok3 \n");
              //printf("%d %d %d\n",c,lista[k],ini);
              if (lista[k]==ini && c==0){
                //printf("ok3 \n");
                int l;
                for (l=k;l<n;l++){
                  //printf("%d %d %d\n",c,lista[l],fim);
                  //printf("ok2 \n");
                  if (lista[l]==fim && c==0){
                    //printf("ok \n");
                    c=1;
                    int ini2;
                    ini2=k;
                    int fim2;
                    fim2=l;
                    int q;
                    //printf("%d %d\n",fim2,ini2);
                    for(q=0;q<(fim2-ini2+1);q++){
                      //printf("ok \n");
                      int p;
                      for (p=0;p<fim2-ini2-q;p++){
                        int aux;
                        aux=lista[ini2+p];
                        lista[ini2+p]=lista[ini2+p+1];
                        lista[ini2+p+1]=aux;
                        int o;
                        for (o=0;o<n;o++){
                          //printf("%d ",lista[o]);
                        }
                        //printf("\n");
                      }
                    }
                  }
                }
              }
            }

        }
        if (t==2){
          //printf("ok \n");
          int k;
            for (k=0;k<n;k++){
              if (lista[k]==ini){
                int l;
                for(l=k;l<n;l++){
                  if (lista[l]==fim){
                    int p;
                    for(p=k;p<l;p++){
                      int aux;
                      aux=lista[p];
                      lista[p]=lista[p+1];
                      lista[p+1]=aux;
                      int o;
                      for (o=0;o<n;o++){
                        //printf("%d ",lista[o]);
                      }
                      //printf("\n");
                    }
                  }
                }
              }
            }

        }
    }
    int o;
    for (o=0;o<(n);o++){
      //printf("ok \n");
      printf("%d ",lista[o]);
    }
    printf("\n");
}
