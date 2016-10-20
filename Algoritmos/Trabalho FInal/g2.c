#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
  char nome[40], sobrenome[40], senha[20] ;
  char dataUltimoSaque[20], cpf[14], dataUltimaTransferencia[20];
  int numeroConta, qtdSaqueAtual, qtdTranferenciaAtual;
  double saldo, saldoDiaAtual, saldoTransferencia;
  
}correntista;

//1 = Sem erro                                 0000
//2 = Excedeu o limite de saque                1000
//3 = Excedeu o limite de tranferencia         2000
//4 = Excedeu a Qtd maxima de saque            3000
//5 = Excedeu a Qtd maxia de tranferencia      4000
//6 = Sem saldo suficiente para saque          5000
//7 = Sem saldo para Tranferencia              5100
//8 = Conta nao encontrada                     6000
//9 = Conta invalida                           6100
//10 = Conta para transferencia nao encontrada 6200
//11 = Senha invalida                          7000
//12 = Sem dinheiro                            8000
typedef struct{
  int erro, posicao;
  double valor;
}retornoOperacao;

typedef struct{
  int n100, n50, n20, n10, n5, n2;
  long int saldo;
} cedulas;

void verificaErro(retornoOperacao retorno){
  if(retorno.erro == 2)
    printf("1000 - EXCEDEU O LIMITE DE SAQUE");
  else if(retorno.erro == 3)
    printf("2000 - EXCEDEU O LIMITE DE TRANFERENCIA");
  else if(retorno.erro == 4)
    printf("3000 - EXCEDEU A QUANTIDADE MAXIMA DE SAQUES");
  else if(retorno.erro == 5)
    printf("4000 - EXCEDEU A QUANTIDADE MAXIMA DE TRANSFERENCIAS");
  else if(retorno.erro == 6)
    printf("5000 - SEM SALDO SUFICIENTE PARA SAQUE");
  else if(retorno.erro == 7)
    printf("5100 - SEM SALDO SUFICIENTE PARA TRANSFERENCIA");
  else if(retorno.erro == 8)
    printf("6000 - CONTA NAO ENCONTRADA");
  else if(retorno.erro == 9)
    printf("6100 - CONTA INVALIDA");
  else if(retorno.erro == 10)
    printf("6200 - CONTA PARA TRANFERENCIA NAO ENCONTRADA");
  else if(retorno.erro == 11)
    printf("7000 - SENHA INVALIDA");
  else if(retorno.erro == 12)
    printf("8000 - SEM DINHEIRO NO CAIXA");
}

int validadorConta(int numeroConta){
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

int validadorCPF(char cpf[]){
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

retornoOperacao verificaConta(int numeroConta, char senha[20], 
			      int posicaoAtual, correntista clientes[300]){
  int i, flag = 0;
  retornoOperacao retorno;

  for(i = 0; i < posicaoAtual; i++){
    if(clientes[i].numeroConta == numeroConta){
      flag = 1; 
      break;
    }
  }
  
  if(!flag){
    retorno.erro = 8;
  }
  else if(strcmp(clientes[i].senha, senha) == 0){
    retorno.erro = 1;
    retorno.posicao = i;
  }
  else 
    retorno.erro = 11;
 
  return retorno;
}

retornoOperacao consultaSaldo(correntista clientes[300], char senha[20], int numeroConta, int posicaoAtual){
  retornoOperacao retorno;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,clientes);
 
  if(retorno.erro == 1)
    retorno.valor = clientes[retorno.posicao].saldo;

  return retorno;
}

int retiraDinheiroCedulas(long int *valor, int *cedula, int valorNota, int flag){
  int qtd, i;
  
  qtd = *valor/ valorNota;
  if(*cedula >= qtd){
    *cedula -= qtd;
    *valor -= (qtd*valorNota);
  }
  
  if(flag)
    printf("+");	  
  
  printf("%d,00",valorNota);
  for(i = 1; i < qtd; i++)
    printf("+%d,00",valorNota);
  
  return 1;
}

retornoOperacao operacaoSaque(correntista clientes[], char senha[20], 
			      int numeroConta, long int valor, int posicaoAtual, 
			      cedulas *notas){
  retornoOperacao retorno;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,clientes);
  
  int flag = 0;
  long int valorSaque = valor;
  
  if(retorno.erro = 1){
    if((strcmp(clientes[retorno.posicao].dataUltimoSaque,__DATE__)==0) && 
       clientes[retorno.posicao].qtdSaqueAtual == 3){
      retorno.erro = 4;
    }
    else if((strcmp(clientes[retorno.posicao].dataUltimoSaque,__DATE__)==0) && 
	    (clientes[retorno.posicao].saldoDiaAtual+valor) > 500){
      retorno.erro = 2;
    }
    else if(clientes[retorno.posicao].saldo < valor){
      retorno.erro = 6;
    }
    else if(notas->saldo < valor){
      retorno.erro = 12;
    }
    else{
      if(valor >= 100){
	flag = retiraDinheiroCedulas(&valor,&notas->n100,100,flag);
      }
      if(valor >= 50){
	flag = retiraDinheiroCedulas(&valor,&notas->n50,50,flag);
      }
      if(valor >= 20){
	flag = retiraDinheiroCedulas(&valor,&notas->n20,20,flag);
      }
      if(valor >= 5){
	flag = retiraDinheiroCedulas(&valor,&notas->n5,5,flag);
      }
      if(valor >= 2){
	flag = retiraDinheiroCedulas(&valor,&notas->n2,2,flag);
      }
      retorno.erro = 1;
      clientes[retorno.posicao].saldo -= valorSaque;
      notas->saldo -= valorSaque;
      if((strcmp(clientes[retorno.posicao].dataUltimoSaque,__DATE__)==0)){
	clientes[retorno.posicao].saldoDiaAtual += valorSaque;
	clientes[retorno.posicao].qtdSaqueAtual++;
      }
      else{
	strcpy(clientes[retorno.posicao].dataUltimoSaque,__DATE__);
	clientes[retorno.posicao].qtdSaqueAtual = 1;
	clientes[retorno.posicao].saldoDiaAtual = valorSaque;
      }
    }
  }
  return retorno;
}

