#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
  int info;
  struct _node *next;
  struct _node *prev;
}node;

typedef struct _nodeFather{
  node *group;
  int max, min, index;
  struct _nodeFather *next, *prev;
}nodeFather;

nodeFather* create(nodeFather *groups, int* qtdGroup){
  nodeFather *newGroup;
  node *newElement = NULL, *newElementTmp = NULL;
  int n , i, flag = 0;
  
  if(groups == NULL || (groups->index == -1)){
    groups = (nodeFather*) malloc(sizeof(nodeFather));
    groups->next = NULL;
    groups->prev = NULL;
  }
  
  else{
    newGroup = (nodeFather*) malloc(sizeof(nodeFather));
    groups->next = newGroup;
    newGroup->prev = groups;
    groups = newGroup;
  }
  
  printf("Quantidade de elementos de entrada: ");
  scanf("%d", &n);
  
  while(n--){
    scanf("%d", &i);
    
    if(!flag){
      groups->min = groups->max = i;
      flag = 1;
    }
    else{
      if(groups->min >= i) groups->min = i; 
      else if(groups->max <= i) groups->max = i;
    }
    
    if(newElement == NULL){
      newElement = (node*) malloc(sizeof(node));
      newElement->info = i;
      newElement->prev = newElement->next = NULL;
    }
    else{
      newElementTmp = (node*) malloc(sizeof(node));
      newElementTmp->info = i;
      newElement->next = newElementTmp;
      newElementTmp->prev = newElement;
      newElement = newElementTmp;  
    } 
  }
  
  groups->index = *qtdGroup;
  groups->group = newElement;
  
  return groups;
}

void show(nodeFather *groups){
  nodeFather *tmp;
  node *tmp2;
  tmp = groups;
  
  if(groups == NULL || (groups->index == -1)){
    printf("Não há conjuntos cadastrados ainda!\n");
  }
  else{
    while(tmp->prev != NULL)
      tmp = tmp->prev;
    
    do{
      printf("[%d] = ",tmp->index); 
      
      tmp2 = tmp->group;
      tmp = tmp->next;
      
      if(tmp2 != NULL){
	while(tmp2->prev != NULL)
	  tmp2 = tmp2->prev;
	
	do{
	  printf("%d ", tmp2->info);
	  tmp2 = tmp2->next;
	}while(tmp2 != NULL);	
      }
      else printf("∅");
      
      printf("\n");
      
    }while(tmp != NULL);
  }
}

void delete(nodeFather *groups){
  nodeFather *tmp, *tmp2;
  int groupIndex;
  
  show(groups);
  
  if(groups->index != -1){ 
    printf("-------------------------\n");
    printf("Qual é o indice do grupo a ser excluido:...");
    scanf("%d",&groupIndex);
    tmp = groups;
    
    while(tmp->index != groupIndex)
      tmp = tmp->prev;
    
    if(tmp->prev != NULL && tmp->next != NULL){
      groups = tmp->prev;
      tmp2 = tmp->next;
      
      groups->next = tmp2;
      tmp2->prev = groups;
    }
    else if(tmp->prev == NULL && tmp->next != NULL){
      groups = tmp->next;
      groups->prev = NULL;
    }
    else if(tmp->prev != NULL && tmp->next == NULL){
      groups = tmp->prev;
      groups->next = NULL;
    }
    else if(tmp->prev == NULL && tmp->next == NULL){
      tmp->index = -1;
    }
    
    tmp = NULL;
  }
}

