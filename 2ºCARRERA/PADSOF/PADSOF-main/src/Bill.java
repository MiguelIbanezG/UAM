import java.util.List;
import java.util.ArrayList;

public class Bill {

    private double price;
    private List<Order> orders;
    private Customer customer;


   public Bill(double price, Customer customer)
   {
       this.price = price;
       this.orders = new ArrayList<Order>();
       this.customer = customer;
   }


    public double getPrice() {
        return this.price;
    }

    public Customer getCustomer(){
        return this.customer;
    }

    public List<Order> getOrders() {
        return this.orders;
    }

    public void setOrders (List<Order> orders)
    {
        this.orders = orders;
        return;
    }

    public void setPrice (double price)
    {
        this.price = price;
        return;
    }

    public void setCustomer(Customer customer)
    {
        this.customer = customer;
    }

    public void addOrder(Order order) {
        this.orders.add(order);
        return;
    }
    
}     