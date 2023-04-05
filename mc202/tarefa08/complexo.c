#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double a;
  double b;
}complexo;

void imprime_complexo(complexo complexo){
  printf("z=%lf+i%lf",complexo.a,complexo.b);
}
void compara_complexo(complexo complexo1 ,complexo complexo2){
  if (complexo1.a==complexo2.a && complexo1.b==complexo2.b)
    printf("Os números são iguais!");
  else
    printf("Os números são diferentes!");  
}

complexo calcula_conjugado(complexo complexo1){
  complexo conjugado;
  conjugado.a=complexo1.a;
  conjugado.b=-complexo1.b;
  return(conjugado);
}

complexo soma_complexo(complexo complexo1 ,complexo complexo2){
  complexo soma;
  soma.a=complexo1.a+complexo2.a;
  soma.b=complexo1.b+complexo2.b;
  return (soma);
}

complexo mult_complexo(complexo complexo1 ,complexo complexo2){
  complexo mult;
  mult.a=complexo1.a*complexo2.a-complexo1.b*complexo2.b;
  mult.b=complexo1.a*complexo2.b+complexo1.b*complexo2.a;
  return (mult);
}

complexo subt_complexo(complexo complexo1 ,complexo complexo2){
  complexo subt;
  subt.a=complexo1.a-complexo2.a;
  subt.b=complexo1.b-complexo2.b;
  return (subt);
}

int main() {
  int n;
  scanf("%d\n",&n);
  complexo *v;
  v=malloc(n*sizeof(complexo));
  if ( v == NULL ) {
    printf (" Nao ha memoria suficente !\n");
    exit (1) ;
  }
  for (int i=0;i<n;i++){
    scanf("%lf %lf", &v[i].a , &v[i].b) ;
  }
  complexo soma;
  soma.a=0;
  soma.b=0;
  complexo mult;
  mult.a=1;
  mult.b=0;
  for (int i=0;i<n;i++){
    soma=soma_complexo(v[i] ,soma);
    mult=mult_complexo(v[i], mult);
  }
  if (soma.b>0)
    printf("A soma dos números é: %lf+%lfi\n",soma.a,soma.b);
  else
    printf("A soma dos números é: %lf%lfi\n",soma.a,soma.b);
  if (mult.b>0)
    printf("A multiplicação dos números é: %lf+%lfi",mult.a,mult.b);
  else
    printf("A multiplicação dos números é: %lf%lfi",mult.a,mult.b);
  free(v);
  return 0;
}