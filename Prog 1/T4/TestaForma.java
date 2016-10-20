import java.util.Scanner;

public class TestaForma{
    public static void main(String[] args){
	int opcao, x, y;
	float raio, base, altura;
	Scanner scan = new Scanner(System.in);
	
	System.out.println("Escolha uma opcao:");
	System.out.println("1)Circulo");
	System.out.println("2)Retangulo");
	opcao = scan.nextInt();

	System.out.print("Digite o valor de X: ");
	x = scan.nextInt();
	System.out.print("Digite o valor de Y: ");
	y = scan.nextInt();
	
	if(opcao == 1){
	    System.out.print("Digite o valor do raio: ");
	    raio = scan.nextFloat();
	    Circulo obj = new Circulo(x,y,raio);
	    System.out.println(obj.toString());
	    System.out.printf("Area = %.2f\n",obj.calcularArea());
	    System.out.printf("Perimetro = %.2f\n",obj.calcularPerimetro());
	    
	}
	else if(opcao == 2){
	    System.out.print("Digite o valor da base: ");
	    base = scan.nextFloat();
	    System.out.print("Digite o valor da altura: ");   
	    altura = scan.nextFloat();
	    Retangulo obj = new Retangulo(x,y,base,altura);
	    System.out.println(obj.toString());
	    System.out.printf("Area = %.2f\n",obj.calcularArea());
	    System.out.printf("Perimetro = %.2f\n",obj.calcularPerimetro());
	}

    }
}
