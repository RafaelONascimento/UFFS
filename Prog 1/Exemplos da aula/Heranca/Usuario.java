public class Usuario{
    protected String nome, sobrenome, cpf, login;

    public Usuario(String nome, String sobrenome, String cpf, String login){
	this.nome = nome;
	this.sobrenome = sobrenome;
	this.cpf = cpf;
	this.login = login;
    }

    public void geraLogin(){
	login = (nome.substring(0,2)+(sobrenome.substring((sobrenome.legth-4),(sobrenome.legth-1)))+(cpf.substring(0,2))).toLowerCase();
    }

    public void exibirDados(){
	System.out.println("-----------------------------------");
	System.out.println("Nome: "+nome);
	System.out.println("Sobrenome: "+sobrenome);
	System.out.println("CPF: "+cpf);
	system.out.println("Login: "+login);
	System.out.println("-----------------------------------");
    }
}