void groupsUnion(nodeFather *groups){
  nodeFather *tmp;
  node *tmp2, *unionTmp = NULL, *tmp3, *newElement;
  int flag = 0;
  
  tmp = groups;
  
  if(groups == NULL || (groups->index == -1))
    printf("Não há conjuntos cadastrados ainda!\n");
  else{
    while(tmp->prev != NULL)
      tmp = tmp->prev;
    do{
      tmp2 = tmp->group;
      tmp = tmp->next;
      if(tmp2 != NULL){
	while(tmp2->prev != NULL)
	  tmp2 = tmp2->prev;
	
	do{
	  if(unionTmp == NULL){
	    unionTmp = (node*) malloc(sizeof(node));
	    unionTmp->info = tmp2->info;
	    unionTmp->prev = unionTmp->next = NULL;
	  }
	  else{
	    tmp3 = unionTmp;
	    flag = 0;
	    do{
	      if(tmp3->info == tmp2->info)
		flag = 1;
	      tmp3 = tmp3->next;
	    }while(tmp3 != NULL && !flag);
	    
	    if(!flag){
	      tmp3 = unionTmp;
	      
	      while(tmp3->next != NULL)
		tmp3 = tmp3->next;
	      
	      newElement = (node*) malloc(sizeof(node));
	      newElement->info = tmp2->info;
	      newElement->next = NULL;
	      newElement->prev = tmp3;
	      tmp3->next = newElement;
	    }
	  }
	  tmp2 = tmp2->next;
	}while(tmp2 != NULL);
      }
    }while(tmp != NULL);
    
    show(groups);
    printf("A uniao dos conjuntos acima é: ");

    if(unionTmp != NULL){
      do{
	printf("%d ",unionTmp->info);
	unionTmp = unionTmp->next;
      }while(unionTmp != NULL);
    }
    else if(unionTmp == NULL){
      printf("∅");
    }
    
    printf("\n");
    printf("Digite ENTER para voltar ao menu.....");
    getchar();
    getchar();
  }
}

void diff(nodeFather *groups){
  int count = 1, flag = 0;
  nodeFather *tmp = groups;
  node *first, *comparar;
  if(groups == NULL || (groups->index == -1)){
    printf("Não há conjutos cadastrados ainda!\n");
  }
  else{
    show(groups);
    
    while(tmp->prev != NULL)
      tmp = tmp->prev;
    
    first = tmp->group;
    if(first != NULL){ 
      while(first->prev != NULL)
	first = first->prev;
      
      while(first->next != NULL){
	count++;
	first = first->next;
      }
      
      int differenceInt[count];
      char differenceChar[count];
      
      while(first->prev != NULL)
	first = first->prev;
      
      for(int i = 0; first != NULL; i++){
	differenceInt[i] = first->info;
	differenceChar[i] = 1;
	first = first->next;
      }
      
      tmp = tmp->next;
      
      for(; tmp != NULL; tmp = tmp->next){
	comparar = tmp->group;
	if(comparar != NULL){
	  while(comparar->prev != NULL)
	    comparar = comparar->prev;
	  
	  while(comparar != NULL){
	    for(int i = 0; i < count; i++){
	    if(comparar->info == differenceInt[i])
	      differenceChar[i] = 0;
	    }
	    comparar = comparar->next;
	  }
	}
      }
      printf("A diferença entre o primeiro conjunto e os demais é: ");
      for(int i = 0; i < count; i++){
	if(differenceChar[i] == 1){
	  flag = 1;
	  printf("%d ", differenceInt[i]);
	}
      }
      
      if(!flag)
	printf("∅");
      
      printf("\n");
    }
    else{
      printf("A diferença entre o primeiro conjunto e os demais é: ∅\n");
    }
  }
}

void intersec(nodeFather *groups){
  nodeFather *tmp;
  node *tmp2, *unionTmp = NULL, *tmp3, *newElement;
  int flag = 0, flag2, flag3, elements = 0;
  
  tmp = groups;
  
  if(groups == NULL || (groups->index == -1)){
    printf("Não há conjuntos cadastrados ainda!\n");
  }
  else{
    while(tmp->prev != NULL)
      tmp = tmp->prev;
    
    groups = tmp;
    do{
      tmp2 = tmp->group;
      tmp = tmp->next;
      if(tmp2 != NULL){
	while(tmp2->prev != NULL)
	  tmp2 = tmp2->prev;
	
	do{
	  if(unionTmp == NULL){
	    unionTmp = (node*) malloc(sizeof(node));
	    unionTmp->info = tmp2->info;
	    unionTmp->prev = unionTmp->next = NULL;
	  }
	  else{
	    tmp3 = unionTmp;
	    flag = 0;
	    do{
	      if(tmp3->info == tmp2->info)
		flag = 1;
	      tmp3 = tmp3->next;
	    }while(tmp3 != NULL && !flag);
	    
	    if(!flag){
	      tmp3 = unionTmp;
	      
	      while(tmp3->next != NULL)
		tmp3 = tmp3->next;
	      
	      newElement = (node*) malloc(sizeof(node));
	      newElement->info = tmp2->info;
	      newElement->next = NULL;
	      newElement->prev = tmp3;
	      tmp3->next = newElement;
	    }
	  }
	  tmp2 = tmp2->next;
	}while(tmp2 != NULL);
      }
    }while(tmp != NULL);
    
    show(groups);
    printf("A intersecção dos conjuntos acima é: ");
    
    
    flag = 0;
    flag2 = 0;

    tmp3 = unionTmp;
    
    if(unionTmp != NULL){
      do{
	tmp = groups;
	flag3 = 1;
	do{
	  if(tmp->group == NULL){
	    flag = 1;
	  }
	  else{
	    flag = 0;
	    flag2 = 0;
	    tmp2 = tmp->group;
	    while(tmp2->prev != NULL)
	      tmp2 = tmp2->prev;
	    
	    do{
	      if(tmp2->info == tmp3->info)
		flag2 = 1;
	      tmp2 = tmp2->next;
	    }while(tmp2 != NULL);
	  }
	  tmp = tmp->next;
	  flag3 &= flag2;
	}while(tmp != NULL && !flag);
	if(flag3){
	  printf("%d ",tmp3->info);
	  elements++;
	}
	tmp3 = tmp3->next;
      }while(tmp3 != NULL && !flag);
    }
    if(!elements)
      printf("∅");
    
    printf("\n");	  
  }
}

