#include <stdio.h>
#include <stdlib.h>

int main(){
  int numero, i = 9, k = 1,  j, flag = 0;
  
  while(i != 0){
    j = i;
    while(j != 0){
      printf(" ");
      j--;
    }
    
    j=1;
    while(j <= flag){
      printf("%d",j);
      j++;
    }
    while(j != 0){
      printf("%d",j);
      j--;
    }

    printf("\n");
    i--;
    flag++;
  }
  
  while(i != 10){
    j = i;
    while(j != 0){
      printf(" ");
      j--;
    }
    j = 1;
    while(j <= (9-i)){
       printf("%d",j);
       j++;
    }
   
    printf("\n");
    
    i++;
  }
  
  return 0;
}