#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  Node *next;
};

typedef struct Node node;

node* start(){
  return NULL;
}

node* pushMidle(node *head, int value, int filter){
  node *tmp, *pre , *finish;

  tmp = head;
  pre = head;
  while(tmp != NULL){
    if(tmp->value == filter){
      finish = (node*)malloc(sizeof(node));
      pre->next = finish;
      finish->next = tmp;
      finish->value = value;
      break;
      tmp = NULL;
    }
    else{
      pre = tmp;
      tmp = tmp->next;
    }
  }

  return head;
}

node* pushFront(node *head, int value){
  node *tmp;
  
  tmp = (node*)malloc(sizeof(node));
  tmp->value = value;
  tmp->next = head;
  
  return tmp;
}

node* push(node *head, int value){
  node *tmp, *blank;

  tmp = head;
  
  blank = (node*)malloc(sizeof(node));
  blank->value = value;
  blank->next = NULL;

  if(head == NULL){
    head = blank;
  }
  else{
    while(tmp != NULL){
      if(tmp->next == NULL){	
	tmp->next = blank;
	tmp = NULL;
	break;
    }
      else{
	tmp = tmp->next;
      }
    }
  }
  return head;
}

void printList(node *head){
  node *tmp = head;

  while(tmp != NULL){
    printf("Value = %d\n",tmp->value);
    tmp = tmp->next;
  }
  
}

node* pop(node *head, int value){
  node *pre, *tmp;

  tmp = head;
  pre = head;
  while(tmp != NULL){
    if(tmp->value == value){
      if(tmp == head){
	if(head->next != NULL)
	  head = head->next;
	else
	  head = NULL;
      }
      else{
	pre->next = tmp->next;
	tmp == NULL;
      }
    }
    pre = tmp;
    tmp = tmp->next;
  }
  return head;
}
 
int main(){
  node *head;
  head = start();
  head = push(head,8);
  head = push(head,9);
  head = push(head,10);
  head = push(head,11);
  head = pushMidle(head ,12, 11);
  head = pushFront(head, 13);
  head = pop(head, 9);
  printList(head);
 
  return 0;
}
