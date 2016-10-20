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

raiz* buscaMaiorEsquerda(raiz *nodo){
  if(nodo->dir != NULL)
    buscaMaiorEsquerda(nodo->dir);
  else return nodo;
}

raiz* excluiNodo(raiz *arvore, int valor){
  raiz *nodo, *tmp, **filho, *tmp2 = NULL;

  if(arvore->valor == valor){
    if(arvore->esq == NULL && arvore->dir == NULL) return NULL;
    filho = &arvore;
  }
  else{
    nodo = busca(arvore, valor);
    if(nodo->esq != NULL && nodo->esq->valor==valor) filho = &nodo->esq;
    else filho = &nodo->dir;
  }
  
  if((*filho)->esq == NULL && (*filho)->dir == NULL) *filho = NULL;
  else if((*filho)->esq != NULL && (*filho)->dir == NULL) (*filho) = (*filho)->esq;
  else if((*filho)->esq == NULL && (*filho)->dir != NULL) (*filho) = (*filho)->dir;
  else{
    tmp = buscaMaiorEsquerda((*filho)->esq);
    if((*filho)->esq == tmp && tmp->dir == NULL){
      tmp->dir = (*filho)->dir;
      (*filho) = tmp;
    }
    else{
      tmp->dir->dir= (*filho)->dir;
      if(tmp->dir->esq != NULL) tmp2 = tmp->dir->esq;
      tmp->dir->esq= (*filho)->esq;
      (*filho) = tmp->dir;
      tmp->dir = tmp2;
    }
  }
  return arvore;
}

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
