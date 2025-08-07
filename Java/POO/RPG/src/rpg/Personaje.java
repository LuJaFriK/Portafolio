package rpg;
public abstract class Personaje {
    private String nombre;
    private double vida;
    private double ataque;
    private String color;
    private String arma;
    
    public Personaje(String nombre, double vida, double ataque, String color) {
        this.nombre = nombre;
        this.vida = vida;
        this.ataque = ataque;
        this.color = color;
    }
    
    public String getNombre() {
        return nombre;
    }
    
    public double getVida() {
        return vida;
    }
    
    public double getAtaque() {
        return ataque;
    }
    
    public String getColor() {
        return color;
    }
    
    public String getArma() {
        return arma;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void addVida(double vida) {
        this.vida += vida;
    }

    public void setAtaque(double ataque) {
        this.ataque = ataque;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setArma(String arma) {
        this.arma = arma;
    }

    public void recibirAtaque(double daño) {
        this.vida -= daño;
    }

    public abstract void atacar(Personaje objetivo, int distancia);
    
    @Override
    public String toString() {
        return "nombre: " + nombre + ", ataque: " + ataque + ", color: " + color + ", arma: " + arma + " ";
    }
}
