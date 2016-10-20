#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x, y;
} ponto;

int area(ponto a,ponto b,ponto c){
  return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y)));
}
 
int verificacao(ponto a, ponto b, ponto c,ponto r){   
   int A = area(a,b,c);
   int A1 = area(r,b,c);
   int A2 = area(a,r,c);
   int A3 = area(a,b,r);
   printf("A1 = %d\nA2 = %d\nA3 = %d\nA4 = %d\n",A,A1,A2,A3);
   return (A == A1 + A2 + A3);
}
 
int main(){
  int  i, j;
  ponto pontos[4];

  while(scanf()){
    
  if(verificacao(pontos[0],pontos[1],pontos[2],pontos[3])) printf("Dentro\n");
  else printf ("Fora\n");

  ponto tmp;
    
  return 0;
}
