#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  double a, b,c;
} triangulo;

void hiph(triangulo *trian){
  trian->c = sqrt(pow((trian->a),2) * pow((trian->b),2));
}

int main(){
  triangulo trian;
  
  scanf("%lf %lf",&trian.a,&trian.b);
  hiph(&trian);
  printf("%.2lf\n",trian.c);
  
  return 0;
}
