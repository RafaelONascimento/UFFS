#include <stdio.h>
#include <stdlib.h>

#define MAX 1123
#define URL "ortogonaliza3.txt"

int dimensao;

int verificaLD(float matrizVetores[MAX][MAX]){
  int flag = false;
  float a;
  
  for(int i = 0; i < dimensao && !flag; i++){
    for(int j = 0; j < dimensao && !flag; j++){
      if(i < j){
	a = (matrizVetores[i][0]/(float)matrizVetores[j][0]);
	for(int k = 1; k < dimensao && !flag; k++){
	  if(a != (matrizVetores[i][k]/(float)matrizVetores[j][k]))
	    flag = 1;
	}
      }
    }
  }
  return flag;
}

void produtoInterno(float v[], float u[], float proj[]){
  float numerador = 0, denominador = 0,escalar = 0;

  for(int i = 0; i < dimensao; i++)
    numerador += v[i]*u[i];
  for(int i = 0; i < dimensao; i++)
    denominador += u[i]*u[i];

  escalar = (numerador/denominador);

  for(int i = 0; i < dimensao; i++)
    proj[i] = u[i]*escalar;
}

void gramSchmidt(float matrizVetores[MAX][MAX]){
  float proj[dimensao];
  
  for(int i = 1; i < dimensao; i++){
    for(int j =0; j <= (i-1); j++){
      produtoInterno(matrizVetores[i],matrizVetores[j],proj);
      
      for(int k = 0; k < dimensao; k++)
	matrizVetores[i][k] = matrizVetores[i][k] - proj[k];
    }
  }
  
}

int leituraArquivo(float matrizVetores[MAX][MAX]){
  int l = 0,c = 0, flag = 0,result;
  FILE *arq = fopen(URL, "rt");

  if (!arq){
    printf("NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
    return 0;
  }
  
  while(!feof(arq)){
    result = fgetc(arq);
    if(result >= 48 &&  result <= 57){
      matrizVetores[l][c] = (result-48);
      c++;
    }
    
    if(result == ')' && c){
      dimensao = c;
      c=0; 
      l++;	
    } 
  }
  fclose(arq);
  return 1;
}

int main(){
  float matrizVetores[MAX][MAX];
  leituraArquivo(matrizVetores);
  
  gramSchmidt(matrizVetores);
  
  for(int l= 0; l< dimensao; l++){
    for(int c = 0; c < dimensao; c++)
      printf("%f ", matrizVetores[l][c]);
    printf("\n");
  }
  
  return 0;
}
