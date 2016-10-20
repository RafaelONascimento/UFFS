#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Estrutura que guarda as informacoes do correntista
typedef struct{
  char nome[40], sobrenome[40], senha[20] ;
  char dataUltimoSaque[20], cpf[14], dataUltimaTransferencia[20];
  int numeroConta, qtdSaqueAtual, qtdTranferenciaAtual;
  double saldo, saldoDiaAtual, saldoTransferencia;
  
}correntista;
//Estrutura de retorna das operacoes, a mesma 
//retorna os erros com os seguintes codigos:
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
//O campo valor e utilizado quando a funcao retorna
//algum valor, como por exemplo o saldo.
//O campos posicao retorna, se necessario, a posicao
//do clientes no vetor de estruturas de clientes
typedef struct{
  int erro, posicao;
  double valor;
}retornoOperacao;

//Estrutura que guarda a quantidade de cedulas no caixa
//e tambem o saldo atual
typedef struct{
  int n100, n50, n20, n10, n5, n2;
  long int saldo;
} cedulas;

//Esta funcao verifica a estrura de retorno das operacoes
//e mostra mensagem de erro na tela
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

//Esta funcao faz a validacao do digito verificador
//da conta, e retorno 1 para numero de conta valido
//e 0 para numero de conta invalido
int validadorConta(int numeroConta){
  int digitoVerificador, i =0, soma , tmp;
  tmp = numeroConta;

  while(tmp){
    tmp = tmp/10;
    i++;
  }
 
  if(i > 5)
    return 0;

  digitoVerificador = numeroConta%10;
  numeroConta /= 10;

  for(i = 6, soma = 0; i <= 9; i++){
    soma += (numeroConta%10)*i;
    numeroConta/= 10;
  }
  
  i = soma%11;  
  return (i == digitoVerificador?1:0);
}

//Esta funcao faz a validacao do cpf, e retorna
//1 caso o cpf for valido, e 0 caso contrario
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

//Esta funcao verifica o numero de conta e a senha, se ambas estao
//corretas, a mesma retorna uma estrutura de retorno
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

//Esta funcao faz consulta do saldo, e retorno uma estrutura de retorno
retornoOperacao consultaSaldo(correntista clientes[300], char senha[20], 
			      int numeroConta, int posicaoAtual){
  retornoOperacao retorno;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,clientes);
 
  if(retorno.erro == 1)
    retorno.valor = clientes[retorno.posicao].saldo;

  return retorno;
}

//Esta funcao faz a retirada de cedulas do caixa, e retorna
//1 casio tudo ocorra corretamente
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

