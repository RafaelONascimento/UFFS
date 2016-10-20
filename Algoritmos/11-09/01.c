#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int numero, i;

  printf("Digite um valor inteiro:\n");
  scanf("%d",&numero);
  
  for(i = 1; i < numero; i++){
    printf("O quadrado de %d = %d\n",i,(i*i));
  }

  return 0;
}
