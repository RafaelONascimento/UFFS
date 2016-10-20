import java.util.Scanner;

public class TestaApolice{
    public static void main(String[] args){
	String nome, cidade, buf;
	int idade, desconto;
	float valorPremio;
	
	Scanner scan = new Scanner(System.in);

	//Primeiro Teste
	Apolice teste1 = new Apolice();
        nome = scan.nextLine();
	idade = scan.nextInt();
	valorPremio = scan.nextFloat();
	scan.nextLine();	
	cidade = scan.nextLine();

	teste1.SetNomeSegurado(nome);
	teste1.SetIdade(idade);
	teste1.SetValorPremio(valorPremio);
	
	teste1.calcularPremio();
	teste1.imprimir();
	desconto = teste1.oferecerDesconto(cidade);
	valorPremio = teste1.GetValorPremio();
	System.out.printf("Valor do desconto = %.2f\n",(valorPremio*desconto)/100.0F); 
	System.out.println("------------------------------------");

	//Segundo Teste
	nome = scan.nextLine();
	idade = scan.nextInt();
	valorPremio = scan.nextFloat();
	scan.nextLine();	
	cidade = scan.nextLine();

	Apolice teste2 = new Apolice(nome,idade,valorPremio);
          	
	teste2.calcularPremio();
	teste2.imprimir();
	desconto = teste2.oferecerDesconto(cidade);
	valorPremio = teste2.GetValorPremio();
	System.out.printf("Valor do desconto = %.2f\n",(valorPremio*desconto)/100.0F);
	teste2.exibeUltimoNum();
    }
}
