#include <stdio.h>
#include <stdlib.h>

void teste(int vetor[10]){
  vetor[0] = 20000;
}

int main(){
  int vetor[10];
  
  vetor[0] = 800;

  teste(vetor);
  
  printf("%d\n",vetor[0]);

  return 0;
}
