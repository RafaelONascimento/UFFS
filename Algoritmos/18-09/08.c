#include <stdio.h>
#include <stdlib.h>

int main(){
  int numero, i = 0, k = 0,  j, flag = 0;
  
  printf("Digite um numero inteiro:\n");
  scanf("%d",&numero);

  k = numero - 1;

  while(k != numero){    
    j = 1;
    while(j <= k){
      printf(" ");
      j++;
    }
    
    while(j <= numero){
      printf("*");
      j++;
    }
    printf("\n");
    
    if(k == 0){
      flag = 1;
    }
    
    if(flag==0){
      k--;
    }
    else{
      k++;
    }
  }
  
  return 0;
}
