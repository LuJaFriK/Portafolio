package rpg;

public class Mago extends Personaje {
    private int duracionhechizo;
    
    public Mago(String nombre, double vida, double ataque, String color, int duracionhechizo) {
        super(nombre, vida, ataque, color);
        setArma( "Varita");
        this.duracionhechizo = duracionhechizo;
    }
    
    public int getDuracionhechizo() {
        return duracionhechizo;
    }
    
    public void setDuracionhechizo(int duracionhechizo) {
        this.duracionhechizo = duracionhechizo;
    }

    @Override
    public void atacar(Personaje objetivo, int distancia) {
        if(distancia<4) {
            System.out.println(getNombre()+" atacó con su magia a :"+objetivo.getNombre());
            for(int i=1;i<=duracionhechizo;i++) objetivo.recibirAtaque(getAtaque());
        }else{
            System.out.println(getNombre()+" no pudo atacar a "+objetivo.getNombre()+" debido a la distancia");
        }
    }
}