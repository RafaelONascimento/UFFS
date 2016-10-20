#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int valor;
  struct node *esq, *dir;
}raiz;


int menu(){
  int op;
  printf("Selecione uma opção:\n");
  printf("1 - Inserir elemento na arvore\n");
  printf("2- Imprimir arvore\n");
  printf("3- Remover elemento\n");
  printf("4- Sair\n");
  printf("Op: "); scanf("%d", &op);
  return op;
}

void imprimePonto(int n){
  int i;
  for (i = 0; i < n; i++) printf(".");
}

int lerValor(){
  int valor;
  printf("Informe o valor que deseja inserir na arvore: ");
  scanf("%d", &valor);
  return valor;
}

void inserirFolha(raiz **arvore, int valor){
  if (*arvore == NULL){
    (*arvore) = (raiz *)malloc(sizeof(raiz));
    (*arvore)->valor = valor;
    (*arvore)->esq = (*arvore)->dir = NULL;
    return ;
  }
  if (valor < (*arvore)->valor){ inserirFolha(&(*arvore)->esq, valor); return ; }
  inserirFolha(&(*arvore)->dir, valor);
}

void imprimeArvore(raiz *arvore, int nivel){
  if (arvore == NULL) return ;
  imprimePonto(nivel * 2 + 2);
  printf("%d\n", arvore->valor);
  imprimeArvore(arvore->esq, nivel + 1);
  imprimeArvore(arvore->dir, nivel+1);
}

void finalizaArvore(raiz **arvore){
  if (*arvore == NULL) return ;
  finalizaArvore(&(*arvore)->esq);
  finalizaArvore(&(*arvore)->dir);
  *arvore = NULL;
}

raiz* busca(raiz *nodo, int valor){
  if(nodo->esq != NULL && nodo->esq->valor == valor)
    return nodo; 
  else if(nodo->dir != NULL && nodo->dir->valor == valor)
    return nodo;
  else if(nodo->dir != NULL && nodo->valor < valor)
    busca(nodo->dir,valor);
  else if(nodo->esq != NULL && nodo->valor > valor)
    busca(nodo->esq,valor);
}

//**************************************************************************/
raiz* buscaMaiorEsquerda(raiz *nodo){
  if(nodo->dir != NULL && nodo->dir->dir)
    buscaMaiorEsquerda(nodo->dir);
  else return nodo;
}
/*
raiz* exclusaoCaso1(raiz* nodo){
  tmp2 = buscaMaiorEsquerda(tmp->esq);
  if(tmp->esq == tmp2 && tmp->esq->dir == NULL){
    tmp2->dir = tmp->dir;
    free(tmp);
    if(dir == 1) nodo->esq = tmp2;
    else nodo->dir = tmp2; 
  }
  else{
    tmp3 = tmp2->dir;
    tmp2->dir = tmp3->esq;
    tmp3->dir = tmp->dir;
    tmp3->esq = tmp->esq;
    if(dir == 1) nodo->esq = tmp3;
    else nodo->dir = tmp3; 
  }
}
*/
raiz* excluiNodo(raiz *arvore, int valor){
  raiz *nodo, *tmp, *tmp2, *tmp3;
  int flag = 0, dir = 0;
  
  if(arvore->valor == valor){
    nodo = arvore;
    flag = 1;
  }
  else nodo = busca(arvore, valor);
  
  if(!flag){
    if(nodo->esq != NULL && nodo->esq->valor==valor){
      tmp = nodo->esq;
      dir = 1;  
    }
    else tmp = nodo->dir;
    
    if(tmp->esq == NULL && tmp->dir == NULL){
      if(dir == 1) nodo->esq = NULL;
      else nodo->dir = NULL;
      
      free(tmp);
    }
     else if(tmp->esq != NULL && tmp->dir == NULL){
      if(dir == 1) nodo->esq = tmp->esq;
      else nodo->dir = tmp->esq; 
      free(tmp);
    }
    else if(tmp->esq == NULL && tmp->dir != NULL){
      if(dir == 1) nodo->esq = tmp->dir;
      else nodo->dir = tmp->dir; 
      free(tmp);
    }
    else{
      if(tmp->esq != NULL){
	tmp2 = buscaMaiorEsquerda(tmp->esq);
	if(tmp->esq == tmp2 && tmp->esq->dir == NULL){
	  tmp2->dir = tmp->dir;
	  free(tmp);
	  if(dir == 1) nodo->esq = tmp2;
	  else nodo->dir = tmp2; 
	}
	else{
	  tmp3 = tmp2->dir;
	  tmp2->dir = tmp3->esq;
	  tmp3->dir = tmp->dir;
	  tmp3->esq = tmp->esq;
	  if(dir == 1) nodo->esq = tmp3;
	  else nodo->dir = tmp3; 
	}
      }
      else if(tmp->dir!=NULL){
	if(dir == 1) nodo->esq = tmp->dir;
	else nodo->dir = tmp->dir; 
	free(tmp);
      }
    }
  }
  else{
    if(nodo->esq != NULL){
      tmp = buscaMaiorEsquerda(nodo->esq);
      if(nodo->esq == tmp && nodo->esq->dir == NULL){
	tmp->dir = nodo->dir;
	free(nodo);
	arvore = tmp;
      }
      else{
	tmp2 = tmp->dir;
	tmp->dir = tmp2->esq;
	tmp2->dir = nodo->dir;
	tmp2->esq = nodo->esq;
	free(nodo);
	arvore = tmp2;
      }
    }
    else if(nodo->dir!=NULL){
      arvore = nodo->dir;
      free(nodo);
    }
  }
  return arvore;
}
//**************************************************************************/
 
int main(void){
  int op, num;
  raiz *arvore = NULL, *tmp;
  inserirFolha(&arvore, 5);
  inserirFolha(&arvore, 10);
  inserirFolha(&arvore, 1);
  inserirFolha(&arvore, 20);

  while (op = menu(), op != 4){
    switch(op){
    case 1:

      num = lerValor();
      inserirFolha(&arvore, num);
      printf("ELEMENTO INSERIDO COM SUCESSO!\n\n");
      break;
    case 2:

      printf("ARVORE IMPRESSA:\n");
      imprimeArvore(arvore, 0);
      printf("\n");
      break;
    case 3:
      num = lerValor();
      arvore = excluiNodo(arvore,num);
      // arvore = removet(arvore, num);
      break;
    }
  }
  finalizaArvore(&arvore);
  return 0;
}
