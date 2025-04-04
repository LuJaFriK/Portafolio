package pagos;

public class TarjetaCredito implements MetodoPago{
     
     private String noTargeta;

     public TarjetaCredito(String noTargeta){
          this.noTargeta = noTargeta;
     }

     
     @Override
     public void procesarPago(double cantidad) {
          System.out.println("Pagado : $ "+ cantidad+" mxn con Targeta de Credito: "+ noTargeta);
     }
}
