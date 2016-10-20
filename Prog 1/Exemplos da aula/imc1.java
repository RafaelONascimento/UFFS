public class imc1{
    public static void main(String[] args){
	int peso = Integer.parseInt(args[1]);
	float altura = Float.parseFloat(args[2]);
	float imc = peso/(altura*altura);

	System.out.println("Ola "+args[0]+", seu IMC é: "+imc+".");
    }
}
