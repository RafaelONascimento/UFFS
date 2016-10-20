#include <stdio.h>
#include <stdlib.h>

int main(){
  int i = 1, j;

  while(i <= 10){
    j = 1;
    if(i == 1 || i == 3 || i == 4 || i == 10){
      while(j <= 12){
	if(j == 1 || j == 12){
	  printf("+");
	}
	else if((j%2) == 0){
	  printf("/");
	}
	else{
	  printf("\\");
	}
	j++;
      }
    }
    else{
      while(j <= 12){
	if(j == 1 || j== 12){
	  printf("|");
	}
	else{
	  printf(" ");
	}
	j++;
      }
    }

    printf("\n");
    i++;
  }

  return 0; 
}
