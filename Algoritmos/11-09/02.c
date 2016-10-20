#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int n,i,j,numero;
  long long fatorial;

  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    printf("Digite um numero inteiro:\n");
    scanf("%d",&numero);
    
    for(fatorial = 1,j = 1; j <= numero; j++){
      fatorial *= j;
    }

    printf("Fatorial de %d = %lli\n",numero,fatorial);
  }

  return 0;
}
