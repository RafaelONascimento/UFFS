#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct _contato{
  char nome[40];
  char fone[30];
}TpContato;

typedef struct _lista{
  TpContato valor;
  struct _lista *prox, *ant;
  int index;
} TpLista;

TpLista *buscaCalda(TpLista *head){
  TpLista *current = head;
  while(current->prox != NULL)
    current = current->prox;
  
  return current;
}

TpLista *buscaCabeca(TpLista *head){
  while(head->ant != NULL)
    head = head->ant;
  printf("%p\n",head);
  return head;
}

void mostraLista(TpLista* head){
  TpLista *tmp = buscaCabeca(head);
  
  while(tmp != NULL){
    printf("%s\n",tmp->valor.nome);
    tmp = tmp->prox;
  }
}

void mostraVetor(TpContato array[40]){
  int i;
  printf("Vetor:\n\n");
  
  printf("--------------------\n");
  for(i = 0; i < 40; i++){
    printf("Nome: %s(%d)\n",array[i].nome,strlen(array[i].nome));
    printf("Fone: %s\n",array[i].fone);
    printf("--------------------\n");
  }
}

TpLista *criaLista(TpLista *lista, int *p){
  TpLista *tmp, *cabeca;
  int aux, n, i;
  
  srand((unsigned) time(NULL));
  
  lista = (TpLista*)malloc(sizeof(TpLista));

  printf("Digite a quantidade de contatos\n");
  scanf("%d",&n);

  aux = rand()%9999;
  while(aux < 1000)
    aux = rand()%9999;

  sprintf(lista->valor.nome, "Fulano %d",aux);
  sprintf(lista->valor.fone, "%d",rand()%10000000);
  lista->prox = NULL;
  lista->index = 0;
  lista->ant = NULL;
  cabeca = lista;
  
  for(i = 1;i < n; i++){
    tmp = (TpLista*)malloc(sizeof(TpLista));
    aux = rand()%9999;
    while(aux < 1000)
      aux = rand()%9999;

    sprintf(tmp->valor.nome, "Fulano %d",aux);
    sprintf(tmp->valor.fone, "%d",rand()%10000000);
    tmp->prox = lista;
    tmp->ant = NULL;
    tmp->index = i;
    lista->ant = tmp;
    lista = tmp;
  }
  
  printf("Lista:\n\n");
  mostraLista(cabeca);
  printf("\n");

  *p = n;

  return cabeca;
}

void criaVetor(TpContato vetor[]){
  int i, j, aux;
  
  for(i= 0; i < 40;i++){
    aux = rand()%9999;

    while(aux < 1000)
      aux = rand()%9999;
    
    sprintf(vetor[i].nome, "Fulano %d",aux);
    sprintf(vetor[i].fone, "%d",rand()%99999999);   
  }
  printf("Vetor:\n\n");

  mostraVetor(vetor);

  printf("\n");
}

void quickSortVetor(TpContato vetor[], int esquerda, int direita){
  int i, j;
  TpContato x,y;
  
  i = esquerda;
  j = direita;
  x = vetor[(esquerda+direita)/2];
  
  while(i <= j){
    while(strcmp(vetor[i].nome,x.nome) < 0 && i < direita)
      i++;
    
    while(strcmp(vetor[j].nome,x.nome) > 0 && j > esquerda)
      j--;

    if(i <= j){
      y = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = y;
      i++;
      j--;
    }
  }
  if(j > esquerda)
    quickSortVetor(vetor, esquerda, j);
  if(i < direita)
    quickSortVetor(vetor, i , direita);
}

void troca(TpContato *a, TpContato *b){
  TpContato temp = *a;
  *a = *b;
  *b = temp;
}

TpLista* divide(TpLista *esquerda, TpLista *direita){
  TpContato pivo  = direita->valor;
  TpLista *i = esquerda->ant;
  
  for (TpLista *j = esquerda; j != direita; j = j->prox){
    if (strcmp(j->valor.nome,pivo.nome) <= 0){
      i = (i == NULL)? esquerda : i->prox;
      troca(&(i->valor), &(j->valor));
    }
  }
  i = (i == NULL)? esquerda : i->prox;
  troca(&(i->valor), &(direita->valor));
  
  return i;
}

void quickSortLista(TpLista* esquerda, TpLista *direita){
  if (direita != NULL && esquerda != direita && esquerda != direita->prox){
    TpLista *p = divide(esquerda, direita);
    quickSortLista(esquerda, p->ant);
    quickSortLista(p->prox, direita);
  }
}

void chamaQuickSortLista(TpLista *lista){
  TpLista *calda = buscaCalda(lista);
  TpLista *cabeca = buscaCabeca(lista);
  quickSortLista(cabeca, calda);
}
 
int main(){
  int n = 0, i;
  TpContato vetor[40], a, b;
  TpLista *lista = NULL;
  
  while(n != 5){
    printf("1) Criar Lista\n");
    printf("2) Criar Vetor\n");
    printf("3) Algoritmo a ser estudado\n");
    printf("4) Método logarítmico\n");
    printf("5) Sair\n");

    scanf("%d",&n);
    
    switch(n){
    case 1: lista = criaLista(lista,&i); break;
    case 2: criaVetor(vetor); break;
    case 3: break;
    case 4:
      chamaQuickSortLista(lista);
      mostraLista(lista);
      break;
    case 6:
      break;
    }
  }
}
