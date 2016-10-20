#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 100
#define MAXE 0

double f(double x){
  //old function
  return cos(2*x)+pow(2,x)-pow(x,2)-(1/3.0);
  //new fucking one
  // return sin(x)-x+pow(M_E,x)-2;
}


int main(){
  double e = pow(10,-5),a,b,xi;
  int flag = 0,fa,fb,fxi,l =0,n;
  
  a = MAXE;  b = MAXD;

  /*  while(a != MAXD){
    flag = 0;
  */
    n = ((log10(b-a)-log10(e))/log10(2))+1;
    printf("%d(%lf || %lf)\n",n,a,b);
    
    while(n-- && !flag/* && a != b*/){
      l++;
       printf("[%d] %.40g || %.40g\n",n,a,b);
      xi = (a+b)/2.0;
      if(f(xi) == 0) flag = 1;
      else{
	fxi = (f(xi) > 0)? 1:0;
	fa = (f(a) > 0)? 1:0;
	fb = (f(b) > 0)? 1:0;
	if(!(fa xor fxi)) a = xi;
	else b = xi;	
      }
    }

    if(a != b || flag){
      printf("Limite inferior: %.10g\n",a);
      printf("Limite superior: %.10g\n",b);
    }
    /*  a = b;
	b = MAXD;
      }
*/  
  return 0;
}
