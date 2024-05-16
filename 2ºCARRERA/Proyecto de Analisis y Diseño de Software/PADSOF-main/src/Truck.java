import java.util.List;
import java.util.ArrayList;

public abstract class Truck {

    private String plate;
    private double maxWeight;
    private List<Integer> pcs;
    private List<Address> addresses;
    
    public Truck(String inPlate, double inMaxWeight)
    {
        this.plate = inPlate;
        this.maxWeight = inMaxWeight;
        this.pcs = new ArrayList<Integer>();
        this.addresses = new ArrayList<Address>();
    }

    public String getPlate() {
        return this.plate;
    }
    public double getMaxWeight() {
        return this.maxWeight;
    }
    public List<Integer> getPcs() {
        return this.pcs;
    }
    public List<Address> getAddresses() {
        return this.addresses;
    }
    
    public void setPlate(String plate) {
        this.plate = plate;
        return;
    }
    public void setMaxWeight(double maxWeight) {
        this.maxWeight = maxWeight;
        return;
    }
    public void setPcs(List<Integer> pcs) {
        this.pcs = pcs;
        return;
    }

    public void addPc(int pc) {
        if(pc <= 0) return;

        this.pcs.add(pc);
        return;
    }

    public void addAddress(Address address) {
        this.addresses.add(address);
        return;
    }
    
}
