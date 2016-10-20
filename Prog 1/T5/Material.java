public class Material{
    private int codigo;
    public String nome;
    private double quantidade;

    public void retirada(double qtd){
	this.quantidade -= qtd;
    }

    public void abastecimento(double qtd){
	this.quantidade += qtd;
    }
    
}
