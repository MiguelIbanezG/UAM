package products;

public class Warehouse {
	public static void main(String[] args) {
		// p1 is a Product with price 150.0€, and 15.0% discount due to promotion "no VAT"
		Product p1 = new Product("Floor lamp", 150.0,
								  new PercentageDiscount("No VAT", 15.0));
		// p2 is a Product with price 90.0€, and 10.0€ discount by “clearance”
		Product p2 = new Product("Cutlery 50 items", 90.0,
								new FixedDiscount("Clearance", 10.0));
		System.out.println("Products in warehouse:\n "+p1+"\n "+p2);
		System.out.println("Higher price: "+Product.higherPrice()); 
	}
}

