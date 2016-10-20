#include <stdio.h>
#include <stdlib.h>

int main(){
  float s = 0, numerador = 1, denominador = 1;
  
  do{
    s += numerador/denominador;
    
    numerador += 2;
    denominador += 1;

  }while(numerador <= 99 && denominador <= 50);

  printf("S = %.2f\n",s);

  return 0;
}