retornoOperacao deposito(int numeroConta, correntista clientes[300], 
			 long int valor, int posicaoAtual){
  int i , flag = 0;
  retornoOperacao retorno;
  
  for(i = 0; i < posicaoAtual; i++){
    if(clientes[i].numeroConta == numeroConta){
      flag = 1; 
      break;
    }
  }
 
  if(!flag){
    retorno.erro = 8;
  }
  else{
    retorno.erro = 1;
    clientes[i].saldo += valor;
  }

  return retorno;
}

retornoOperacao transferencia(int contaOrigem, int contaDestino, double valor, 
			      correntista clientes[], int posicaoAtual, char senha[20]){
  int clienteDestino;
  int i, flag = 0;
  retornoOperacao retorno;
 
  retorno = verificaConta(contaOrigem,senha,posicaoAtual,&clientes[posicaoAtual-1]);

  if(retorno.erro = 1){   
    for(i = 0, flag = 1; i < posicaoAtual; i++){
      if(clientes[i].numeroConta == contaDestino){
	flag = 1;
	break;
      }
    }
    
    if(!flag){
      retorno.erro = 10;
    }
    else{      
      if((strcmp(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__)==0) && 
	 clientes[retorno.posicao].qtdTranferenciaAtual == 3){
	retorno.erro = 5;
      }
      else if((strcmp(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__)==0) && 
	      (clientes[retorno.posicao].saldoTransferencia+valor) > 500){
	retorno.erro = 3;
      }
      else if(clientes[retorno.posicao].saldo < valor){
	retorno.erro = 7;
      }
      else{
	retorno.erro = 1;
	clientes[i].saldo += valor;
	retorno.valor = clientes[i].saldo;

	clientes[retorno.posicao].saldo -= valor;
	if((strcmp(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__)==0)){
	  clientes[retorno.posicao].saldoTransferencia += valor;
	  clientes[retorno.posicao].qtdTranferenciaAtual++;
	}
	else{
	    strcpy(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__);
	    clientes[retorno.posicao].qtdTranferenciaAtual = 1;
	}
      }
    }
  }
  return retorno;
}

void cadastraCliente(correntista clientes[300], int *posicaoAtual){
  int flag = 0;
  getchar();
  printf("DIGITE O NOME DO CORRENTISTA: ");
  fgets(clientes[*posicaoAtual].nome,40,stdin);
  printf("DIGITE O SOBRENOME DO CORRENTISTA: ");
  fgets(clientes[*posicaoAtual].sobrenome,40,stdin);
  printf("DIGITE O CPF DO CORRENTISTA: ");
  fgets(clientes[*posicaoAtual].cpf,14,stdin);
  flag = validadorCPF(clientes[*posicaoAtual].cpf);
  while(!flag){
    printf("CPF INVALIDO!! DIGITE NOVAMENTE: ");
    fgets(clientes[*posicaoAtual].cpf,14,stdin);
    flag = validadorCPF(clientes[*posicaoAtual].cpf);
  }
  printf("DIGITE O NUMERO DA CONTA: ");
  scanf("%d",&clientes[*posicaoAtual].numeroConta);
  flag = validadorConta(clientes[*posicaoAtual].numeroConta);
  while(flag){
    printf("NUMERO DE CONTA INVALIDO: ");
    scanf("%d",&clientes[*posicaoAtual].numeroConta);
    flag = validadorConta(clientes[*posicaoAtual].numeroConta);
  }
  getchar();
  printf("DIGITE A SENHA PARA A CONTA: ");
  fgets(clientes[*posicaoAtual].senha,20,stdin);
  printf("DIGITE O VALOR INICIAL:\n");
  scanf("%lf",&clientes[*posicaoAtual].saldo);
  printf("CADASTRO EFETUADO COM SUCESSO\n");
  *posicaoAtual = (*posicaoAtual+1);
}

