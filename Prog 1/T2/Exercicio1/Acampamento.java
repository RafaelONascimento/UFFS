public class Acampamento{
    private String nome;
    private int idade;
    private char equipe;

    public Acampamento(String nome, int idade){
	setNome(nome);
	setIdade(idade);
    }

    public void definirEquipe(){
	if(idade >= 6 && idade <= 10){
	    setEquipe('A');
	}
	else if(idade >= 11 && idade <= 20){
	    setEquipe('B');
	}
	else if(idade >= 21){
	    setEquipe('C');
	}
	
	
    }

    public void setNome(String nome){
	this.nome = nome;
    }

    public String getNome(){
	return nome;
    }

    public void setIdade(int idade){
	this.idade = idade;
    }

    public int getIdade(){
	return idade;
    }

    public void setEquipe(char equipe){
	this.equipe = equipe;
    }

    public char getEquipe(){
	return equipe;
    }

    public String toString(){
	return ("Nome:"+nome+" Idade:"+idade+" Equipe:"+equipe);
    }
}
