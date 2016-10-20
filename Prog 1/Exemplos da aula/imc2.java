import java.util.Scanner;

class imc2{
    public static void main(String[] args ){
	String nome;
	int peso;
	float altura;
	Scanner scanner = new Scanner(System.in);

	System.out.printf("Digite seu nome: ");
	nome = scanner.nextLine();
	System.out.printf("Digite seu peso: ");
	peso = scanner.nextInt();
	System.out.printf("Digite sua altura: ");	
	altura = scanner.nextFloat();

	System.out.print("Ola "+nome+", seu IMC é: ");
	System.out.printf("%.2f.\n",(peso/(altura*altura)));
    }
}
