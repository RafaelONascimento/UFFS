#include <stdio.h>
#include <stlib.h>

int main(){
  char nome[20] = "Rafael", nomeB[20];
  int i;
  
  for(i = 0; i < 20 && nome[i] != '\0';i++){
    nomeB[i] = nome[i];
  } 
  nomeB[i] = '\0';
  printf("%s\n",nomeb);
  return 0;
}
