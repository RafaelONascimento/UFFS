#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define URL "ortogonaliza4.txt"

int dimensao;

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
  printf("%f\n",Determinant(matrizVetores,(dimensao)));
  
    if(Determinant(matrizVetores,dimensao)){
      gramSchmidt(matrizVetores);
    }
  
  
  for(int l= 0; l< dimensao; l++){
    for(int c = 0; c < dimensao; c++)
      printf("%f ", matrizVetores[l][c]);
    printf("\n");
  }
  
  return 0;
}
