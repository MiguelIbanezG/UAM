package products;

public class PercentageDiscount extends Discount {

	public PercentageDiscount(String name, double value) {
		super(name, value);
	}

	@Override
	protected double getDiscount(double price) {		
		return price*this.value/100.0;
	}

}
