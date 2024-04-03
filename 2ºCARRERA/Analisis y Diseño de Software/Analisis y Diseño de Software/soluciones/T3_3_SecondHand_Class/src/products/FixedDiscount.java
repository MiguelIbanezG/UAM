package products;

public class FixedDiscount extends Discount {

	public FixedDiscount(String name, double value) {
		super(name, value);
	}

	@Override
	protected double getDiscount(double price) {
		return this.value;
	}

}
