import java.lang.classfile.attribute.SourceDebugExtensionAttribute;
import java.util.Scanner;

import javax.lang.model.type.UnionType;

public class Main {
    public static void main(String[] args) {
        Medico[] medicos = new medicos[10];
        Psiquiatra[] psiquiatras = new Psiquiatra[10];
        Cardiologo[] cardiologos = new Cardiologo[10];
        Scanner scanner = new Scanner(System.in);
        int opc=0, i=0;
        do{
            menu();
            switch (opc){
                case 1:
                System.out.println("Ingresa el tipo de medico:");
                System.out.println("1. Medico general.");
                System.out.println("2. Cardiologo");
                System.out.println("3. Psiquiatra");
                int opt = scanner.nextInt();
                scanner.nextLine();
                if(opt == 1){
                    while(medicos[i]!=null&&medicos[i].getNombre()!=null&&i>medicos.length-1){i++;}
                    registrarMedico(scanner, medicos[i], i);
                }if(opt == 2){
                    while(cardiologos[i]!=null&&cardiologos[i].getNombre()!=null&&i>cardiologos.length-1){i++;}
                    registrarCardiologo(scanner, cardiologos[i], i);
                }else if(opt == 3){
                    while(psiquiatras[i]!=null&&psiquiatras[i].getNombre()!=null&&i>psquiatras.length-1){i++;}
                    registrarPsiquiatra(scanner, psiquiatras[i], i);
                }else{
                    System.out.println("Error. El valor ingresado no es valido.");
                }
                break;
                case 2:
                System.out.println("Listas de medicos:");
                System.out.println("Medicos generales:");
                 while(medicos[i]!=null&&medicos[i].getNombre()!=null&&i>medicos.length-1){
                     System.out.println("--------------------------");
                     medicos[i].info();
                     System.out.println("--------------------------");
                     i++;
                 }i=0;
                 System.out.println("Cardiologos:");
                 while(cardiologos[i]!=null&&cardiologos[i].getNombre()!=null&&i>cardiologos.length-1){
                     System.out.println("--------------------------");
                     cardiologos[i].info();
                     System.out.println("--------------------------");
                     i++;
                 }i=0;
                 System.out.println("Psiquiatras:");
                 while(psquiatras[i]!=null&&psquiatras[i].getNombre()!=null&&i>psiquiatras.length-1){
                     System.out.println("--------------------------");
                     psiquiatras[i].info();
                     System.out.println("--------------------------");
                     i++;
                 }
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                System.out.println("Saliendo...");
                break;
                default:
                System.out.println("Error. Opcion no valida.");
                break;
            }
        }while(opc!=5);
        scanner.close();
    }
    public static void menu(){
        System.out.println("1. Registrar un Medico nuevo.");
        System.out.println("2. Lista de Medicos.");
        System.out.println("3. Buscar un medico.");
        System.out.println("4. Especializar un medico.");
        System.out.println("5. Salir.");
    }
    
    public static void registrarMedico(Scanner scanner,Medico[] medicos,int i){
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        medicos[i] = new Medico(nombre,cedula,universidad);
    }
    public static void registrarCardiologo(Scanner scanner,Cardiologo[] cardiologos, int i){
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        System.out.println("Ingresa la subespecialidad del cardiologo:");
        String subespecialidad = scanner.nextLine();
        cardiologos[i] = new Cardiologo(nombre,cedula,universidad,subespecialidad);
    }
    public static void registrarPsiquiatra(Scanner scanner,Psiquiatra[] psiquiatras, int i){
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        psiquiatras[i] = new Psiquiatra(nombre,cedula,universidad);
    }
    
}
