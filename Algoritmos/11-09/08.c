#include <stdio.h>
#include <stdlib.h>

int main(){
  char operador;
  int numero, resultado = 0, i;

  printf("Digite o calculo:\n");
  scanf("%d",&resultado);
  scanf("%c",&operador);

  for(i = 0; operador != '='; i++){
    scanf("%d",&numero);
    
    switch(operador){
       case '+':
	 resultado += numero;
	 break;
       case '-':
	 resultado -= numero;
	 break;
       case '*':
	 resultado *= numero;
	 break;
       case '/':
	 resultado /= numero;
	 break;
    }

    scanf("%c",&operador);
  }

  printf("Resultado = %d\n",resultado);

  return 0;
}
