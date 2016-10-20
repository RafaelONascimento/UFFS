#include <stdio.h>
#include <stdlib.h>

int main(){
   int idade, qtdLivros = 0 ,qtdMenores = 0, qtdMulheres = 0, qtdHomens = 0;
   int qtdPessoas = 0, qtdNaoLeram = 0, somaIdade = 0;
   float mediaIdadeHomens = 0.0;
   char sexo;

   printf("Digite o sexo, a idade e quantidade de livros lida:\n");

   while(scanf("%c %d %d",&sexo,&idade,&qtdLivros),idade >= 0){
     setbuf(stdin,NULL);
     if(idade < 10){
       qtdMenores += qtdLivros;
     }

     if(sexo == 'F' && qtdLivros >= 5){
       qtdMulheres++;
     }
     
     if(sexo == 'M' && qtdLivros < 5){
       somaIdade += idade;
       qtdHomens++;
     }
     if(qtdLivros <= 0){
       qtdNaoLeram++;
     }

     qtdPessoas++;
   }
   
   
   if(qtdHomens > 0){
     mediaIdadeHomens = (somaIdade/qtdHomens);
   }
   else{
     mediaIdadeHomens = 0.0;
   }
   

   printf("Quantidade de livros lidos por pessoas com menos de 10 anos = %d\n",qtdMenores);
   printf("Quantidade de mulheres que leram 5 livros ou mais = %d\n",qtdMulheres);
   printf("Media de idade dos homen que leram menos que 5 livros = %.1f\n",mediaIdadeHomens);
   printf("O percentual de pessoal que nao leram livros eh: %.2f\n",((100.0/qtdPessoas)*qtdNaoLeram));

   return 0;
}
