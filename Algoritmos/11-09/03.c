#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i,j;
  unsigned long long produto = 1;

  for(i=92;i <= 1478; i++){
    for(j=2; j<i;j++){
      if((i%j)==0){
	break;
      } 
    }

    if(j == i){
      produto *= i;
    }
  }

  printf("O produto eh: %llu\n",produto);

  return 0; 
}
