import java.util.ArrayList;
import java.util.Arrays;

public class Treino{
    private ArrayList<String> exercicios = new ArrayList<String>();
    private double precoExercicio;
    
    public void adicionarExercico(String nomeExercicio){
	exercicios.add(nomeExercicio);
    }
    
    public void imprimeCobranca(){
	System.out.printf("Valor a pagar: R$ %.2f\n",(exercicos.size()*precoExercicios));
    }
    
    public void imprimeExercicios(){
	System.out.println("Lista de exercicos:");
	
	for(int i = 0; i < exercicios.size(); i++)
	    System.out.prinln("["+(i+1)+"]"+exercicos.get(i));	
    }
}
