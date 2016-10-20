#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int saldo;
  int conta;
  int senha;
  char nome[50];
  int n_operacoes_realizadas;
} usuarios;

void validaUsuario(usuarios vet[100], char nome[50], int senha, usuarios *retorno){
  int i, flag = 0;

  for(i = 0; i < 100; i++){
    if(strcmp(vet[i].nome,nome) == 0 && vet[i].senha == senha){
      *retorno = vet[i];
      flag = 1;
      break;
    }
  }

  if(flag == 0){
    usuarios zero;
    zero.conta = 0;
    *retorno = zero;
  }
}

int main(){
  char nome[50] = "joao";
  usuarios vet[100];
  
  strcpy(vet[0].nome,nome);
  vet[0].senha = 123345;
  vet[0].conta = 30;
  
  int senha = 123345;

  usuarios user;
  
  validaUsuario(vet,nome,senha,&user);
  

  printf("%d\n",user.conta);

  return 0;
}
  
