package productos;

public class ProductosMain {

	public static void main(String[] args) {
		Producto[] products = {
				new Producto("Pan", 0.5, TipoIva.EXENTO),
				new Producto("Leche", 1.5, TipoIva.SUPERREDUCIDO),
				new Producto("Libro", 15, TipoIva.REDUCIDO),
				new Producto("Cerveza", 0.8, TipoIva.NORMAL)
		};

		for (Producto p : products)
			System.out.println(p);
	}
}

