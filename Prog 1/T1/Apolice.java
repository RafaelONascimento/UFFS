public class Apolice{
    private int numApolice, idade;
    private static int ultimoNumApolice;
    private String nomeSegurado;
    private float valorPremio;

    public Apolice(){
	numApolice = ++ultimoNumApolice;
    }

    public Apolice(String nomeSegurado, int idade, float valorPremio){
	numApolice = ++ultimoNumApolice;
	this.nomeSegurado = nomeSegurado;
	this.idade = idade;
	this.valorPremio = valorPremio;
    }

    public void SetNomeSegurado(String nomeSegurado){
	this.nomeSegurado = nomeSegurado;
    }

    public String GetNomeSegurado(String nomeSegurado){
	return nomeSegurado;
    }

    public void SetIdade(int idade){
	this.idade = idade;
    }

    public int GetIdade(){
	return idade;
    }

    public void SetValorPremio(float valorPremio){
	this.valorPremio = valorPremio;
    }

    public float GetValorPremio(){
	return valorPremio;
    }

    public void imprimir(){
	System.out.println("------------------------------------");
	System.out.println("Informacoes Apolice Numero "+numApolice);
	System.out.println("------------------------------------");
	System.out.println("Nome: "+nomeSegurado);
	System.out.println("Idade: "+idade);
	System.out.printf("Valor premio: %.2f\n",valorPremio);
	System.out.println("------------------------------------");
    }
    
    public void calcularPremio(){
	if(idade >= 18 && idade <= 25)
	    valorPremio = valorPremio*1.2F;
	else if(idade > 25 && idade <= 36)
	    valorPremio = valorPremio*1.15F;
	else if(idade > 36)
	    valorPremio = valorPremio*1.1F;
    }

    public int oferecerDesconto(String cidade){
	switch(cidade){
	   case "Florianópolis":
	       return 5;
	   case "Chapecó":
	       return 6;
	   case "Joaçaba":
	       return 7;
	   case "Joinville":
	       return 8;
	   default:
	       return 0;
	}
    }

    public void exibeUltimoNum(){
	System.out.println("------------------------------------");
	System.out.println("Numero da ultima apolice = "+ultimoNumApolice);
	System.out.println("------------------------------------");	
    }
}
