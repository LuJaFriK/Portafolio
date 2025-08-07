package rpg;
public class Arquero extends Personaje {
    private int punteria;
    
    public Arquero(String nombre, double vida, double ataque, String color, int punteria) {
        super(nombre, vida, ataque, color);
        this.punteria = punteria;
        setArma( "Arco");
    }
    
    public int getPunteria() {
        return punteria;
    }
    
    public void setPunteria(int punteria) {
        this.punteria = punteria;
    }
    
    public void atacar(Personaje objetivo, int distancia) {
    double punteriaEfectiva = this.punteria; 
    
    if (distancia >= 3 && distancia <= 10) {
        punteriaEfectiva = 100;
    } else if (distancia >= 11 && distancia <= 20) {
        punteriaEfectiva *= 0.8; // Reduce 20% la puntería si el objetivo esta a mas de 11 de distancia
    }

    if (distancia <= 20 && Math.random() * 100 <= punteriaEfectiva) {
        objetivo.recibirAtaque(getAtaque());
        System.out.println(getNombre() + " ha disparado a " + objetivo.getNombre() + 
                         " (Distancia: " + distancia + ", Puntería efectiva: " + (int)punteriaEfectiva + "%)");
    } else {
        System.out.println(getNombre() + " ha fallado el disparo.");
    }
}
}