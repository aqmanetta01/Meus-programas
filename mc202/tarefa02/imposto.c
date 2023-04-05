#include <stdio.h>

int main() {
  int n;
  scanf("%d",&n);
  double M[1000][12];
  for (int i=0;i<n;i++){
    for (int j=0;j<12;j++){
      scanf("%lf",&M[i][j]);
    }
  }
  double A[1000];
  for (int i=0;i<n;i++){
    scanf("%lf",&A[i]);
  }
  double impm[1000][12];
  double impmt[1000];
  for (int i=0;i<n;i++){
    impmt[i]=0;
    for (int j=0;j<12;j++){
      if (M[i][j]<1499.15){
        impm[i][j]=0;
      }
      else if (M[i][j]<2246.75){
        impm[i][j]=(M[i][j]-1499.15)*0.075;
      }
      else if (M[i][j]<2995.70){
        impm[i][j]=(M[i][j]-2246.75)*0.15;
        impm[i][j]=impm[i][j]+(2246.75-1499.15)*0.075;
      }
      else if (M[i][j]<3743.19){
        impm[i][j]=(M[i][j]-2995.70)*0.225;
        impm[i][j]=impm[i][j]+(2995.70-2246.75)*0.15;
        impm[i][j]=impm[i][j]+(2246.75-1499.15)*0.075;
      }
      else{
        impm[i][j]=(M[i][j]-3743.19)*0.275;
        impm[i][j]=impm[i][j]+(3743.19-2995.70)*0.225;
        impm[i][j]=impm[i][j]+(2995.70-2246.75)*0.15;
        impm[i][j]=impm[i][j]+(2246.75-1499.15)*0.075;
      }
      impmt[i]=impmt[i]+impm[i][j];
    }
  }


  double ra[1000];
  double impa[1000];
  for (int i=0;i<n;i++){
    ra[i]=0;
    for (int j=0;j<12;j++){
      ra[i]=ra[i]+M[i][j];
    }
    impa[i]=0;
    ra[i]=ra[i]-A[i];
    if (ra[i]<18000){
      impa[i]=0;
    }
    else if (ra[i]<26400){
      impa[i]=(ra[i]-18000)*0.075;
    }
    else if (ra[i]<36000){
      impa[i]=(ra[i]-26400)*0.15;
      impa[i]=impa[i]+(26400-18000)*0.075;
    }
    else if (ra[i]<44400){
      impa[i]=(ra[i]-36000)*0.225;
      impa[i]=impa[i]+(36000-26400)*0.15;
      impa[i]=impa[i]+(26400-18000)*0.075;
    }
    else {
      impa[i]=(ra[i]-44400)*0.275;
      impa[i]=impa[i]+(44400-36000)*0.225;
      impa[i]=impa[i]+(36000-26400)*0.15;
      impa[i]=impa[i]+(26400-18000)*0.075;
    }

  }


  printf("Jan\tFev\tMar\tAbr\tMai\tJun\tJul\tAgo\tSet\tOut\tNov\tDez\tRetido\tDevido\tAjuste\t\n");
  for (int i=0;i<n;i++){
    for (int j=0;j<12;j++){
      printf("%.2lf\t",impm[i][j]);
    }
    printf("%.2lf\t",impmt[i]);
    printf("%.2lf\t",impa[i]);
    printf("%.2f\t\n",(impa[i]-impmt[i]));
  }
}
