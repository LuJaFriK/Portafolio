package rpg;

public class Guerrero extends Personaje {
    public Guerrero(String nombre, double vida, double ataque, String color) {
        super(nombre, vida, ataque, color);
        setArma( "Espada");
    }
    @Override
    public void atacar(Personaje objetivo, int distancia) {
        if(distancia<1) {
            objetivo.recibirAtaque(getAtaque());
            System.out.println(getNombre()+" atacó con su espada a :"+objetivo.getNombre());
            System.out.println();
        }else{
            System.out.println(getNombre()+" no pudo atacar a "+objetivo.getNombre()+" debido a la distancia");
        }
    }
}