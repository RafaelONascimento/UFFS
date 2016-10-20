#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

using namespace std;

int menu(){
  int op;
  printf("Selecione uma opção:\n");
  printf("1 - Inserir elemento na arvore\n");
  printf("2- Imprimir arvore\n");
  printf("3- Remover elemento\n");
  printf("0- Sair\n");
  printf("Op: "); scanf("%d", &op);
  return op;
}

int main(void){
  
  Node* tree = CreateEmptyTree();
  bool _exit = false;
  int value, opcao = 5;
  
  while(opcao = menu(), opcao){
    switch(opcao){
       case 1:
	 printf("Digite o valor: ");
	 scanf("%d",&value);
	 CreateNode(value, &tree);
	 tree = Balance(tree);
	 break;
       case 2:
	 printTree(tree,0);
	 break;
    case 3:
         printf("Digite o valor: ");
         scanf("%d",&value);
	 tree = excluiNodo(tree,value);
	 tree = Balance(tree);
	 break;	 
    } 
  }

  return 0;
}
