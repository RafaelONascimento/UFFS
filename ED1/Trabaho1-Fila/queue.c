#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 8

node* start(){
  return NULL;
}
int empty(node* first){
  return (first==NULL)?1:0;
}

int full(node *first, node *last){
  int i = 0;
  node *tmp;

  tmp = first;
  
  while(tmp != NULL){
    i++;
    tmp = tmp->prox;
  }

  return (i >= MAX)?1:0;
}

node* push(int value,node *first, node *last){
  node *tmp;

  tmp = (node*)malloc(sizeof(node));
  
  if(full(first,last) || tmp==NULL){
    return NULL;
  }
  else{
    if(last != NULL)
      last->prox = tmp;
    
    tmp->prox = NULL;
    tmp->num = value;
  }
  return tmp;
}

node* pop(node *first){
  node *tmp;
  if(empty(first))
    return NULL;
  else{
    tmp = first->prox;
    first = NULL;
  }
  return tmp;
}


int main(){
  node *first, *last;

  first = start();
  last = start();

  printf("Lista %s\n",(empty(first))?"vazia":"com intens");
  first = push(8,first,last);
  last = first;
  last = push(8,first,last);
  printf("Lista %s\n",(empty(first))?"vazia":"com intens");
  printf("Lista %sesta cheia\n",(full(first,last))?"":"nao ");
  first = pop(first);
  first = pop(first);
  printf("Lista %s\n",(empty(first))?"vazia":"com intens");
  
  return 0;
}
