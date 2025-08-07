class Lenguaje 
{
    private string nombre;
    private int costo;

    public Lenguaje(string nombre, int costo)
    {
        this.nombre = nombre;
        this.costo = costo;
    }

    public string Nombre
    {
        get { return nombre; }
        set { nombre = value; }
    }

    public int Costo
    {
        get { return costo; }
        set { costo = value; }
    }
}
