#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int matricula,i;
  float media;

  for(i = 1; i <= 75; i++){
    printf("Digite o numero da matricula(#%d):\n",i);
    scanf("%d",&matricula);
    printf("Digite a nota:\n");
    scanf("%f",&media);
    
    if(media >= 9 && media <= 10){
      printf("Conceito A\n");
    }
    else if(media >= 7 && media <= 8.9){
      printf("Conceito B\n");
    }
    else if(media >= 5 && media <= 6.9){
      printf("Conceito C\n");
    }
    else if(media <= 4.9){
      printf("Conceito D\n");
    }
  }

  return 0;
}
