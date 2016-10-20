#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,m, i, j;
  int *tmp;
  scanf("%d",&n);
  
  int **matriz = (int**)malloc(n * sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%d",&m);
    matriz[i] = (int*)malloc(m * sizeof(int));
    for(j = 0; j < m; j++){
      tmp = matriz[i]+j;
      *tmp = rand()%10;
    }
    tmp++;
    *tmp = -1;
  }

  for(i =0; i < n; i++){
    j = 0;
    printf("%p = ",matriz[i]);
    tmp = matriz[i]+j;
    while(*tmp != -1){
      printf("%d ",*tmp);
      j++;
      tmp = matriz[i]+j;
    }
    printf("\n");
  }

  return 0;
}
