package pagos;

public class PayPal implements MetodoPago {
     private String email;

     public PayPal(String email){
          this.email = email;
     }


     @Override
     public void procesarPago(double cantidad) {
          System.out.println("Pagado : $ "+ cantidad+" mxn con Paypal: "+ email);
          
     }
}
