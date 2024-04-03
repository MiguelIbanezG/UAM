package products;

public abstract class Discount {
	private String name;
	protected double value;
	
	public Discount(String name, double value) {
		this.name = name;
		this.value = value;
	}

	@Override
	public String toString() {
		return this.name;
	}

	protected abstract double getDiscount(double price);
	
}
