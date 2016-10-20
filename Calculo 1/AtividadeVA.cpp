#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD  100
#define MAXE -100

double f(double x){
  //old function
  //  return cos(2*x)+pow(2,x)-pow(x,2)-(1.0/3.0);
  //new fucking one
  return sin(x)/*-x+pow(M_E,x)-2*/;
}


int main(){
  double e = pow(10,-5),a,b,xi;
  int flag = 0,fa,fb,fxi,n;
  n = ((log10(MAXD-MAXE)-log10(e))/log10(2))+1;

  a = MAXE;
  b = MAXD;

  printf("%d(%.80g)\n",n,f(0));
  
  while(n-- && !flag){
    xi = (a+b)/2.0;
    if(f(xi) == 0) flag = 1;
    else{
      fxi = (f(xi) >= 0)? 1:-1;
      fa = (f(a) >= 0)? 1:-1;
      fb = (f(b) >= 0)? 1: -1;
      printf("|%d|%.80g|%.80g|%.80|%d|%d|%d|\n",n,a,b,xi,fa,fb,fxi);
      if((fa*fxi) > 0) a = xi;
      else b = xi;	
    }
  }

  if(!flag) printf("Limite: %lf || %lf\n",a,b);
  else printf("Raiz: %lf\n",xi);
  return 0;
}
