#include <stdio.h>
#include <stdlib.h>

int main(){
  int numero, qtdPares = 0, qtdImpares = 0, somaPares = 0, somaImpares = 0, contador = 1;

  while(contador <= 10){
    printf("Digite um numero inteiro:\n");
    scanf("%d",&numero);

    if((numero%2) == 0){
      qtdPares++;
      somaPares += numero;
    }
    else{
      qtdImpares++;
      somaImpares += numero;
    }

    contador++;
  }

  printf("Soma dos numeros pares eh %d\n",somaPares);
  printf("Media dos numeros Impares eh %d\n",(float)(somaImpares/qtdImpares));

  return 0;
}
