public class sexo{
    public static void main (String[]args){
        long sumatoria=500000;
        long ganancia=500000;
        System.out.println(ganancia);
        for(int i=1;i<13;i++){
            ganancia=(ganancia*11)/10;
            System.out.println(i+":"+ganancia);
            sumatoria+=ganancia;
        }
        System.out.println("Sumatoria"+sumatoria);
    }
}