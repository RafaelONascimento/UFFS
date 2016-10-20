#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  float matriz[10][3], media, soma, qtd;
  int i, j;
  memset(matriz,0,sizeof(matriz));
  for(i = 0; i < 10; i++){
    for(j = 0; j < 3; j++){
      scanf("%f",matriz[i][j]);
      soma += (!i)?matriz[i][j]:0;
    }
  }
  media = soma/10;
  for(i = 0; i < 10; i++){
    for(j = 0; j < 3; j++)
      if(matriz[i][j] > media) qtd++; 
  }
  printf("%d\n",qtd);
  return 0;
}
