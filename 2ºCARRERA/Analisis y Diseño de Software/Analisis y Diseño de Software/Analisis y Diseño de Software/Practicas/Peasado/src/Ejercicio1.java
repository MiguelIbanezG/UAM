
public class Ejercicio1 {
	public static void main(String[] args) { // Producto.TRACE = true;
		Producto p1 = new Pizza(TipoMasa.FINA,"jamón", "ternera", "cebolla", "pimiento");
		Producto b1 = new Bebida("refresco", 9, 1.0);
		Producto p2 = new Pizza("jaguayana", 6.25);
		Producto b2 = new Bebida("cerveza", 4, 1.25);
		Producto c1 = new Complemento("alitas", 7.75);
		Producto c2 = new Complemento("helado", 2.25);
		// ejemplos de uso de productos
		System.out.println(p1 + " promocional: " + p1.promocional());
		System.out.println(b1 + " coste: " + b1.coste()); // con descuento por cantidad
		System.out.println(c1 + " especialidad: " + c1.especialidad());
		System.out.println(c2 + " promocional: " + c2.promocional());


 	// creación de pedidos: pe1 con descuento a promocionales, pe2 sin dto. promocionales
 	Pedido pe1 = new Pedido(), pe2 = new Pedido();
 	double precio1 = pe1.añadir(p1).añadir(b1).añadir(p2).añadir(c1).añadir(b2).cerrar();
 	System.out.println("precio1 = "+precio1);

 	pe2.añadir(p1).añadir(b1).añadir(p2).añadir(c2);

 	// facturación
 	System.out.println(Pedido.facturacion());
 	pe2.cerrar();
 	System.out.println(Pedido.facturacion());

 }// end método main
}// end clase Ejercicio2
