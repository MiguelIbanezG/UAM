import java.util.Date;
import java.util.List;
import java.util.ArrayList;

public abstract class Order {
    private int numAttempts;
    private double cost;
    private Date date;
    private DeliveryStatus status;
    private List<Product> products;

    public Order(int numAttempts, double cost, Date date, DeliveryStatus status) {
        this.numAttempts = numAttempts;
        this.cost = cost;
        this.date = date;
        this.status = status;
        this.products = new ArrayList<Product>();
    }

    public int getNumAttempts() {
        return this.numAttempts;
    }
    public double getCost() {
        return this.cost;
    }
    public Date getDate() {
        return this.date;
    }
    public DeliveryStatus getState() {
        return this.status;
    }

    public void setNumAttempts(int numAttempts) {
        this.numAttempts = numAttempts;
        return;
    }
    public void setCost(double cost) {
        this.cost = cost;
        return;
    }
    public void setDate(Date date) {
        this.date = date;
        return;
    }
    public void setStatus(DeliveryStatus status) {
        this.status = status;
        return;
    }

    public void addProduct(Product product) {
        this.products.add(product);
        return;
    } 
}
