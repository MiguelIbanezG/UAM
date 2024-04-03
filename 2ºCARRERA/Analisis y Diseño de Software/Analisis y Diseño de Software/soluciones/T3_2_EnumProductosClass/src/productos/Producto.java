package productos;

public class Producto {
	private String nombre;
	private double precio;
	private TipoIva iva;

	public Producto(String nombre, double precio, TipoIva iva) {
		this.nombre = nombre;
		this.precio = precio;
		this.iva = iva;
	}

	@Override
	public String toString() {
		return "Producto [nombre=" + 
			   this.nombre + ", precio=" + 
			   this.precio + ", iva=" + 
			   this.iva + ", precio final="+
			   String.format("%.2f", this.precioFinal())+"]";
	}

	public double precioFinal() {
		return this.precio+this.precio*this.iva.getIva()/100.0;
	}

}
