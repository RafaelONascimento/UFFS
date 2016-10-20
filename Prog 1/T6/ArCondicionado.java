public class ArCondicionado extends Eletrodomestico{
    private int btus;
    private boolean arQuente;

    public ArCondicionado(String nome, int potencia, int cee, int btus, boolean arQuente){
	super(nome,potencia,cee);
	this.btus = btus;
	this.arQuente = arQuente;
    }
    
    public boolean verificaCapacidade(int compr, int larg, int nPessoas){
	if((((compr * larg)*600)+(nPessoas*600)) <= btus) return true;
	else return false;
    }

    public String mensagemPromocional(){
	return super.mensagemPromocional()+" Seu conforto nao tem preco!";
    }

    public char classificarConsumo(){
	if(cee > 3.2) return 'A';
	else if(cee >= 2.8 && cee <= 3.2) return 'B';
	else if(cee >= 0 && cee <= 2.7) return 'C';
	else return ' ';
    }

    public int getBtus(){
	return btus;
    }

    public boolean setBtus(int btus){
	if(btus >= 0){
	    this.btus = btus;
	    return true;
	}
	else return false;
    }

    public boolean getArQuente(){
	return arQuente;
    }

    public void setArQuente(boolean arQuente){
	this.arQuente = arQuente;
    }
}
