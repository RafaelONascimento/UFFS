#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Estrutura para respresentar o correntistas, com seus atributos;
//necessarios;
typedef struct{
  char nome[40], sobrenome[40], senha[20] ;
  char dataUltimoSaque[20], cpf[14];
  int numeroConta, qtdSaqueAtual;
  long int saldo, saldoDiaAtual;
}correntista;

//Estrutura para retorno de funcao, sendo os tipos de Erro:
//1 = OK, ocorreu a transacao de forma correta;
//2 = Conta inexistente;
//3 = senha invalida;
//4 = saldo indisponivel;
//5 = saldo do dia ultrapassado;
//6 = senha dinheiro;
//7 = tentiva de saque acima de 500, porem com saldo 
//    disponivel no dia;
//8 = Ultrapassou a qtd de saques diario;
//9 = Qtd indisponivel em caixa;
typedef struct{
  int erro, posicao;
  long int valor;
}retornoOperacao;

//Estrutura que armazena a quantidade de notas no caixa;
typedef struct{
  int n100, n50, n20, n10, n5, n2;
  long int saldo;
} cedulas;

//Funcao para verificar se a conta e valida. Sendo que seu returno
//e 0 para invalido e 1 para valido;
int verificadorConta(int numeroConta){
  int digitoVerificador, i, soma ;
  digitoVerificador = numeroConta%10;
  numeroConta /= 10;

  for(i = 6, soma = 0; i <= 9; i++){
    soma += (digitoVerificador%10)*i;
    digitoVerificador/= 10;
  }
  
  i = soma%11;  
  return (i == digitoVerificador?1:0);
}

//Funcao para verificar se o cpf e valido. Sendo que o seu returno 
//e 0 para invalido, e um para valido;
int verificadorCPF(char cpf[]){
  int i, j,total = 0, resto;
  
  for(i = 0,j = 1; i < 9; i++, j++)
    total += (cpf[i]-48)*j;
  
  resto = total%11;
  resto = (resto==10?0:resto);  

  if(resto != (cpf[9]-48)) 
    return 0;
  
  for(i = 0, total = 0, j = 9; i < 9; i++, j--)
    total += (cpf[i]-48)*j;

  resto = total%11;
  resto = (resto<10?resto:0);
  
  if(resto == (cpf[10]-48)) 
    return 1;
  else 
    return 0;
}

//Verifica se a conta e a senha estao ok
retornoOperacao verificaConta(int numeroConta, char senha[20], int posicaoAtual, correntista *clientes[]){
  int i, flag = 0;
  retornoOperacao retorno;

  for(i = 0; i < posicaoAtual; i++){
    if(clientes[i]->numeroConta == numeroConta){
      flag = 1; 
      break;
    }
  }
  
  if(!flag){
    retorno.erro = 2;
  }
  else if(strcmp(clientes[i]->senha, senha) == 0){
    retorno.erro = 1;
    retorno.posicao = i;
  }
  else 
    retorno.erro = 3;
 
  return retorno;
}

//Funcao para consulta de saldo da conta, sendo que retorna 
//uma estrutura de verificacao
retornoOperacao consultaSaldo(correntista *clientes[], char senha[20], int numeroConta, int posicaoAtual){
  int i, flag = 0;
  retornoOperacao retorno;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,&clientes[posicaoAtual-1]);
  
  if(retorno.erro ==1)
    retorno.valor = clientes[retorno.posicao]->saldo;

  return retorno;
}

void retiraDinheiroCedulas(int *valor, int *cedula, int *valorNota){
  int qtd;
  
  qtd = *valor/ *valorNota;
  if(*cedula >= qtd){
    *cedula -= qtd;
    *valor -= (qtd* *valorNota);
  }
}

retornoOperacao operacaoSaque(correntista *clientes[], char senha[20], int numeroConta, long int valor, int posicaoAtual, cedulas *notas){
  retornoOperacao retorno;
  int qtd;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,&clientes[posicaoAtual-1]);
  
  if(retorno.erro = 1){
    if((strcmp(clientes[retorno.posicao]->dataUltimoSaque,__DATE__)==0) && 
       clientes[retorno.posicao]->qtdSaqueAtual == 3){
      retorno.erro = 8;
    }
    else if((strcmp(clientes[retorno.posicao]->dataUltimoSaque,__DATE__)==0) && 
	    (clientes[retorno.posicao]->saldoDiaAtual+valor) > 500){
      retorno.erro = 5;
    }
    else if(clientes[retorno.posicao]->saldo < valor){
      retorno.erro = 4;
    }
    else if(notas->saldo < valor){
      retorno.erro = 9;
    }
    else{
      if(valor >= 100){
	qtd = valor/100;
	if(notas->n100 >= qtd){
	  notas->n100 -= qtd;
	  valor -= (qtd*100);
	}
      }
      if(valor >= 50){
	qtd = valor/50;
	if(notas->n50 >= qtd){
	  notas->n50 -= qtd;
	  valor -= (qtd*50);
	}
      }
      if(valor >= 20){
	qtd = valor/20;
	if(notas->n20 >= qtd){
	  notas->n20 -= qtd;
	  valor -= (qtd*20);
	}
      }
       if(valor >= 10){
	qtd = valor/10;
	if(notas->n10 >= qtd){
	  notas->n10 -= qtd;
	  valor -= (qtd*10);
	}
       }
       if(valor >= 5){
	 qtd = valor/5;
	 if(notas->n5 >= qtd){
	   notas->n5 -= qtd;
	   valor -= (qtd*5);
	}
       }
       if(valor >= 2){
	 qtd = valor/2;
	 if(notas->n2 >= qtd){
	   notas->n2 -= qtd;
	   valor -= (qtd*2);
	 }
       }
       retorno.erro = 1;
    }
  }
  return retorno;
}

int main(){
  correntista clientes[90];
  double saldoDisponivel;
  cedulas notasDisponiveis;
}
