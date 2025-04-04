/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package clubcampestre;

/**
 *
 * @author lujafrik
 */
public class Socio {
    private double cuota;
    private
    private
    private

    public double calcularPagoMensual(){
          final double IMP_MPAL=0.02;
          final double IVA = 0.16;
          double pago=0,montoImpMpal,montoIVA;
          montoIVA=cuota*IVA;
          pago=cuota+montoImpMpal+montoIVA;
          System.out.println("Detalle");
          System.out.println("Cuota: "+cuota);
          System.out.println("Impuesto Municipal: "+montoImpMpal);
          System.out.println("IVA (16%):"+montoIVA);
          return pago;
    }
}
