#include <stdio.h>
#include <stdlib.h>

int main(){
  int matriz[3][2], i , j, qtd = 0;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 2; j++){
      printf("Digite o valor[%dX%d]:\n",(i+1),(j+1));
      scanf("%d",&matriz[i][j]);
    }
  }
  
  for(i = 0; i < 3; i++){
    for(j = 0; j < 2; j++){
      if(matriz[i][j] < 0){
	qtd++;
      }
    }
  } 

  printf("Total numeros negativos = %d\n",qtd);
}
