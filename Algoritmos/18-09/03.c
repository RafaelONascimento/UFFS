#include <stdio.h>
#include <stdlib.h>

int main(){
  int codigo, numeroDependentes, contador = 1;
  float horasTrabalhadas , salarioLiquido;
  
  while(contador <= 10){
    printf("Digite o codigo do funcionario:\n");
    scanf("%d %f %d",&codigo,&hprasTrabalhadas,&numeroDependentes);
    
    salarioLiquido = ((horasTrabalhadas*12) + numerosDepentes + 40); 
    
    printf("Codigo: %d\n",codigo);
    printf("Desconto de INSS = %.2f\n",salarioLiquido * 0.085);
    printf("Desconto de IR = %.2f\n",salario*0.05);
    salarioLiquido -= ((salarioLiquido*0.085) + (salario*0.05));
    printf("Salario Liquido = %2.f",salarioLiquido);
    
    contado++;
  }

  return 0;
}
