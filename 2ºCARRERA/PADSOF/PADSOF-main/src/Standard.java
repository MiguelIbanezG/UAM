
public class Standard extends Product {
    
    private double price;

    public Standard(Address address, int numAttempts, long weight, boolean lot, double price) {
        super(address, numAttempts, weight, lot);
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }
    public void setPrice(double price) {
        this.price = price;
        return;
    }
}