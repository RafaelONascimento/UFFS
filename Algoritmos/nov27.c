#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int base;
  int altura;
} area;

void teste(area vet[100],area *maiorbase, area *menoraltura){
  int i;
  maiorbase = &vet[0];
  menoraltura = &vet[0];
  
  for(i=0; i < 100; i++){
    if((vet[i].base) > maiorbase->base)
      maiorbase = &vet[i];
    if((vet[i].altura) < maiorbase->altura)
      menoraltura = &vet[i];
  }
}

int main(){
  area vet[100], a, b;
  int i, j;

  for(i = 99, j = 0; j < 100; i--, j++){
    vet[j].base = i;
    vet[j].altura = i+1;
  }
  
  teste(&vet[100],&a,&b);
}
