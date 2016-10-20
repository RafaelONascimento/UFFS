#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade = 0, identificador = 0, opiniao = 0, qtdOpiniao10 = 0, somaIdades = 0, qtdOpiniao5 = 0;
    int contador = 1, maisVelha  = 0;
    
    while(contador <= 200){
      printf("Digite a idade, identificador e opiniao:\n");
      scanf("%d %d %d",&idade,&identificador,&opiniao);
      
      if(opiniao == 10){
	qtdOpiniao10++;
      }
      if(opiniao <= 5){
	qtdOpiniao5++;
      }
      somaIdades += idade;
      
      if(idade > maisVelha){
	maisVelha = identificador;
      }
      
      contador++;
    }
    
    printf("Quantidade de opiniao 10: %d\n",qtdOpiniao10);
    printf("Media de idade: %d\n",(somaIdades/200));
    printf("Percentual de pessoas que responderam 5 ou menos: %.2f\n",((100.0/200.0) * qtdOpiniao5));
    printf("Identificador pessoa mais velha = %d\n",maisVelha)

    return 0;
}
