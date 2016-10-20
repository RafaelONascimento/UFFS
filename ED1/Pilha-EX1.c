#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 600

void pop(char pilha[], char c, int topo){
  pilha[topo] = ' ';
  topo -= 1;
}

void push(char pilha[], char c, int *topo){
  *topo += 1;
  pilha[*topo] = c;
}

int main(){
  char pilha[MAX], entrada[MAX];
  int topo = -1, i , j , tm, espaco = 0;

  fgets(entrada,MAX,stdin);
  tm = strlen(entrada);
  
  for(i = 0; i < tm; i++){
    if(entrada[i] == ' ' || entrada[i] == '\n'){
      j = i-1;
      while(j >= espaco){
	push(pilha,entrada[j],&topo);
	j--;
      }
      espaco = i;
      push(pilha,entrada[espaco],&topo);
    }
  }

  pilha[tm] = '\0';
  printf("%s\n",pilha);
  
  return 0;
}
