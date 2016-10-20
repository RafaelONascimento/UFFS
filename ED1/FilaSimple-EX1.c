#include <stdio.h>
#include <stdlib.h>

struct Node{
  int num;
  struct Node *prox;
};

typedef struct Node node;

typedef struct{
  node *first, *last;
} retorno;

node* push(int value,node *first, node *last){
  node *tmp;

  tmp = (node*)malloc(sizeof(node));
  
  if(tmp==NULL){
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

void printQueue(node *first){
  node *tmp;
  
  tmp = first;
  while(tmp != NULL){
    printf("%d",tmp->num);
    tmp = tmp->prox;
    if(tmp != NULL)
      printf(" ");
  }
  printf("\n");
}

retorno popMidle(node *oldFirst){
  node *tmp, *first, *last, *pre;
  int counter = 0, midle;
  retorno newQueue;
  
  tmp = oldFirst;
  while(tmp != NULL){
    counter++;
    tmp = tmp->prox;
  }

  if((counter%2))
    midle = (counter/2)+1;
  else
    midle = counter/2;
  
  tmp = oldFirst;
  first = oldFirst;
  counter = 0;
  while(tmp != NULL){
    counter++;  
    if(counter == midle){
      pre->prox = tmp->prox;
      free(tmp);
      tmp =  pre;
    }
    if(tmp->prox == NULL) last = tmp;
    pre = tmp;
    tmp = tmp->prox;
  }
  
  newQueue.first = first;
  newQueue.last = last;

  return newQueue;
  }


int main(){
  node *first, *last;
  retorno popMidleQueue;
  first = NULL;
  last = NULL;
  first = push(8,first,last);
  last = first;
  last = push(9,first,last);
  last = push(10,first,last);
  last = push(11,first,last);
  last = push(12,first,last);
 
  printQueue(first);
  
  popMidleQueue = popMidle(first);
  first = popMidleQueue.first;
  last = popMidleQueue.last;
  
  printQueue(first);
  
  return 0;
}
