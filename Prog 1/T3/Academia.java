import java.util.Scanner;

public class Academia{
    public static void main(String[] args){
	String nome;
	Scanner scan = new Scanner(System.in);
	Treino tr;
	Cliente cli;
	int tipo;
	
	System.out.println("Digite o nome do cliente:");
	nome = scan.nextLine();
	System.out.println("Digite o tipo do treino 0(Simples)|1(vip):");
	tipo = scan.nextInt();

	if(tipo == 0)
	    tr = new TreinoSimples();
	else
	    tr = new TreinoVip();
	
    }
} 
