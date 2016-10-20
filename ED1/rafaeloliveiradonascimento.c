#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99999

typedef struct _doubleLinkedList{
  int value;
  struct _doubleLinkedList *next, *prev;
}dLinkedList;

void arrayInsertionSort(int array[],int number){ 
  int i, j, key;
  
  for(i = 0; i < number; i++){
    key = array[i];
    j = i-1;
    while(j>=0 && array[j]>key){
      array[j+1] = array[j];
      j = j-1;
    }
    array[j+1] = key;
  }
}

void arrayBubbleSort(int array[],int number){
  int flag, i;
 
  do{
    flag = 0;
    for(i = 1; i < number; i++){
      if(array[i-1]>array[i]){
	//bit to bit change
	array[i-1] ^= array[i];
	array[i] ^= array[i-1];
	array[i-1] ^= array[i];
	flag = 1;
      }
    }
  }while(flag);
}

dLinkedList *listInsertionSort(dLinkedList *list){ 
  dLinkedList *tmp,*tmp2, *head = NULL;
  int i, j, key;
  
  head = list;
 
  while(head->prev != NULL)
    head = head->prev;
  tmp2 = head;
  
  for(head = head->next;head != NULL;head = head->next){
    key = head->value;
    tmp = head->prev;
    
    while(tmp && tmp->value > key){
      tmp->next->value = tmp->value;
      tmp = tmp->prev;
    }
    
    if(tmp == NULL)tmp2->value = key;
    else tmp->next->value = key;
  }
  return tmp2;
}

dLinkedList *listBubbleSort(dLinkedList *list){
  int flag, i;
  dLinkedList *tmp, *head;

  head = list;

  while(head->prev != NULL)
    head = head->prev;
  
  do{
    flag = 0;
    tmp = head;
    for(tmp = tmp->next; tmp != NULL; tmp = tmp->next){
      if(tmp->prev->value > tmp->value){
	tmp->prev->value ^= tmp->value;
	tmp->value ^= tmp->prev->value;
	tmp->prev->value ^= tmp->value;
	flag = 1;
      }
    }
  }while(flag);
  
  return head;
}

dLinkedList *push(dLinkedList *list, int value){
  dLinkedList *tmp;
  
  if(list == NULL){
    tmp = (dLinkedList*)malloc(sizeof(dLinkedList));
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->value = value;
  }
  else{
    tmp = list;

    while(tmp->next != NULL)
      tmp = tmp->next;

    list = tmp;
    tmp = (dLinkedList*)malloc(sizeof(dLinkedList));
    tmp->next = NULL;
    tmp->prev = list;
    tmp->value = value;
    list->next = tmp;
  }
  return tmp;
}

dLinkedList *clearList(dLinkedList *list){
  dLinkedList *tmp, *tmp2;

  tmp = list;
    
  while(tmp->next != NULL)
    tmp = tmp->next;
  
  while(tmp != NULL){
    tmp2 = tmp;
    free(tmp2);
    tmp = tmp->next;
  }
  return tmp;
}

void printList(dLinkedList *list){
  dLinkedList *tmp;

  while(list->prev != NULL)
    list = list->prev;

  tmp = list;

  while(tmp != NULL){
    printf("%d\n",tmp->value);
    tmp = tmp->next;
  }
}

int main(){
  int i , flag = 0;
  int array[MAX];
  dLinkedList *list = NULL;

  printf("Do you want see the values after the ordination?\n");
  printf("(1 = Yes)(0 = No): ");
  scanf("%d",&flag);
  
  //#InsertionSort on Array
  for(i = 0; i < MAX; i++)
    array[i] = rand()%MAX;
  clock_t start = clock();
  arrayInsertionSort(array, MAX);
  clock_t end = clock();
  double timeInsertion = (end-start)*(1000.0 / CLOCKS_PER_SEC);
  //printing the array
  if(flag){
    printf("########InsertionSort on Array\n");
    for(i = 0; i < MAX ;i++)
      printf("%d\n",array[i]);
  }
  
  //#BubbleSort on Array
  for(i = 0; i < MAX; i++)
    array[i] = rand()%MAX;
  start = clock();
  arrayBubbleSort(array, MAX);
  end = clock();
  double timeBubbleSort = (end-start)*(1000.0 / CLOCKS_PER_SEC);
  //printing the array
  if(flag){
    printf("########BubbleSort on Array\n");
    for(i = 0; i < MAX ;i++)
      printf("%d\n",array[i]);
  }
  
  //#InsertionSort on LinkedList
  //Pushing elements in the list
  for(i = 0; i < MAX; i++)
    list = push(list,rand()%MAX);
  //Calling insertionSort
  start = clock();  
  list = listInsertionSort(list);
  end = clock();
  double timeInsertionList = (end-start)*(1000.0 / CLOCKS_PER_SEC);
  //Printing the list
  if(flag){
    printf("########InsertionSort on DoubleLinkedList\n");
    printList(list);
  }
  //#BubbbleSort on LinkedList
  //Turn the list empty again
  list  = clearList(list);
  //Fill the list
  for(i = 0; i < MAX; i++)
    list = push(list,rand()%MAX);
  //Calling of bubbleSort
  start = clock();  
  list = listBubbleSort(list);
  end = clock();
  double timeBubbleSortList = (end-start)*(1000.0 / CLOCKS_PER_SEC);
  //Printing the list
  if(flag){
    printf("########BubbleSort on DoubleLinkedList\n");
    printList(list);
  }
  
  printf("|-------------------------------------------------|\n");
  printf("| SORT TYPE     | DATA STRUCTURE     | TIME       |\n");
  printf("|-------------------------------------------------|\n");
  printf("| InsertionSort | Array              | %lf ms|\n",timeInsertion);
  printf("| InsertionSort | Double Linked List | %lf ms|\n",timeInsertionList);
  printf("| BubbleSort    | Array              | %lf ms|\n",timeBubbleSort);
  printf("| BubbleSort    | Double Linked List | %lf ms|\n",timeBubbleSortList);
  return 0;
}
