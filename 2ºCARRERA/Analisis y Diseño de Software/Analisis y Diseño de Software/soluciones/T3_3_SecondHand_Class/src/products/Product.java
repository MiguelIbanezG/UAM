package products;

public class Product {
	private String name;
	private double price;
	private Discount discount;
	private static double maxPrice = 0;

	public Product(String name, double price, Discount discount) {
		this.name = name;
		this.price = price;
		this.discount = discount;
		updateMaxPrice();
	}

	private void updateMaxPrice() {
		if (this.getFinalPrice()>maxPrice)
			maxPrice = this.getFinalPrice();
	}

	@Override
	public String toString() {
		return this.name+" price: "+
			   this.getFinalPrice()+" with discount: "+this.discount;
	}

	public double getFinalPrice() {
		return this.price-this.discount.getDiscount(this.price);
	}

	public static double higherPrice() {
		return Product.maxPrice;
	}
}
