import java.util.List;
import java.util.ArrayList;

public class Package {

    private boolean urgent;
    private List<Order> orders; 

    public Package(boolean urgent)
    {
        this.urgent = urgent;
        this.orders = new ArrayList<Order>();
    }
    
    public boolean getUrgent() {
        return this.urgent;
    }
    public List<Order> getOrders() {
        return this.orders;
    }

    public void setUrgente (boolean urgent)
    {
        this.urgent = urgent;
        return;
    }

    public void setOrders (List<Order> orders)
    {
        this.orders = orders;
        return;
    }
    
    public void addOrder(Order order) {
        this.orders.add(order);
        return;
    }
}
