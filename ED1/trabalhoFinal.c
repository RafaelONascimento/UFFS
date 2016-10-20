#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define VEC 40

typedef struct _contato{
  char nome[40];
  char fone[30];
}TpContato;

typedef struct _lista{
  TpContato valor;
  struct _lista *prox, *ant;
  int index;
} TpLista;

//Buscas na lista
TpLista *buscaCauda(TpLista *head){
  TpLista *current = head;
  while(current->prox != NULL)
    current = current->prox;

  return current;
}

TpLista *buscaCabeca(TpLista *head){
  while(head->ant != NULL)
    head = head->ant;
  return head;
}


//Criacao e preenchimento de estruturas
TpLista *criaLista(TpLista *lista){
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
    aux = rand()%9999;
    while(aux < 1000)
      aux = rand()%9999;

    tmp = (TpLista*)malloc(sizeof(TpLista));
    sprintf(tmp->valor.nome, "Fulano %d",aux);
    sprintf(tmp->valor.fone, "%d",rand()%10000000);
    tmp->index = i;
    tmp->ant = lista;
    tmp->prox = NULL;
    lista->prox = tmp;
    lista = tmp;
  }

  return cabeca;
}

TpLista *criaListaAuxiliar(TpLista *lista){
  TpLista *tmp, *cabeca, *novaLista, *tmp2;

  lista  = buscaCabeca(lista);

  srand((unsigned) time(NULL));

  if(lista != NULL){
    novaLista = (TpLista*)malloc(sizeof(TpLista));

    strcpy(novaLista->valor.nome,lista->valor.nome);
    strcpy(novaLista->valor.fone,lista->valor.fone);
    novaLista->prox = NULL;
    novaLista->index = 0;
    novaLista->ant = NULL;
    cabeca = novaLista;

    for(tmp2 = lista->prox; tmp2 != NULL; tmp2 = tmp2->prox){
      tmp = (TpLista*)malloc(sizeof(TpLista));
      strcpy(tmp->valor.nome,tmp2->valor.nome);
      strcpy(tmp->valor.fone,tmp2->valor.fone);
      tmp->index = tmp2->index;
      tmp->ant = novaLista;
      tmp->prox = NULL;
      novaLista->prox = tmp;
      novaLista = tmp;
    }
  }
  return cabeca;
}

void criaVetor(TpContato vetor[]){
  int i, j, aux;

  for(i= 0; i < VEC;i++){
    aux = rand()%9999;

    while(aux < 1000)
      aux = rand()%9999;

    sprintf(vetor[i].nome, "Fulano %d",aux);
    sprintf(vetor[i].fone, "%d",rand()%99999999);
  }

}

void criaVetorAuxiliar(TpContato vetor[],TpContato vetorTmp[]){
  int i;

  for(i = 0; i < VEC; i++)
    vetorTmp[i] = vetor[i];
}

//Exclusao de estruturas
TpLista *excluiLista(TpLista *lista){
  TpLista *tmp;
  lista = buscaCauda(lista);

  while(lista != NULL){
    tmp = lista;
    lista = lista->ant;
    free(tmp);
  }

  return lista;
}

//Apresentacao dos dados das estruturas
void mostraLista(TpLista* head){
  TpLista *tmp = buscaCabeca(head);

  printf("Lista:\n\n");
  printf("--------------------\n");
  while(tmp != NULL){
    printf("Nome: %s\n",tmp->valor.nome);
    printf("Fone: %s\n",tmp->valor.fone);
    printf("--------------------\n");
    tmp = tmp->prox;
  }
}

void mostraVetor(TpContato array[VEC]){
  int i;
  printf("Vetor:\n\n");

  printf("--------------------\n");
  for(i = 0; i < VEC; i++){
    printf("Nome: %s\n",array[i].nome,strlen(array[i].nome));
    printf("Fone: %s\n",array[i].fone);
    printf("--------------------\n");
  }
}

