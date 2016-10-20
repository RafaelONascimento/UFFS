public class Retangulo extends Forma{
    private float base, altura;

    public Retangulo(){
    }

    public Retangulo(int x, int y, float b, float h){
	super(x,y);
	base = b;
	altura = h;
    }
  
    public void setBase(float b){
	base = b;
    }

    public float getBase(){
	return base;
    }

    public void setAltura(float h){
	altura = h;
    }

    public float getAltura(){
	return altura;
    }

    public String toString(){
	return "Retangulo. Centro: ("+super.toString()+") Base: "+base+" Altura: "+altura;
    }

    public float calcularArea(){
	return (base*altura);
    }

    public float calcularPerimetro(){
	return (base+altura)*2;
    }
}
