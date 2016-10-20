public class Produto{
    private String nome;
    private float valor;
    private int quantidade;

    public void setNome(String nome){
	this.nome = nome;
    }

    public String getNome(){
	return nome;
    }

    public void setValor(float valor){
	this.valor = valor;
    }

    public float getValor(){
	return valor;
    }

    public void setQuantidade(int quantidade){
	this.quantidade = quantidade;
    }

    public int getQuantidade(){
	return quantidade;
    }

    public boolean verificaDisponibilidade(int quantidade){
	if(this.quantidade >= quantidade){
	    return true;
	}
	else{
	    return false;
	}
    }

    public void adicionarUnidades(int quantidade){
	this.quantidade += quantidade;
    }

    public boolean removerUnidades(int quantidade){
	if(verificaDisponibilidade(quantidade)){
	    this.quantidade -= quantidade;
	    return true;
	}
	else{
	    return false;
	}
    }

    public String toString(){
	return (nome+" "+" "+valor+" "+quantidade);
    }
}
