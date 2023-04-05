#include <stdio.h>
#include "planejar.h"

int main(){
  Voo voos[100];

  int a=0;
  char op;
  int qtd_voos;
  qtd_voos=0;
  int numero_voo;
  while (a==0){

    //printf("%d\n",a);
    scanf("%c",&op);
    //printf("%c\n",op);
    char lixo;
    if (op=='r'){
      //printf("%c\n",op);
      for (int i=0;i<8;i++){
        scanf("%c",&lixo);
        //printf("%c",lixo);

      }
      //printf("\n");
      qtd_voos=qtd_voos+1;
      //printf("%d\n",qtd_voos);
      voos[qtd_voos-1]=ler_voo( voos,qtd_voos);

    }
    if(op=='a'){
      for (int i=0;i<6;i++){
        scanf("%c",&lixo);
        //printf("%c",lixo);
      }
      //printf("\n");
      double novo_valor;
      scanf("%d %lf\n",&numero_voo,&novo_valor);
      //printf("%d %.2lf\n",numero_voo,novo_valor);
      alterar( voos, qtd_voos, numero_voo, novo_valor);
    }
    if(op=='c'){
      for (int i=0;i<7;i++){
        scanf("%c",&lixo);
      }

      scanf("%d ",&numero_voo);
      cancelar(voos, qtd_voos, numero_voo);
    }
    if(op=='p'){
      for (int i=0;i<7;i++){
        scanf("%c",&lixo);
        //printf("%c",lixo);
      }
      //printf("\n");
      Data data_inicio;
      Data data_fim;
      char codigo_origem[4];

      scanf("%s ",codigo_origem);
      //printf("%s\n",codigo_origem);
      data_inicio= ler_data();
      data_fim=ler_data();
      //printf("%d/%d/%d\n",data_inicio.dia,data_inicio.mes,data_inicio.ano);
      planejar( voos, qtd_voos, data_inicio, data_fim, codigo_origem);
      a=1;
    }
  }
}
