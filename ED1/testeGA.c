#include <stdio.h>
#include <stdlib.h>

 int teste(int vetor[]){
   int i;
   for(i = 0; i < 80; i++) vetor[i] = 0;
   return 0;
 }


 int main(){
   int vetor[80], i;

   for(i = 0; i < 80; i++) vetor[i] = i;

   teste(vetor);

   for(i = 0; i < 80; i++)
     printf("%d\n",vetor[i]);

   return 0;
 }
