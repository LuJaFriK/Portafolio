/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package rpg;

import java.util.Random;

/**
 *
 * @author lujafrik
 */
public class RPG {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Personaje jugador = null;
        
        Personaje[] enemigos = new Personaje[5];
        enemigos[0] = new Guerrero("Gandalf", 10, 5,"Rojo");
        enemigos[1] = new Mago("Neldat", 20, 10,"Azul",4);
        enemigos[2] = new Mago("Hobbit", 30, 15,"Verde",3);
        enemigos[3] = new Arquero("Esqueleto", 15, 8,"Amarillo",80);
        enemigos[4] = new Guerrero("Zombie", 25, 12,"Morado");
        
        do{
            System.out.println("1. Crea tu personaje.");
            System.out.println("2. Enfrentate a un enemigo.");
            System.out.println("3. Salir");
            switch(Inputs.InputIntRange("Seleccione una opción: ",1,3)){
                case 1:
                    String nombre = Inputs.InputString("Ingresa tu nombre:");
                    double ataque;
                    String color = Inputs.InputString("Ingresa el color de tu vestimenta:");
                    System.out.println("1. Guerrero");
                    System.out.println("2. Mago");
                    System.out.println("3. Arquero");
                    switch(Inputs.InputIntRange("Seleccione una opción: ",1,3)){
                        case 1:
                            ataque = Math.random() * 35 + 5;
                            jugador = new Guerrero(nombre, 100, ataque,color);
                            break;
                        case 2:
                            Random rand = new Random();
                            int duracion = rand.nextInt(5);
                            ataque = Math.random() * 10 + 5;
                            jugador = new Mago(nombre, 100,ataque,color,duracion);
                            break;
                        case 3:
                            Random r = new Random();
                            int punteria = r.nextInt(90);
                            ataque = Math.random() * 30 + 5;
                            jugador = new Arquero(nombre, 100,ataque,color,punteria);
                            break;
                    }
                    break;
                case 2:
                    if (jugador != null) pelea(jugador,getEnemigo(enemigos));
                    break;
                case 3:
                    break;
            }
        }while(true);
    }
    public static Personaje getEnemigo(Personaje[] enemigos){
        Random rand = new Random();
        int indice = rand.nextInt(enemigos.length);
        return enemigos[indice];
    }

    private static void pelea(Personaje jugador, Personaje enemigo){
        String menu = """
        Que deseas hacer:
        1. Acercarte
        2. Alejarte
        3. Atacar
        """;
        int distancia = 0;
        while (jugador.getVida() > 0 && enemigo.getVida() > 0) {
            CLI(jugador, enemigo, distancia);
            if(Math.random()>=0.5){
                System.out.println("Tu turno:");
                Inputs.wait(500);
                switch (Inputs.InputIntRange(menu, 1, 4)) {
                    case 1:
                        if(distancia>0) distancia -=1;
                        else System.out.println("No se puede acercar más");
                        break;
                
                    case 2:
                        if(distancia<20) distancia +=1;
                        else System.out.println("No se puede alejar más");
                        break;

                    case 3:
                        jugador.atacar(enemigo, distancia);
                        break;
                    default:
                        System.out.println(enemigo.getNombre()+ " ha perdido su turno.");
                        break;
                }
            }else{
                System.out.println("Turno de "+ enemigo.getNombre());
                Inputs.wait(500);
                Random rand = new Random();
                switch(rand.nextInt(3)){
                    case 0:
                        if(distancia>0) {
                            distancia -=1;
                            System.out.println(enemigo.getNombre()+" se ha acercado un bloque");
                        }
                        System.out.println(enemigo.getNombre()+" se ha acercado un bloque");
                        break;
                
                    case 1:
                        if(distancia<20) {
                            distancia +=1;
                            System.out.println(enemigo.getNombre()+" se ha alejado un bloque");
                        } 
                        break;

                    case 2:
                        enemigo.atacar(jugador, distancia);
                        System.out.println(enemigo.getNombre()+" te ha atacado");
                        break;
                    default:
                        System.out.println(enemigo.getNombre()+ " ha perdido su turno.");
                        break;
                }
            Inputs.wait(2000);
            }
        }
        if(jugador.getVida() < 0) System.out.println("Perdiste");        
        else System.out.println("Ganaste");

        Inputs.wait(1000);
    }

    public static void CLI(Personaje jugador, Personaje enemigo, int distancia){
        for(int i=0;i>10;i++) System.out.println();
        System.out.print("[");
        for(int i=1;i<=(enemigo.getVida()/10);i++) {
            System.out.print("#");
        }
        System.out.println("] "+enemigo.getVida());

        System.out.println(enemigo+ "Distancia: "+distancia);
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.print("[");
        for(int i = 1 ; i<=(jugador.getVida()/10);i++) {
            System.out.print("=");
        }
        System.out.println("] "+jugador.getVida());
        System.out.println(jugador);
        for(int i=0;i>10;i++) System.out.println();
    }

}
