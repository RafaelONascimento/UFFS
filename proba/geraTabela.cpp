#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long llu;

llu fact(llu f){
  if (f == 0) return 1;
  return(f * fact(f - 1));
}

double exp(double n, llu x){
  float final;
  if(x != 0){
    final = n;
    x--;
    while(x--) final *= n;
  
    return final;
  }
  else return 1;
}

unsigned long long int comb(unsigned int n, unsigned int p) {
  if(p>n) return 0;
  else return fact(n)/(fact(n-p)*fact(p));
  return 0;
}

double binomialSimples(llu n, double p, llu x){
  return  comb(n,x)*exp(p,x)*exp(1-p,abs(n-x));
}

double binomialAcumulado(llu n, double p, llu x){
  double final = 0;
  for(int i = 0; i <= n; i++ )
    final = binomialSimples(i,p,x);
  return final;
}

int main(){
  int op = 1;
  llu n,x;
  double p;
  
  do{
    printf("1)Individual\n");
    printf("2)Acumulada\n");
    printf("Digite a sua opcao...\n");
    scanf("%d",&op);
    printf("Digite N P X:\n");
    scanf("%llu %lf %llu",&n,&p,&x);
   
    switch(op){
    case 1:
      printf("%.4lf\n",binomialSimples(n,p,x));
      break;
    case 2:
      printf("%.4lf\n",binomialAcumulado(n,p,x));
      break;
    }
  } while(op > 0 && op < 3);
  
  return 0;
}
