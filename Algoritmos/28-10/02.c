#include <stdio.h>
#include <stdlib.h>

int main(){
  int matriz[3][3], i , j, total;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      printf("Digite o valor[%dX%d]:\n",(i+1),(j+1));
      scanf("%d",&matriz[i][j]);
    }
  }
  
  for(i = 0; i < 3; i++){
    total += matriz[0][i];
  }

  printf("Total coluna 1 = %d\n",total);
}
