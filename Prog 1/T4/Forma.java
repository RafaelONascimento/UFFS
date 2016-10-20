abstract class Forma{
    private int x, y;

    public Forma(){
    }

    public Forma(int x, int y){
	this.x = x;
	this.y = y;
    }

    public String toString(){
	return ""+x+","+y;
    }

    abstract float calcularArea();
    abstract float calcularPerimetro();
}
