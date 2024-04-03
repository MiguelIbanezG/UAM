
public class Pizza extends Producto {
	private String nombre;
	private String[] ingredientes;
	private double precio;
	private boolean especialidad;
	private static int masa = 2;
	private static double ingrediente = 2;
	
	public Pizza(String nombre, String...ingredientes) {
		this.nombre = nombre;
		this.ingredientes = ingredientes;
	
		
	}
	
	public Pizza(String nombre, double precio) {
		this.nombre = nombre;
		this.precio = precio;
	}

}