//Esta funcao faz a operacao do saque, sendo que a mesma, retona 
//uma estrtuura de retorno
retornoOperacao operacaoSaque(correntista clientes[], char senha[20], 
			      int numeroConta, long int valor, int posicaoAtual, 
			      cedulas *notas){
  retornoOperacao retorno;
  
  retorno = verificaConta(numeroConta,senha,posicaoAtual,clientes);
  
  int flag = 0;
  long int valorSaque = valor, v2 = 0, v5 =0;
  
  if(retorno.erro == 1){
    if((strcmp(clientes[retorno.posicao].dataUltimoSaque,__DATE__)==0) && 
       clientes[retorno.posicao].qtdSaqueAtual == 3){
      retorno.erro = 4;
    }
    else if((strcmp(clientes[retorno.posicao].dataUltimoSaque,__DATE__)==0) && 
	    (clientes[retorno.posicao].saldoDiaAtual+valor) > 500)
      retorno.erro = 2;
    else if(clientes[retorno.posicao].saldo < valor)
      retorno.erro = 6;
    else if(notas->saldo < valor ||(valor ==3 || valor==1))
      retorno.erro = 12;
    else{
      if(valor%10 == 1){
	v2 = 3;
	notas->n2 -= 3;
	v5 = 1;
	notas->n5 -= 1;
	valor -= 11;
      }
      else if(valor%10 == 3){
	v2 = 4;
	notas->n2 -= 4;
	v5 = 1;
	notas->n5 -= 1;
	valor -= 13;
      }
      else if(valor%10 == 6){
	v2 = 3;
	notas->n2 -= 3;
	valor -=6;
      }
      else if(valor%10 == 8){
	v2 = 4;
	notas->n2 -= 4;
	valor -= 8;
      }
      if(valor >= 100)
	flag = retiraDinheiroCedulas(&valor,&notas->n100,100,flag);
      if(valor >= 50)
	flag = retiraDinheiroCedulas(&valor,&notas->n50,50,flag);
      if(valor >= 20)
	flag = retiraDinheiroCedulas(&valor,&notas->n20,20,flag);
      if(valor >= 10)
	flag = retiraDinheiroCedulas(&valor,&notas->n10,10,flag);
      if(valor >= 5)
	flag = retiraDinheiroCedulas(&valor,&notas->n5,5,flag);
   
      while(v5){
	if(flag){
	  printf("+");
	}
	printf("5,00");
	flag = 1;
	v5--;
      }
      if(valor >= 2)
	flag = retiraDinheiroCedulas(&valor,&notas->n2,2,flag);
     
      while(v2){
	if(flag)
	  printf("+");
	
	printf("2,00");
	flag = 1;
	v2--;
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

//Esta funcao faz o deposito na conta desejada, e retorna
//um retorno de operacao
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
 
  if(!flag)
    retorno.erro = 8;
  else{
    retorno.erro = 1;
    clientes[i].saldo += valor;
  }

  return retorno;
}

//Esta funcao faz a operacao da tranferencia, e retorna
//uma estrutura de retorno
retornoOperacao transferencia(int contaOrigem, int contaDestino, double valor, 
			      correntista clientes[300], int posicaoAtual, char senha[20]){
  int clienteDestino;
  int i, flag = 0;
  retornoOperacao retorno;
 
  retorno = verificaConta(contaOrigem,senha,posicaoAtual,clientes);

  if(retorno.erro == 1){   
    for(i = 0, flag = 0; i < posicaoAtual; i++){
      if(clientes[i].numeroConta == contaDestino){
	flag = 1;
	break;
      }
    }
    
    if(!flag)
      retorno.erro = 10;
    else{    
      if((strcmp(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__)==0) && 
	 clientes[retorno.posicao].qtdTranferenciaAtual == 3)
	retorno.erro = 5;
      else if(((strcmp(clientes[retorno.posicao].dataUltimaTransferencia,__DATE__)==0) && 
	      (clientes[retorno.posicao].saldoTransferencia+valor) > 500) || valor > 500)
	retorno.erro = 3;
      else if(clientes[retorno.posicao].saldo < valor)
	retorno.erro = 7;
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
  else
    retorno.erro = 8;
  
  return retorno;
}

//Esta funcao, escreve na tela, a mesagem
//de cabecalho das funcoes
void printaCabecalho(char texto[]){
  int tamanho = strlen(texto), i;
  system("clear");
  printf("----------------------------------------------------------------------------\n");
  printf("-----              %s",texto);
  for(i = 0; i < (53-tamanho); i++)
    printf(" ");
  printf("----\n----------------------------------------------------------------------------\n");
}

//Esta funcao faz o cadastramento dos clientes
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
  getchar();

  flag = validadorConta(clientes[*posicaoAtual].numeroConta);
  while(!flag){
    printf("NUMERO DE CONTA INVALIDO: ");
    scanf("%d",&clientes[*posicaoAtual].numeroConta);
    flag = validadorConta(clientes[*posicaoAtual].numeroConta);
  }

  printf("DIGITE A SENHA PARA A CONTA: ");
  fgets(clientes[*posicaoAtual].senha,20,stdin);

  printf("DIGITE O VALOR INICIAL: R$");
  scanf("%lf",&clientes[*posicaoAtual].saldo);

  printf("----------------------------------------------------------------------------\n");
  printf("CADASTRO EFETUADO COM SUCESSO\n");
  printf("............................................................................\n");
  *posicaoAtual = (*posicaoAtual+1);
}

int main(){
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

  printaCabecalho("CAIXA ELETRONICO - CADASTRO");
  printf("DIGITE O NUMERO DE CADASTROS INICIAIS: ");
  scanf("%d",&n);

  printaCabecalho("CAIXA ELETRONICO - CADASTRO");
  for(i= 0; i < n; i++)
     cadastraCliente(clientes,&posicaoAtual);

  while(operacao){
    printaCabecalho("CAIXA ELETRONICO - OPERACOES");
    printf("1)SALDO              2)SAQUE               3)DEPOSITO\n"); 
    printf("4)TRANFERENCIA       0)SAIR\n");
    printf("----------------------------------------------------------------------------\n");

    printf("DIGITE A OPERACAO DESEJADA: ");
    scanf("%d",&operacao);

    system("clear");
    switch(operacao){ 
      case 1://Operacao do saldo
	 printaCabecalho("CAIXA ELETRONICO - SALDO");
	 printf("DIGITE O NUMERO DA CONTA: ");
         scanf("%d",&numeroConta);
	 getchar();

	 printf("DIGITE A SENHA: ");
	 fgets(senha,20,stdin);

	 retorno = consultaSaldo(clientes,senha,numeroConta,posicaoAtual);
	 printf("----------------------------------------------------------------------------\n");

	 if(retorno.erro == 1)
	   printf("SALDO = R$%.2lf",retorno.valor);
	 else
	   verificaErro(retorno);

	  printf("\n..........................................................................");
	 getchar();
	 system("clear");
	 break;
      case 2://Operacao do saque
	  printaCabecalho("CAIXA ELETRONICO - SAQUE");
	  printf("DIGITE O NUMERO DA CONTA: ");
	  scanf("%d",&numeroConta);

	  printf("DIGITE O VALOR: R$");
	  scanf("%ld",&valor);
	  getchar();

	  printf("DIGITE A SENHA: ");
	  fgets(senha,20,stdin);

	  printf("----------------------------------------------------------------------------\n");
	  retorno = operacaoSaque(clientes,senha,numeroConta,valor,posicaoAtual,&notasDisponiveis);

	  if(retorno.erro != 1)
	    verificaErro(retorno);

	  printf("\n");
	   printf("..........................................................................");
	  getchar();
	  system("clear");	 
	  break;
      case 3://Operacao de deposito
	  printaCabecalho("CAIXA ELETRONICO - DEPOSITO");
	  printf("DIGITE O NUMERO DA CONTA: ");
	  scanf("%d",&numeroConta);

	  printf("DIGITE O VALOR: R$");
	  scanf("%ld",&valor);

	  retorno = deposito(numeroConta,clientes,valor,posicaoAtual);
	  getchar();

	  printf("----------------------------------------------------------------------------\n");
	  if(retorno.erro == 1)
	    printf("OPERACAO FEITA COM SUCESSO");
	  else
	    verificaErro(retorno);
	  printf("\n..........................................................................");
	  getchar();
	  system("clear");
	  break;
      case 4://Operacao de transferencia
	  printaCabecalho("CAIXA ELETRONICO - TRANSFERENCIA");
	  printf("DIGITE O NUMERO DA CONTA DE ORIGEM: ");
	  scanf("%d",&numeroConta);

	  printf("DIGITE O NUMERO DA CONTA DE DESTINO: ");
	  scanf("%d",&numeroTransferencia);
	  getchar();

	  printf("DIGITE A SENHA DA CONTA DE ORIGEM: ");
	  fgets(senha,20,stdin);

	  printf("DIGITE O VALOR DA TRANSFERENCIA: R$");
	  scanf("%lf",&valorTransferencia);

	  retorno = transferencia(numeroConta,numeroTransferencia,valorTransferencia, 
				  clientes, posicaoAtual, senha);
	  getchar();
	  printf("----------------------------------------------------------------------------\n");
	  if(retorno.erro == 1)
	    printf("TRANSFERENCIA OK");
	  else
	    verificaErro(retorno);
	  printf("\n..........................................................................");
	  getchar();
	  system("clear");
	  break;
    }
  }
  return 0;
  
}
