/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
import java.util.Scanner;

public class Hospital {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Medico[] medicos = new Medico[10];
        Psiquiatra[] psiquiatras = new Psiquiatra[10];
        Cardiologo[] cardiologos = new Cardiologo[10];
        Scanner scanner = new Scanner(System.in);
        int opc = 0, i = 0; 
        do {
            menu();
            opc = scanner.nextInt();
            scanner.nextLine(); 
            switch (opc) {
                case 1:
                    System.out.println("Ingresa el tipo de medico:");
                    System.out.println("1. Medico general.");
                    System.out.println("2. Cardiologo");
                    System.out.println("3. Psiquiatra");
                    int opt = scanner.nextInt();
                    scanner.nextLine(); 
                    int currentGeneralIndex = 0;
                    while (currentGeneralIndex < medicos.length && medicos[currentGeneralIndex] != null) {
                        currentGeneralIndex++;
                    }

                    int currentCardioIndex = 0;
                    while (currentCardioIndex < cardiologos.length && cardiologos[currentCardioIndex] != null) {
                        currentCardioIndex++;
                    }

                    int currentPsiqIndex = 0;
                    while (currentPsiqIndex < psiquiatras.length && psiquiatras[currentPsiqIndex] != null) {
                        currentPsiqIndex++;
                    }


                    if (opt == 1) {
                        if (currentGeneralIndex < medicos.length) {
                            registrarMedico(scanner, medicos, currentGeneralIndex);
                        } else {
                            System.out.println("No hay espacio para mas medicos generales.");
                        }
                    } else if (opt == 2) {
                        if (currentCardioIndex < cardiologos.length) {
                            registrarCardiologo(scanner, cardiologos, currentCardioIndex);
                        } else {
                            System.out.println("No hay espacio para mas cardiologos.");
                        }
                    } else if (opt == 3) {
                         if (currentPsiqIndex < psiquiatras.length) {
                            registrarPsiquiatra(scanner, psiquiatras, currentPsiqIndex);
                        } else {
                            System.out.println("No hay espacio para mas psiquiatras.");
                        }
                    } else {
                        System.out.println("Error. El valor ingresado no es valido.");
                    }
                    break;
                case 2:
                    System.out.println("Listas de medicos:");
                    System.out.println("\nMedicos generales:");
                    boolean foundGeneral = false;
                    for (int k = 0; k < medicos.length; k++) {
                        if (medicos[k] != null) {
                            System.out.println("--------------------------");
                            medicos[k].info();
                            System.out.println("--------------------------");
                            foundGeneral = true;
                        }
                    }
                    if (!foundGeneral) System.out.println("No hay medicos generales registrados.");

                    System.out.println("\nCardiologos:");
                    boolean foundCardio = false;
                    for (int k = 0; k < cardiologos.length; k++) {
                        if (cardiologos[k] != null) {
                            System.out.println("--------------------------");
                            cardiologos[k].info(); 
                            System.out.println("Subespecialidad: " + cardiologos[k].getSubespecialidad());
                            System.out.println("--------------------------");
                            foundCardio = true;
                        }
                    }
                     if (!foundCardio) System.out.println("No hay cardiologos registrados.");

                    System.out.println("\nPsiquiatras:");
                    boolean foundPsiq = false;
                    for (int k = 0; k < psiquiatras.length; k++) {
                        if (psiquiatras[k] != null) {
                            System.out.println("--------------------------");
                            psiquiatras[k].info(); 
                            System.out.println("--------------------------");
                            foundPsiq = true;
                        }
                    }
                    if (!foundPsiq) System.out.println("No hay psiquiatras registrados.");
                    break;
                case 3:
                    buscarMedico(scanner, medicos, cardiologos, psiquiatras);
                    break;
                case 4:
                    especializarMedico(scanner, medicos, cardiologos, psiquiatras);
                    break;
                case 5:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Error. Opcion no valida.");
                    break;
            }
        } while (opc != 5);
        scanner.close();
    }

    public static void menu() {
        System.out.println("\n--- MENU HOSPITAL ---");
        System.out.println("1. Registrar un Medico nuevo.");
        System.out.println("2. Lista de Medicos.");
        System.out.println("3. Buscar un medico.");
        System.out.println("4. Especializar un medico.");
        System.out.println("5. Salir.");
        System.out.print("Selecciona una opcion: ");
    }

    public static void registrarMedico(Scanner scanner, Medico[] medicos, int index) {
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        medicos[index] = new Medico(nombre, cedula, universidad);
        System.out.println("Medico general registrado exitosamente.");
    }

    public static void registrarCardiologo(Scanner scanner, Cardiologo[] cardiologos, int index) {
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        System.out.println("Ingresa la subespecialidad del cardiologo:");
        String subespecialidad = scanner.nextLine();
        cardiologos[index] = new Cardiologo(nombre, cedula, universidad, subespecialidad);
        System.out.println("Cardiologo registrado exitosamente.");
    }

    public static void registrarPsiquiatra(Scanner scanner, Psiquiatra[] psiquiatras, int index) {
        System.out.println("Ingresa el nombre del medico:");
        String nombre = scanner.nextLine();
        System.out.println("Ingresa la cedula profesional del medico:");
        int cedula = scanner.nextInt();
        scanner.nextLine(); 
        System.out.println("Ingresa la universidad de procedencia del medico:");
        String universidad = scanner.nextLine();
        psiquiatras[index] = new Psiquiatra(nombre, cedula, universidad);
        System.out.println("Psiquiatra registrado exitosamente.");
    }

    public static void buscarMedico(Scanner scanner, Medico[] medicosGenerales, Cardiologo[] cardiologos, Psiquiatra[] psiquiatras) {
        System.out.println("¿Que tipo de medico desea buscar?");
        System.out.println("1. Medico general");
        System.out.println("2. Cardiologo");
        System.out.println("3. Psiquiatra");
        System.out.print("Opcion: ");
        int tipoBusqueda = scanner.nextInt();
        scanner.nextLine(); 

        System.out.print("Ingrese el nombre del medico a buscar: ");
        String nombreBusqueda = scanner.nextLine();
        boolean encontrado = false;

        switch (tipoBusqueda) {
            case 1:
                System.out.println("\nBuscando Medicos Generales...");
                for (Medico medico : medicosGenerales) {
                    if (medico != null && medico.getNombre().equalsIgnoreCase(nombreBusqueda)) {
                        System.out.println("--- Medico Encontrado ---");
                        medico.info();
                        System.out.println("-------------------------");
                        encontrado = true;
                        break;
                    }
                }
                break;
            case 2:
                System.out.println("\nBuscando Cardiologos...");
                for (Cardiologo cardiologo : cardiologos) {
                    if (cardiologo != null && cardiologo.getNombre().equalsIgnoreCase(nombreBusqueda)) {
                        System.out.println("--- Cardiologo Encontrado ---");
                        cardiologo.info();
                        System.out.println("Subespecialidad: " + cardiologo.getSubespecialidad());
                        System.out.println("---------------------------");
                        encontrado = true;
                        break;
                    }
                }
                break;
            case 3:
                System.out.println("\nBuscando Psiquiatras...");
                for (Psiquiatra psiquiatra : psiquiatras) {
                    if (psiquiatra != null && psiquiatra.getNombre().equalsIgnoreCase(nombreBusqueda)) {
                        System.out.println("--- Psiquiatra Encontrado ---");
                        psiquiatra.info();
                        System.out.println("---------------------------");
                        encontrado = true;
                        break;
                    }
                }
                break;
            default:
                System.out.println("Tipo de medico no valido.");
                return;
        }

        if (!encontrado) {
            System.out.println("No se encontro ningun medico con el nombre '" + nombreBusqueda + "' del tipo especificado.");
        }
    }


    public static void especializarMedico(Scanner scanner, Medico[] medicosGenerales, Cardiologo[] cardiologos, Psiquiatra[] psiquiatras) {
        System.out.print("Ingrese el nombre del Medico General a especializar: ");
        String nombreMedicoGeneral = scanner.nextLine();

        int indiceMedicoGeneral = -1;
        Medico medicoAEspecializar = null;

        for (int k = 0; k < medicosGenerales.length; k++) {
            if (medicosGenerales[k] != null && medicosGenerales[k].getNombre().equalsIgnoreCase(nombreMedicoGeneral)) {
                medicoAEspecializar = medicosGenerales[k];
                indiceMedicoGeneral = k;
                break;
            }
        }

        if (medicoAEspecializar == null) {
            System.out.println("No se encontro un Medico General con el nombre '" + nombreMedicoGeneral + "'.");
            return;
        }

        System.out.println("Medico encontrado: ");
        medicoAEspecializar.info();
        System.out.println("¿A que especialidad desea cambiarlo?");
        System.out.println("1. Cardiologo");
        System.out.println("2. Psiquiatra");
        System.out.print("Opcion: ");
        int tipoEspecialidad = scanner.nextInt();
        scanner.nextLine(); 

        switch (tipoEspecialidad) {
            case 1: 
                int indiceLibreCardiologo = -1;
                for (int k = 0; k < cardiologos.length; k++) {
                    if (cardiologos[k] == null) {
                        indiceLibreCardiologo = k;
                        break;
                    }
                }

                if (indiceLibreCardiologo == -1) {
                    System.out.println("No hay espacio para mas Cardiologos. No se puede especializar.");
                    return;
                }

                System.out.print("Ingrese la subespecialidad del Cardiologo: ");
                String subespecialidad = scanner.nextLine();
                
                cardiologos[indiceLibreCardiologo] = new Cardiologo(
                        medicoAEspecializar.getNombre(),
                        medicoAEspecializar.getCedula(),
                        medicoAEspecializar.getEscuela(),
                        subespecialidad
                );
                medicosGenerales[indiceMedicoGeneral] = null; 
                System.out.println("Medico '" + nombreMedicoGeneral + "' especializado a Cardiologo exitosamente.");
                break;

            case 2: 
                int indiceLibrePsiquiatra = -1;
                for (int k = 0; k < psiquiatras.length; k++) {
                    if (psiquiatras[k] == null) {
                        indiceLibrePsiquiatra = k;
                        break;
                    }
                }

                if (indiceLibrePsiquiatra == -1) {
                    System.out.println("No hay espacio para mas Psiquiatras. No se puede especializar.");
                    return;
                }

                psiquiatras[indiceLibrePsiquiatra] = new Psiquiatra(
                        medicoAEspecializar.getNombre(),
                        medicoAEspecializar.getCedula(),
                        medicoAEspecializar.getEscuela()
                );
                medicosGenerales[indiceMedicoGeneral] = null; 
                System.out.println("Medico '" + nombreMedicoGeneral + "' especializado a Psiquiatra exitosamente.");
                break;

            default:
                System.out.println("Tipo de especialidad no valido.");
                break;
        }
    }
}
