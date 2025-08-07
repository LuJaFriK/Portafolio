public class Viaje {
    String origen;
    String destino;
    int duracion;
    double precio;
    public Viaje() {
        
    }
    public Viaje(String origen, String destino, int duracion, double precio) {
        this.origen = origen;
        this.destino = destino;
        this.duracion = duracion;
        this.precio = precio;
    }
    public String toString() {
        return "Origen: " + origen + ", Destino: " + destino + ", Duracion: " + duracion + ", Precio: " + precio;
    }
    public void setDuracion(int duracion) {
        this.duracion = duracion;
    }
    public int getDuracion() {
        return duracion;
    }
    public void setPrecio(double precio) {
        this.precio = precio;
    }
    public void setOrigen(String origen) {
        this.origen = origen;
    }
    public void setDestino(String destino) {
        this.destino = destino;
    }
    public String getOrigen() {
        return origen;
    }
    public String getDestino() {
        return destino;
    }