int main(){
  system("clear");
  printf("DIGITE O NUMERO DE CADASTROS INICIAIS: ");
  correntista clientes[300];
  int posicaoAtual = 0, i, n, operacao = 1, numeroConta, numeroTransferencia;
  double saldoDisponivel, valorTransferencia;
  cedulas notasDisponiveis;
  char senha[20];
  retornoOperacao retorno;
  long int valor;

  notasDisponiveis.n100 = 20;
  notasDisponiveis.n50 = 20;
  notasDisponiveis.n20 = 20;
  notasDisponiveis.n10 = 20;
  notasDisponiveis.n5 = 20;
  notasDisponiveis.n2 = 20;
  notasDisponiveis.saldo = 3740;

  scanf("%d",&n);
  for(i= 0; i < n; i++)
     cadastraCliente(clientes,&posicaoAtual);

  system("clear");
  while(operacao){
    printf("-----------------------------------------------------\n");
    printf("-----           CAIXA ELETRONICO                 ----\n");
    printf("-----------------------------------------------------\n");
    printf("1)SALDO              2)SAQUE               3)DEPOSITO\n"); 
    printf("4)TRANFERENCIA       5)ADM                 0)SAIR\n");
    printf(" ----------------------------------------------------\n");
    printf("DIGITE A OPERACAO DESEJADA: ");
    scanf("%d",&operacao);
    system("clear");
    switch(operacao){ 
       case 1:
         printf("-----------------------------------------------------\n");
	 printf("-----        CAIXA ELETRONICO - SALDO            ----\n");
	 printf("-----------------------------------------------------\n");
	 printf("DIGITE O NUMERO DA CONTA: ");
         scanf("%d",&numeroConta);
	 getchar();
	 printf("DIGITE A SENHA: ");
	 fgets(senha,20,stdin);
	 retorno = consultaSaldo(clientes,senha,numeroConta,posicaoAtual);
	 printf("-----------------------------------------------------\n");
	 if(retorno.erro == 1)
	   printf("SALDO = R$%.2lf",retorno.valor);
	 else
	   verificaErro(retorno);
	 printf("\n.....................................................");
	 getchar();
	 system("clear");
	 break;
       case 2:
	  printf("-----------------------------------------------------\n");
	  printf("-----        CAIXA ELETRONICO - SAQUE            ----\n");
	  printf("-----------------------------------------------------\n");
	  printf("DIGITE O NUMERO DA CONTA: ");
	  scanf("%d",&numeroConta);
	  printf("DIGITE O VALOR: R$");
	  scanf("%ld",&valor);
	  getchar();
	  printf("DIGITE A SENHA: ");
	  fgets(senha,20,stdin);
	  printf("-----------------------------------------------------\n");
	  retorno = operacaoSaque(clientes,senha,numeroConta,valor,posicaoAtual,&notasDisponiveis);
	  if(retorno.erro != 1)
	    verificaErro(retorno);
	  printf("\n");
	  printf(".....................................................");
	  getchar();
	  system("clear");	 
	  break;
       case 3:
	  printf("-----------------------------------------------------\n");
	  printf("-----       CAIXA ELETRONICO - DEPOSITO          ----\n");
	  printf("-----------------------------------------------------\n");
	  printf("DIGITE O NUMERO DA CONTA: ");
	  scanf("%d",&numeroConta);
	  printf("DIGITE O VALOR: R$");
	  scanf("%ld",&valor);
	  retorno = deposito(numeroConta,clientes,valor,posicaoAtual);
	  getchar();
	  printf("-----------------------------------------------------\n");
	  if(retorno.erro == 1)
	    printf("OPERACAO FEITA COM SUCESSO");
	  else
	    verificaErro(retorno);
	  printf("\n.....................................................");
	  getchar();
	  system("clear");
	 break;
       case 4:
	  printf("-----------------------------------------------------\n");
	  printf("-----      CAIXA ELETRONICO - TRANSFERENCIA      ----\n");
	  printf("-----------------------------------------------------\n");
	  printf("DIGITE O NUMERO DA CONTA DE ORIGEM\n");
	  scanf("%d",&numeroConta);
	  printf("DIGITE O NUMERO DA CONTA DE DESTINO\n");
	  scanf("%d",&numeroTransferencia);
	  getchar();
	  printf("DIGITE A SENHA DA CONTA DE ORIGEM\n");
	  scanf("%lf",&valorTransferencia);
	  fgets(senha,20,stdin);
	  retorno = transferencia(numeroConta,numeroTransferencia,valorTransferencia, 
				  &clientes[300], posicaoAtual, senha);
	  break;
    }
  }

  return 0;
  
}
