#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j,k;

  for(i=1; i <= 7; i++){
    for(j=1; j <= i; j++){
      printf("%d",j);
    }

    for(k=1; k <= (7-i); k++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
