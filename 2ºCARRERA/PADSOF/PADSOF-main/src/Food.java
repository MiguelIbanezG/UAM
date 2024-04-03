
public class Food extends Product {
    
    private Double price;
    private Foodtype type;

    public Food(Address address, int numAttempts, long weight, boolean lot, double price, Foodtype type) {
        super(address, numAttempts, weight, lot);
        this.price = price;
        this.type = type;
    }

    public Foodtype getType() {
        return this.type;
    }

    public void setType(Foodtype type) {
        this.type = type;
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    
}
