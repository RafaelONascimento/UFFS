#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 220
#define MAXE  -220

double f(double x){
  //old function
  //  return cos(2*x)+pow(2,x)-pow(x,2)-(1.0/3.0);
  //new fucking one
  return cos(x)/*-x+pow(M_E,x)-2*/;
}


int main(){
  double e = pow(10,-5),a,b,xi;
  int flag = 0,fa,fb,fxi,n;
  
  a = MAXE;
  b = MAXD;
  
  while(a != MAXD){
    flag = 0;
    
    n = ((log10(MAXD-MAXE)-log10(e))/log10(2))+1;

    while(n-- && !flag && a != b){
      //  printf("|%d|%.80g|%.80g|%.80g|%d|%d|%d|\n",n,a,b,xi,fa,fb,fxi);
      xi = (a+b)/2.0;
      // printf("|%d|%.80g|%.80g|%.80g|%d|%d|%d|\n",n,a,b,xi,fa,fb,fxi);
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
    if(/*(*/flag || a != b/*) && (b-a) <= e*/) {
      printf("Limites: %lf || %lf\n",a,b);
      //  printf("Limite superior: %.80g\n",b);
    }
    a = b;
    b = MAXD;
  }
  return 0;
}
