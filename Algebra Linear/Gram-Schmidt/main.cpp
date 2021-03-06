#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100
#define URL "ortogonaliza.txt"

int dimensao = 0;

float Determinant(float a[MAX][MAX],int n){
  int i,j,j1,j2;
  float det = 0;
  float m[MAX][MAX];
  
  if (n < 1) {
  } else if (n == 1) { 
    det = a[0][0];
  } else if (n == 2) {
    det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
  } else {
    det = 0;
    for (j1=0;j1<n;j1++) {
      for (i=1;i<n;i++) {
	j2 = 0;
	for (j=0;j<n;j++) {
	  if (j == j1) continue;
	  m[i-1][j2] = a[i][j];
	  j2++;
	}
      }
      det += pow(-1.0,1.0+j1+1.0) * a[0][j1] * Determinant(m,n-1);
    }
  }
  return(det);
}

void produtoInterno(float v[], float u[], float proj[]){
  float numerador = 0, denominador = 0,escalar = 0;

  for(int i = 0; i < dimensao; i++)
    numerador += v[i]*u[i];
  for(int i = 0; i < dimensao; i++)
    denominador += u[i]*u[i];
  
  escalar = (numerador/denominador);
  for(int i = 0; i < dimensao; i++){
    proj[i] = u[i]*escalar;
  }
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

int leituraArquivo(float Matriz[MAX][MAX]){
  char s[2] = ",";
  char *coluna;  
  char linha[130]; 
  char *result;  

  FILE *fMatriz;

  int j= 0, i= 0;

  if((fMatriz = fopen(URL,"r")) != NULL) {
    i = 0;
    while (!feof(fMatriz) && i < 100){ 	     
      result = fgets(linha, 130, fMatriz); 
      if(!(linha[0] == '/' && linha[1] == '/')){
	linha[0]=',';
	if (result){
	  coluna = strtok(result, s); 
	}else
	  break;
	
	j = 0;
	
	while( coluna != NULL ){ 
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
    return 1;
  }
  else{
    return 0;
  }
}

int saidaNoArquivo(float matrizVetores[MAX][MAX]){
  FILE *f = fopen(URL,"a+");
  
  if(f != NULL){
    for(int i = 0; i < dimensao; i++){
      fprintf(f,"(");
      for(int j = 0; j < dimensao; j++){
	fprintf(f,"%.4f",matrizVetores[i][j]);
	if(j != (dimensao-1)) fprintf(f,",");
      }
      fprintf(f,")\n");
    }
    fclose(f);
    return 1;
  }
  return 0;
}

int main(){
  float matrizVetores[MAX][MAX];
  if(leituraArquivo(matrizVetores)){
    if(Determinant(matrizVetores,dimensao)){
      gramSchmidt(matrizVetores);

      if(saidaNoArquivo(matrizVetores))
	printf("SUCESSO: Os novos vetores foram escritos no arquivo!\n");
      else
	printf("ERRO: Aquivo 'ortogonaliza.txt' nao encontrado na pasta!\n");
    }
    else{
      printf("ERRO: Vetores informados não são linearmente independentes!\n");
    }
  }
  else{
    printf("ERRO: Aquivo 'ortogonaliza.txt' nao encontrado na pasta!\n");
  }
  return 0;
}
