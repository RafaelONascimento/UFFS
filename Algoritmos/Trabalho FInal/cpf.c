#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char cpfMascara[14], cpf[11];
    while(scanf("%s",cpf) != EOF)
    {
        int i, j= 0, total = 0, resto = 0, quociente = 0, verificador1 = 0, verificador2 = 0;
        for(i = 0, j = 1; i < 9; i++,j++)
        {
            total += (((int)cpf[i]-48)*j);
        }
 
        quociente = (total/11);
        resto = (total%11);
 
        if(resto == 10)
        {
            verificador1 = 0;
        }
        else
        {
            verificador1 = resto;
        }
 
        total = 0;
 
        for(i = 0, j = 9; i < 9; i++,j--)
        { 
            total += (((int)cpf[i]-48)*j);
        }
 
	printf("%d\n",total);
        quociente = (total/11);
        resto = (total%11);
	
        if(resto == 10)
        {
            verificador2 = 0;
        }
        else
        {
            verificador2 = resto;
        }
 
        if((cpf[9]-48) == verificador1 && (cpf[10]-48) == verificador2)
        {
            printf("CPF valido\n");
        }
        else
        {
            printf("CPF invalido\n");
        }
    }
    return 0;
}
