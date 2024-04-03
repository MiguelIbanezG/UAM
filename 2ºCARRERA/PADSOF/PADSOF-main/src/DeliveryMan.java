


public class DeliveryMan extends User{

    private long mobile;
    private Truck truck;


    public DeliveryMan(String user, String pass, String name, long mobile, Truck truck){

        super(user, pass, name);
        this.mobile = mobile;
        this.truck = truck;
    }

    public long getMobile()
    {
        return this.mobile;
    }

    public Truck getTruck()
    {
        return this.truck;
    }

    public void setMobile(long mobile)
    {
        this.mobile = mobile;
    }

    public void setTruck(Truck truck)
    {
        this.truck = truck;
    }
}
