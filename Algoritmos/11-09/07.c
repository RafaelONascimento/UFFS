#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int numero, i, j, k, l;

  printf("Digite um numero inteiro(1-10):\n"); 
  scanf("%d",&numero);

  for (i = 1; i <= numero; i++){
    for (j = (numero - 1); j >= i; j--){
      printf("   ");
    }
    
    for(k = i; k > 1; k--){
      printf("  %d", k);
    }
    
    for(l = 1; l <= i; l++){           
      printf("  %d", l); 
    } 
		
    printf("\n");
  }
  
  return 0;
}
