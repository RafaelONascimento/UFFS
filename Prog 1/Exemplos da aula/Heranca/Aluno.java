public class Aluno{
    protected String matricula;
    
    public Aluno(String nome, String sobrenome,String cpf, String matricula){
	super.Usuario(nome,sobrenome,cpf);
	this.matricula = matricula;
    }
    
    public void gerarLogin(){
	login = (nome.substring(0,0)+sobrenome+matricula.substring(0,3)).toLowerCase();
    }
    
    public void exibirDados(){
	System.out.println("-----------------------------------");
	System.out.println("Nome: "+nome);
	System.out.println("Sobrenome: "+sobrenome);
	System.out.println("CPF: "+cpf);
	system.out.println("Login: "+login);
	system.out.println("Matricula: "matricula);	
	System.out.println("-----------------------------------");
    }
}
