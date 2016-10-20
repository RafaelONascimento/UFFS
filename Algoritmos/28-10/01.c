#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  double vendas[4][12], total;
  int i, j;
  memset(vendas,0.0,sizeof(vendas));
  
  for(i = 0; i < 12; i++){
    for(j = 0; j < 4; j++){
      printf("Digite o valor para o mes %d: Semana %d:\n",(i+1),(j+1));
      scanf("%lf",&vendas[i][j]);
    }
  }

  for(i = 0; i < 12; i++){
    total = 0;
    for(j = 0; j < 4; j++){
      total += vendas[i][j];
    }
    printf("Total Vendido Mes %d = %.2lf",(i+1),total);
  }
  
  for(i = 0; i < 12; i++){
    for(j = 0; j < 4; j++){
      printf("Total vendido semana %d, do mes %d = %.2lf\n",(j+1),(i+1),vendas[i][j]);
    }
  }
  total = 0;

  for(i = 0; i < 12; i++){
    for(j = 0; j < 4; j++){
      total += vendas[i][j];
    }
  }

  printf("Total vendido no ano = %.2lf\n",total);

  return 0;
}
