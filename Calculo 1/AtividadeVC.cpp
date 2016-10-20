#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 400
#define MAXE -400

double f(double x){
  return pow(x,2);
}

int main(){
  double e = pow(10,-3),a,b,xi, paso = 0.01;
  int flag = 0,fa,fb,fxi,n, l = 1, i= 0, j =0;
  
  a = MAXE;
  b = MAXE+paso;
  
  while(a < MAXD){
    flag = 0;
    n = ((log10(b-a)-log10(e))/log10(2))+1;
    l++;
    j=0;
    while(n-- && !flag){
      j++;
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
      printf("Raiz Numero #%d\n",++i);
      printf("    LI = %.10g\n",a);
      printf("    LS = %.10g\n",b);	
    }
    a = MAXE+((paso)*(l-1));
    b = MAXE+(l*paso);
  }
  return 0;
}






//Funcoes Jah digitadas
//old function
//return cos(2*x)+pow(2,x)-pow(x,2)-(1.0/3.0);
//new fucking one
// return sin(x)-x+pow(M_E,x)-2;
//Cos function
//return cos(x);
