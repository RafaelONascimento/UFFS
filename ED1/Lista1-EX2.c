#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
  int *p, *tmp, *valor;
  int i, j;
  
  p = (int*)malloc(sizeof(int)*(n1+n2));
  
  for(i = 0; i < n1; i++){
    tmp = p+i;
    valor = v1+i;
    *tmp = *valor;
  }
  
  for(j = 0; j < n2; j++,i++){
    tmp = p+i;
    valor = v2+j;
    *tmp = *valor; 
  }

  return p;
}

int main(){
  int v1[5],  v2[8], i , j;
  int *vetorFinal, *tmp;
  
  printf("Digite 5 valores:\n");
  for(i = 0; i < 5; i++){
    printf("#%d = ",(i+1));
    scanf("%d",&v1[i]);
  }
  
  printf("Digite 8 valores:\n");
  for(i = 0; i < 8; i++){
    printf("#%d = ",(i+1));
    scanf("%d",&v2[i]);
  }

  vetorFinal = uniao(v1,5,v2,8);

  printf("Vetor Final:\n");
  for(i = 0; i < 13; i++){
    tmp = vetorFinal+i;
    printf("%d ",*tmp);
  }
  printf("\n");
  free(vetorFinal);
  free(tmp);

  return 0;
}