int main(){
  int opcao;
  int qtdGroup = 0;
  nodeFather *groups = NULL;
  
  do{
    system("clear");
    printf("-------------------------\n");
    printf("-----------NP1-----------\n");
    printf("---- Eduardo Stefanello--\n");
    printf("---- Rafael Nascimento---\n");
    printf("-------------------------\n");
    printf("- Opções:               -\n");
    printf("- Inserir um Conjunto...1\n");
    printf("- Excluir um Conjunto...2\n");
    printf("- Exibir conjuntos......3\n");
    printf("- Exibir Intersecção....4\n");
    printf("- Exibir União..........5\n");
    printf("- Exibir Diferença......6\n");
    printf("- Finalizar.............7\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    switch (opcao){
    case 1:
      qtdGroup++;
      groups = create(groups, &qtdGroup);
      printf("%p\n", groups->prev);
      break;
    case 2:
      delete(groups);
      break;
    case 4: 
      intersec(groups);
      printf("Digite ENTER para voltar ao menu.....");
      getchar();
      getchar();
      break;
    case 3:
      show(groups);
      printf("Digite ENTER para voltar ao menu.....");
      getchar();
      getchar();
      break;
    case 5:
      groupsUnion(groups);
      break;
    case 6:
      diff(groups);
      printf("Digite ENTER para voltar ao menu.....");
      getchar();
      getchar();
      break;
    case 7:
      printf("               SEE YOU LATER                  \n ");
      printf("░░░░░░░░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄\n");
      printf("░░░█░░░░▄▀█▀▀▄░░▀▀▀▄░░░░▐█░░░░░░░░░▄▀█▀▀▄░░░▀█▄\n");
      printf("░░█░░░░▀░▐▌░░▐▌░░░░░▀░░░▐█░░░░░░░░▀░▐▌░░▐▌░░░░█▀\n");
      printf("░▐▌░░░░░░░▀▄▄▀░░░░░░░░░░▐█▄▄░░░░░░░░░▀▄▄▀░░░░░▐▌\n");
      printf("░█░░░░░░░░░░░░░░░░░░░░░░░░░▀█░░░░░░░░░░░░░░░░░░█\n");
      printf("▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█\n");
      printf("▐█░░░░░░░░░░░░░░░░░░░░░░░░░░█▌░░░░░░░░░░░░░░░░░█\n");
      printf("░█░░░░░░░░░░░░░░░░░░░░█▄░░░▄█░░░░░░░░░░░░░░░░░░█\n");
      printf("░▐▌░░░░░░░░░░░░░░░░░░░░▀███▀░░░░░░░░░░░░░░░░░░▐▌\n");
      printf("░░█░░░░░░░░░░░░░░░░░▀▄░░░░░░░░░░▄▀░░░░░░░░░░░░█\n");
      printf("░░░█░░░░░░░░░░░░░░░░░░▀▄▄▄▄▄▄▄▀▀░░░░░░░░░░░░░█\n");
      break;
    }
  }while(opcao != 7);
  
  return 0;
}
