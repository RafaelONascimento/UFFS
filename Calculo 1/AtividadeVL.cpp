#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 400
#define MAXE -400

double f(double x){
  return pow(x,2);
}

int main(){
  double erro = pow(10,-5),a,b,xi;
  int flag = 0,fa,fb,fxi,n;

  a = MAXE;
  b = MAXD;
  
  n = ((log10(b-a)-log10(erro))/log10(2))+1;
  
  while(n-- && !flag){
    xi = (a+b)/2.0;
    if(f(xi) == 0) flag = 1;
    else{
      fxi = (f(xi) >= 0)? 1:0;
      fa = (f(a) >= 0)? 1:0;
      fb = (f(b) >= 0)? 1:0;
      if(!(fa xor fxi)) a = xi;
      else b = xi;	
    }
  }

  if(flag || (f(a)*f(b)) <= 0){
    if(flag){
      a = xi;
      b = xi+erro;
    }
    printf("LI = %.10g\n",a);
    printf("LS = %.10g\n",b);	
  }
  
  return 0;
}
