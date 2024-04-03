import java.util.List;


import java.util.ArrayList;
import java.util.Date;


public class DeliveryPlan {

    private Date date;
    private List<Truck> trucks;
    private List<DeliveryMan> deliveryMen;

    public DeliveryPlan(Date date) 
    {
        this.date = date;
        this.trucks = new ArrayList<Truck>();
        this.deliveryMen = new ArrayList<DeliveryMan>();
    }   

    
    
    
    public Date getDate()
    {
        return this.date;
    }

    public List<Truck> getTrucks()
    {
        return this.trucks;
    }

    public List<DeliveryMan> getDeliveryMen()
    {
        return this.deliveryMen;
    }


    public void setDate(Date date)
    {
        this.date = date;
    }

    public void setTrucks (List<Truck> trucks)
    {
        this.trucks = trucks;
    }

    public void setDeliverymen(List<DeliveryMan> deliveryMen)
    {
        this.deliveryMen = deliveryMen;
    }

    public void addTrucks (Truck truck)
    {
        this.trucks.add(truck);
    }

    public void addDeliverymen(DeliveryMan deliveryman)
    {
        this.deliveryMen.add(deliveryman);
    }


}