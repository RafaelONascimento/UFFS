import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class TesteAcampamento{
    public static void main(String[] args){
	Acampamento[] pessoas = new Acampamento[10];
	Scanner scan = new Scanner(System.in);
	String nome;
	int idade, i;

	for(i = 0; i < 4; i++){
	    nome = scan.nextLine();
	    idade = scan.nextInt();
	    scan.nextLine();	
	    pessoas[i] = new Acampamento(nome,idade);
	    pessoas[i].definirEquipe();
	}

	System.out.println("---------------------------");
	System.out.println("Resumo de cadastros:");
	System.out.println("---------------------------");
	
	for(i = 0; i < 4; i++){
	    System.out.println("["+(i+1)+"]"+pessoas[i].toString());
	}
    }
}
