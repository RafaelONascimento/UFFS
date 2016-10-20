import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class TesteProduto{
    public static void main(String[] args){
	ArrayList<Produto> produtos = new ArrayList<Produto>();
	int opcao = 0, codigo, quantidade;
	String nome;
	Scanner scan = new Scanner(System.in);

	while(opcao != 9){
	    System.out.println("------------------------");
	    System.out.println("     Menu de opcoes");
	    System.out.println("------------------------");
	    System.out.println("1 – Cadastrar Produto");
	    System.out.println("2 – Consultar estoque");
	    System.out.println("3 – Remover unidades");
	    System.out.println("4 – Adicionar unidades");
	    System.out.println("9 – Sair");
	    System.out.print("Digite a opcao desejada...: ");
	    opcao = scan.nextInt();
	    scan.nextLine();
	    
	    switch(opcao){
	        case 1:
		    Produto p = new Produto();
		    System.out.println("Digite o nome: ");
		    nome = scan.nextLine();
		    p.setNome(nome);
		    System.out.println("Digite a quantidade: ");
		    p.setQuantidade(scan.nextInt());
		    scan.nextLine();
		    System.out.println("Digite o valor: ");
		    p.setValor(scan.nextFloat());
		    produtos.add(p);
		    break;
	        case 2:
		    System.out.println("Digite o codigo do produto: ");
		    codigo = scan.nextInt();
		    scan.nextLine();
		    System.out.println("Quantidade: "+produtos.get(codigo).getQuantidade());
		    System.out.print("Digite enter para continuar......... ");
		    scan.nextLine();
		    break;
	        case 3:
		    System.out.println("Digite o codigo do produto: ");
		    codigo = scan.nextInt();
		    scan.nextLine();
		    System.out.println("Digite a quantidade: ");
		    quantidade = scan.nextInt();
		    scan.nextLine();
		    if(produtos.get(codigo).removerUnidades(quantidade))
			System.out.println("Operacao efetuada com sucesso!!!");
		    else
			System.out.println("Erro: Quantidade do produto inferior a solicitado");
		    break;
	        case 4:
		    System.out.println("Digite o codigo do produto: ");
		    codigo = scan.nextInt();
		    scan.nextLine();
		    System.out.println("Digite a quantidade: ");
		    quantidade = scan.nextInt();
		    scan.nextLine();
		    produtos.get(codigo).adicionarUnidades(quantidade);
		    break;
	    }
	}
    }
}
