public class Refrigerador extends Eletrodomestico{
    private int litros;
    private boolean frostFree;

    public Refrigerador(String nome, int potencia, int cee, int litros, boolean frostFree){
	super(nome,potencia,cee);
	this.litros = litros;
	this.frostFree = frestFree;
    }
    
    public char classificarConsumo(){
	if((cee>19 && frostFree) || (cee > 22 && !frostFree)) return 'A';
	else if((cee>=5 && cee<=19 && frostFree) || (cee>=6 && cee<= 22 && !frostFree)) return 'B';
	else if((cee>=0 && cee<=4 && frostFree) || (cee>=0 && cee<=5 && !frostFree)) return 'C';
	else return ' ';
    }

    public String mensagemPromocional(){
	return super.mensagemPromocional() + " Sua cozinha ainda mais bonita";
    }

    public int getLitros(){
	return litros;
    }

    public boolean setLitros(int litros){
	if(litros >= 0){
	    this.litros = litros;
	    return true;
	}
	else return false;
    }

    public boolean getFrostFree(){
	return frostFree;
    }

    public void setFrostFree(boolean fostFree){
	this.frostFree = fostFree;
    }
}
