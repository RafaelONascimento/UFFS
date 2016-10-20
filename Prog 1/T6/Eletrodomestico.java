public abstract class Eletrodomestico{
    private String nome;
    private int potencia;
    protected float cee;
    private Marca marca;
    
    public Eletrodomestico(String nome, int potencia, int cee){
	this.nome = nome;
	this.potencia = potencia;
	this.cee = cee;
    }
    
    public abstract char classificarConsumo();
	
    public String mensagemPromocional(){
	return "Promoção!!!";
    }

    public String getNome(){
	return nome;
    }

    public void setNome(String nome){
	this.nome = nome;
    }

    public int getPotencia(){
        return potencia;
    }

    public void setPotencia(int potencia){
	this.potencia = potencia;
    }

    public float getCee(){
	return cee;
    }

    public boolean setCee(float cee){
	if(cee >= 0){
	    this.cee = cee;
	    return true;
	}
	else return false;
    }

    public Marca getMarca(){
	return marca;
    }

    public void setMarca(Marca marca){
	this.marca = marca;
    }
}
