#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int dimensao;

void CarregaArquivo(float Matriz[MAX][MAX]){
  char s[2] = ","; // Separador da Coluna
  char *coluna;    // Conteudo da Coluna
  char linha[130]; // Linha inteira do arquivo
  char *result;    // retorna conteudo da linha

  FILE *fMatriz;

  int j= 0, i= 0;

  if((fMatriz = fopen("ortogonaliza3.txt","r")) != NULL) {// SE não existe o arquivo não deve ler
    i = 0;
    while (!feof(fMatriz) && i < 100){ //para garantir que não passa do tamanho da Matriz.	     
      result = fgets(linha, 130, fMatriz); // Le a linha
      if(!(linha[0] == '/' && linha[1] == '/')){
	
	linha[0]=',';
	if (result){
	  coluna = strtok(result, s); // se encontrou linha, quebra pelo separador "s";
	}else
	  break;
	
	j = 0;
	
	while( coluna != NULL ){ // enquanto não chegar na ultima coluna
	  Matriz[i][j] = atof(coluna);
	  coluna = strtok(NULL, s);

	  if ((dimensao-1) < j){
	    dimensao = (j+1);
	  }
	  j++;
	}
	i++;
      }
    }
    
    fclose(fMatriz);
  }
}

int main(){
  float Matriz[MAX][MAX];
  int ordem,i,j;

  CarregaArquivo(Matriz);
  for(i = 0;i < dimensao;i++){
    for(j = 0;j < dimensao;j++){
      printf("%.4f ",Matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
