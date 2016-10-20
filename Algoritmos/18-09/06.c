#include <stdio.h>
#include <stdlib.h>

int main(){
  int serie = 0, qtdLivros = 0, gostaRedacao = 0, qtdTerceiraSerie = 0;
  int maiorQtdLivro = 0, naoGostamRedacao = 0, idade = 0;

  do{
    printf("Digite a serie do aluno:\n");
    scanf("%d",&serie);

    printf("Digite a quantidade de livros lidos por mes:\n");
    scanf("%d",&qtdLivros);
    
    printf("Gosta de redacao(Sim-1 ou nao-0):\n");
    scanf("%d",&gostaRedacao);

    printf("Digite a idade do aluno:\n");
    scanf("%d",&idade);
    

    if(serie == 3){
      qtdTerceiraSerie++;
    }
    if(serie == 4 && qtdLivros > maiorQtdLivro){
      maiorQtdLivro = qtdLivros;
    }
    if(gostaRedacao == 0){
      naoGostamRedacao++;
    }
    
  }while(idade != 0);
  
  printf("A quantidade de alunos da terceira serie = %d.\n",qtdTerceiraSerie);
  printf("A maior quantidade ed livros lidos por um aluno que esta na quarta serie eh: %d.\n",maiorQtdLivro);
  printf("A porcentagem de alunos que nao gostam de fazer redacao na terceira serie = %.2f.\n",((100.00)/qtdTerceiraSerie) * naoGostamRedacao);
  
  return 0;

}
