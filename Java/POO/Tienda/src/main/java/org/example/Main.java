package org.example;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        Pantalon[] pantalones = new Pantalon[10];
        String marca,talla;
               pantalones[0] = new Pantalon();
               pantalones[0].setMarca("Levi's");
               pantalones[0].setTalla("M");
               pantalones[0].setTipo(1);
               pantalones[0].setCinturaAjustable("Si");
               pantalones[0].setPrecio(500.0);
       
               pantalones[1] = new Pantalon();
               pantalones[1].setMarca("Wrangler");
               pantalones[1].setTalla("L");
               pantalones[1].setTipo(2);
               pantalones[1].setCinturaAjustable("No");
               pantalones[1].setPrecio(450.0);
       
               pantalones[2] = new Pantalon();
               pantalones[2].setMarca("Lee");
               pantalones[2].setTalla("S");
               pantalones[2].setTipo(1);
               pantalones[2].setCinturaAjustable("Si");
               pantalones[2].setPrecio(600.0);
       
               pantalones[3] = new Pantalon();
               pantalones[3].setMarca("Calvin Klein");
               pantalones[3].setTalla("M");
               pantalones[3].setTipo(2);
               pantalones[3].setCinturaAjustable("No");
               pantalones[3].setPrecio(800.0);
       
               pantalones[4] = new Pantalon();
               pantalones[4].setMarca("Tommy Hilfiger");
               pantalones[4].setTalla("L");
               pantalones[4].setTipo(1);
               pantalones[4].setCinturaAjustable("Si");
               pantalones[4].setPrecio(750.0);
       
               pantalones[5] = new Pantalon();
               pantalones[5].setMarca("Diesel");
               pantalones[5].setTalla("S");
               pantalones[5].setTipo(2);
               pantalones[5].setCinturaAjustable("No");
               pantalones[5].setPrecio(900.0);
       
               pantalones[6] = new Pantalon();
               pantalones[6].setMarca("Guess");
               pantalones[6].setTalla("M");
               pantalones[6].setTipo(1);
               pantalones[6].setCinturaAjustable("Si");
               pantalones[6].setPrecio(650.0);
       
               pantalones[7] = new Pantalon();
               pantalones[7].setMarca("Nike");
               pantalones[7].setTalla("L");
               pantalones[7].setTipo(2);
               pantalones[7].setCinturaAjustable("No");
               pantalones[7].setPrecio(550.0);
        int opc, i=0,max=0;
        while(pantalones[max]!=null&&max<pantalones.length-1){
            max++;
        }
        do {
            System.out.println("1.- Registrar un pantalón.");
            System.out.println("2.- Vender un pantalón.");
            System.out.println("3.- Desplegar catalogo.");
            System.out.println("4.- Buscar un pantalón.");
            System.out.println("5.- Salir.");
            opc = leer.nextInt();
            leer.nextLine();
            switch(opc) {
                case 1:
                i=0;
                while(pantalones[i]!=null&&i<pantalones.length-1){i++;}
                pantalones[i]=new Pantalon();
                System.out.println("Ingresa el tipo de pantalón:");
                System.out.println("1.Casual            2.Vestir");
                pantalones[i].setTipo(leer.nextInt());
                System.out.println("Ingresa la marca del pantalón:");
                pantalones[i].setMarca(leer.nextLine());
                System.out.println("Ingresa la talla del pantalón:");
                pantalones[i].setTalla(leer.nextLine());
                System.out.println("El pantalón es de cintura ajustable?");
                pantalones[i].setCinturaAjustable(leer.nextLine());
                System.out.println("Ingresa el precio del pantalón:");
                pantalones[i].setPrecio(leer.nextDouble());
                    break;
                case 2:
                i=0;
                    System.out.println("Buscar por ID?");
                    System.out.println("1.- Si.      2.- No.");
                    int opt = leer.nextInt();
                    leer.nextLine();
                        System.out.println("Ingresa la marca del pantalón");
                        marca = leer.nextLine();
                        System.out.println("Ingresa la talla del pantalón:");
                        talla = leer.nextLine();
                        buscarpantalon(pantalones,marca,talla,true,max);
                    break;
                case 3:
                System.out.println("Catalogo de pantalones: ");
                i = 0;
                    while(i<pantalones.length-1&&pantalones[i]!=null){
                        System.out.println("----------------------");
                        System.out.println("ID: "+i);
                        pantalones[i].info();
                        System.out.println("----------------------");
                        i++;
                    }
                    break;
                case 4:
                i=0;
                System.out.println("Buscar por ID?");
                System.out.println("1.- Si.      2.- No.");
                opt = leer.nextInt();
                leer.nextLine();
                if (opt==1){
                    System.out.println("Ingrese el ID del pantalón:");
                    i = leer.nextInt();
                    System.out.println("----------------------");
                    System.out.println("ID: "+i);
                    pantalones[i].info();
                    System.out.println("----------------------");
                }else{
                    System.out.println("Ingresa la marca del pantalón");
                    marca = leer.nextLine();
                    System.out.println("Ingresa la talla del pantalón:");
                    talla = leer.nextLine();
                    buscarpantalon(pantalones,marca,talla,false,max);
                }
                    break;
                case 5:
                    System.out.println("Salir");
                    break;
                default:
                    System.out.println("Error. Opción no válida.");
                    break;
            }
        } while(opc != 5);
    }
    public static void buscarpantalon(Pantalon[] pantalones,String marca, String talla,boolean comprar,int max){
        int i=0;
        int sumatoria=0;
        for(i=0;i<=max;i++){
            if(pantalones[i]!=null&&pantalones[i].getMarca().equalsIgnoreCase(marca)&&pantalones[i].getTalla().equalsIgnoreCase(talla)){
                System.out.println("----------------------");
                System.out.println("ID: "+i);
                pantalones[i].info();
                System.out.println("----------------------");
                sumatoria += 1;
                i++;
            }
        }
        if (sumatoria>1){
            System.out.println("Hay más de un modelo posible, favor de ingresar el ID del pantalón.");
        }else if (sumatoria ==0){
            System.out.println("No hay coincidencias.");
        }else if(sumatoria ==1&&comprar){
            double iva = 0.16;
            double subtotal = pantalones[i].getPrecio();
            double total = subtotal * (1 + iva);
            String afi = "No.";
            if (pantalones[i].getCinturaAjustable()){
                afi = "Si.";
            }
            System.out.println("---------- TICKET DE COMPRA ----------");
            System.out.println("Marca: " + pantalones[i].getMarca());
            System.out.println("Talla: " + pantalones[i].getTalla());
            System.out.println("Tipo: " + pantalones[i].getTipo());
            System.out.println("Cintura ajustable: " + afi);
            System.out.println("Precio unitario: $" + pantalones[i].getPrecio());
            System.out.println("Subtotal: $" + subtotal);
            System.out.println("IVA (16%): $" + (subtotal * iva));
            System.out.println("Total: $" + total);
            System.out.println("--------------------------------------");
        }
        }
}