#include <stdio.h>
#include <stdlib.h>

int main(){

  int numero, i,j;
  
  printf("Digite um numero inteiro\n");
  scanf("%d",&numero);

  for(i = 1; i <= numero; i++){
    for(j=0;j < i;j++){
      printf("*");
    }
    printf("\n");
  }

  return 0; 
}
