
public abstract class Product {
    private Address address ;
    private int numAttempts;    
    private long weight;
    private double price;
    private DeliveryStatus status;


    public Product(Address address, int numAttempts, long weight, boolean lot, double price, DeliveryStatus status) {
        this.address = address;
        this.numAttempts = numAttempts;
        this.weight = weight;
        this.price = price;
        this.status = status;

    }

    public Address getAddress() {
        return this.address;
    }
    public long getWeight() {
        return this.weight;
    }
    public DeliveryStatus getStatus() {
        return this.status;
    }
    public int getnumAttempts()
    {
        return this.numAttempts;
    }

    public void setAddress(Address address) {
        this.address = address;
    }
    public void setWeight(long weight) {
        this.weight = weight;
    }
    public void setStatus(DeliveryStatus status) {
        this.status = status;
    }


    public void setnumAttempts(int numAttempts)
    {
        this.numAttempts = numAttempts;
    }

    public void setPrice(double price) {
        this.price = price;
    }
    public double getPrice() {
        return this.price;
    }

}