//Ordenacao de vetores
void gnomeSortVetor(TpContato vetor[]){
  int ant = 0, prox = 0, i;
  TpContato x;

  for(i = 0; i < VEC - 1; i++){
    if(strcmp(vetor[i].nome, vetor[i + 1].nome) > 0){
      ant = i; prox = i + 1;

      while(strcmp(vetor[ant].nome, vetor[prox].nome) > 0){
	x = vetor[ant];
	vetor[ant] = vetor[prox];
	vetor[prox] = x;

	if(ant > 0) ant--;
	if(prox > 0) prox--;
      }
    }
  }
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

//Ordenacao de listas
//GnomeSort
TpLista gnomeSortLista(TpLista *lista){
  int i, tamanho = 0;
  char auxiliarNome[VEC], auxiliarFone[VEC];

  //CONTA LISTA:
  for(tamanho = 0; lista->prox != NULL; lista = lista->prox) tamanho++;

  for(i = 0; i < tamanho; i++){
    //VOLTA LISTA:
    while(lista->index > 0) lista = lista->ant;

    //ACESSA 'Lista[i]':
    while(lista->prox != NULL && lista->index < i) lista = lista->prox;
    
    if(strcmp(lista->valor.nome, lista->prox->valor.nome) > 0){
      while(strcmp(lista->valor.nome, lista->prox->valor.nome) > 0){
	//TROCA:
	strcpy(auxiliarNome, lista->valor.nome);
	strcpy(auxiliarFone, lista->valor.fone);
	strcpy(lista->valor.nome, lista->prox->valor.nome);
	strcpy(lista->valor.fone, lista->prox->valor.fone);
	strcpy(lista->prox->valor.nome, auxiliarNome);
	strcpy(lista->prox->valor.fone, auxiliarFone);
	//VOLTA 1:
	if(lista->index > 0) lista = lista->ant;
      }
    }
  }
  //VOLTA LISTA:
  while(lista->index > 0) lista = lista->ant;

  return *lista;
}

//QuickSort
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
  TpLista *calda = buscaCauda(lista);
  TpLista *cabeca = buscaCabeca(lista);
  quickSortLista(cabeca, calda);
}

//Funcao principal
int main(){
  int n = 0, i, flag = 0;
  TpContato vetor[VEC],vetorTmp[VEC], a, b;
  TpLista *lista = NULL, *listaTmp = NULL;
  clock_t comeco, fim;
  double tempo;

  while(n != 5){
    printf("1) Criar Lista\n");
    printf("2) Criar Vetor\n");
    printf("3) Algoritmo a ser estudado\n");
    printf("4) Método logarítmico\n");
    printf("5) Sair\n");

    scanf("%d",&n);

    switch(n){
    case 1:
      if(lista == NULL) lista = criaLista(lista);
      mostraLista(lista);
      printf("\n");
      break;
    case 2:
      flag = 1;
      criaVetor(vetor);
      mostraVetor(vetor);
      printf("\n");
      break;
    case 3:
      //Vetor
      if(flag){
	criaVetorAuxiliar(vetor,vetorTmp);
	comeco = clock();
	gnomeSortVetor(vetorTmp);
	fim = clock();
	mostraVetor(vetorTmp);
	tempo = ((fim-comeco) / CLOCKS_PER_SEC);
	printf("Tempo = %.0lf segs.\n\n",tempo);
      }
      //Lista
      listaTmp = criaListaAuxiliar(lista);
      comeco = clock();
      gnomeSortLista(listaTmp);
      fim = clock();
      mostraLista(listaTmp);
      excluiLista(listaTmp);
      tempo = ((fim-comeco) / CLOCKS_PER_SEC);
      printf("Tempo = %.0lf segs.\n\n",tempo);
      break;
    case 4:
      //Vetor
      if(flag){
	criaVetorAuxiliar(vetor,vetorTmp);
	comeco = clock();
	quickSortVetor(vetor,0,VEC-1);
	fim = clock();
	mostraVetor(vetor);
	tempo = ((fim-comeco) / CLOCKS_PER_SEC);
	printf("Tempo = %.0lf segs.\n\n",tempo);
      }
      //Lista
      listaTmp = criaListaAuxiliar(lista);
      comeco = clock();
      chamaQuickSortLista(listaTmp);
      fim = clock();
      mostraLista(listaTmp);
      excluiLista(listaTmp);
      tempo = ((fim-comeco) / CLOCKS_PER_SEC);
      printf("Tempo = %.0lf segs.\n\n",tempo);
      break;
    case 5:
      excluiLista(lista);
      break;
    }
  }
}
