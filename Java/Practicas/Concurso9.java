import java.util.Scanner;
import java.util.ArrayList;
public class Concurso9 {
    public static void main (String[]args){
        ArrayList<String> trabajadores = new ArrayList<>();
        trabajadores.add("Sebas");
        trabajadores.add("Luis");
        trabajadores.add("Paco");
        trabajadores.add("Memo");
        trabajadores.add("Hugo");
        Scanner leer = new Scanner (System.in);
        int opc=0,i=0;
        String srch;
        boolean found = false;
        do{
            System.out.println("1.- Agregar un trabajador.");
            System.out.println("2.- Modificar el nombre de un trabajador.");
            System.out.println("3.- Eliminar un trabajador un trabajador.");
            System.out.println("4.- Mostrar todos los trabajadores registrados.");
            System.out.println("5.- Salir.");
            opc = leer.nextInt();
            leer.nextLine();
            switch (opc){
                case 1:
                    System.out.println("Ingresa el nombre del nuevo trabajador:");
                    trabajadores.add(leer.nextLine());
                break;
                case 2:
                    System.out.println("Ingresa el nombre del trabajador a modificar:");
                    srch = leer.nextLine();
                    int mod = srch(trabajadores,srch);
                    if(mod==-1){System.out.println("Error. El trabajador no existe.");}
                    else{
                        System.out.println("Ingresa el nuevo nombre del trabajador:");
                        trabajadores.set(mod, leer.nextLine());
                        System.out.println("Nombre exitosamente corregido.");}
                break;
                case 3:
                    System.out.println("Ingresa el nombre del trabajador a eliminar:");
                    srch = leer.nextLine();
                    int erase = srch(trabajadores,srch);
                    if(erase==-1){System.out.println("Error. El trabajador no existe.");}
                    else{
                        trabajadores.remove(erase);
                        System.out.println("Nombre exitosamente eliminado.");}
                break;
                case 4:
                System.out.println(trabajadores); 
                break;
                case 5:
                    System.out.println("Saliendo...");
                break;
                default:
                    System.out.println("La opción seleccionada no es válida.");
                break;
            }
        }while(opc!=5);
        leer.close();
    }
    public static int srch (ArrayList<String> trabajadores,String srch){
        boolean found = false;
        int i=0;
        do{
            if(trabajadores.get(i).equals(srch)){
                found = true;
            }else if(i==trabajadores.size()&&found==false){i=-1;
            }else{i++;}   
        }while(found==false || i==-1);
        return i;
    }
}