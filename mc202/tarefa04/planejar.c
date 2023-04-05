#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "planejar.h"

Data ler_data(){
  Data data;
  scanf("%d/%d/%d",&data.dia,&data.mes,&data.ano);
  return data;
}

Voo ler_voo(Voo voos[100],int qtd_voos){
  Voo voo;

  scanf("%d",&voo.numero_voo);
  scanf("%s %s",voo.cod_ori_voo,voo.cod_des_voo);
  voo.data_voo= ler_data();
  scanf("%lf\n",&voo.valor);

  return voo;
}

int compara_data(Data data1, Data data2){
  int aux;
  if (data1.ano == data2.ano){
    if (data1.mes == data2.mes){
      if (data1.dia > data2.dia){
        aux= 0;
      }
      else{
        aux= 1;
      }
    }
    else{
      if (data1.mes > data2.mes){
        aux= 0;
      }
      else{
        aux= 1;
      }
    }
  }
  else{
    if (data1.ano > data2.ano){
      aux=0;
    }
    else{
      aux=1;
    }
  }
  return aux;
}

int diferenca_data(Data data1, Data data2){
  int aux;
  int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int soma1=data1.dia;
  int soma2=data2.dia;
  for (int i=0;i<data1.mes-1;i++){
    soma1=soma1+dias_mes[i];
  }
  for (int i=0;i<data2.mes-1;i++){
    soma2=soma2+dias_mes[i];
  }
  if (data1.ano == data2.ano){
    aux=soma1-soma2;
  }
  else{
    aux=365+soma1-soma2;
  }
  return aux;
}

void cancelar(Voo voos[], int qtd_voos, int numero_voo){
  for(int i=0;i<qtd_voos;i++){
    voos[i].conf=0;
  }
  for(int i=0;i<qtd_voos;i++){

    if (numero_voo==voos[i].numero_voo){
      voos[i].conf=1;
    }
  }
}

void alterar(Voo voos[], int qtd_voos, int numero_voo,double novo_valor){
  for(int j=0;j<qtd_voos;j++){
    if (numero_voo==voos[j].numero_voo){
      voos[j].valor=novo_valor;
    }
  }
}

void planejar(Voo voos[], int qtd_voos, Data data_inicio, Data data_fim, char codigo_origem[]){
  double menor_custo;
  menor_custo=100000;
  int menor_custo_ida;
  int menor_custo_volta;
  //printf("%d\n",qtd_voos);
  for(int i=0;i<qtd_voos;i++){

    if(voos[i].conf==0){
      //printf("%d\n",i);
      //printf("%s %s\n",codigo_origem,voos[i].cod_ori_voo);
      if(strcmp(codigo_origem,voos[i].cod_ori_voo)==0 ){
        //printf("%d\n",i);
        if(compara_data(data_inicio, voos[i].data_voo)==1){
          voos[i].data_ok=1;
          //voo bom
          for(int j=0;j<qtd_voos;j++){
            if(strcmp(voos[j].cod_ori_voo,voos[i].cod_des_voo)==0 && strcmp(voos[i].cod_ori_voo,voos[j].cod_des_voo)==0 && compara_data( voos[j].data_voo,data_fim)==1 && diferenca_data(voos[j].data_voo,voos[i].data_voo)>2){
              voos[i].par_voo[j]=j;
              int aux;
              aux=voos[i].valor+voos[j].valor;
              if(aux<menor_custo){
                menor_custo=aux;
                menor_custo_ida=voos[i].numero_voo;
                menor_custo_volta=voos[j].numero_voo;
              }
            }
          }
        }
        else{
          voos[i].data_ok=0;
          //voo ruim
        }

      }

    }
  }
  printf("%d\n%d",menor_custo_ida,menor_custo_volta);
}
