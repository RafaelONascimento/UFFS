import java.lang.Math;

public class Circulo extends Forma{
    private float raio;
    
    public Circulo(){
    }

    public Circulo(int x, int y, float raio){
	super(x,y);
	this.raio = raio;
    }

    public void setRaio(float raio){
	this.raio = raio;
    }

    public float geRaio(){
	return raio;
    }

    public String toString(){
	return "Circulo. Centro: ("+super.toString()+") Raio: "+raio;
    }

    public float calcularArea(){
	return ((float)Math.PI*(raio*raio));
    }

    public float calcularPerimetro(){
	return (2*(float)Math.PI*raio);
    }
}
