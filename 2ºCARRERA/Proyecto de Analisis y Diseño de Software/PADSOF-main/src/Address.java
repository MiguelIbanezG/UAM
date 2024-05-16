

public class Address {
    private String city;
    private String street;
    private int pc;

    public Address(String city, String street, int pc) {
        this.city = city;
        this.street = street;
        this.pc = pc;
    }

    public String getCity() {
        return this.city;
    }
    public String getStreet() {
        return this.street;
    }
    public int getPc() {
        return this.pc;
    }
    public void setCity(String city) {
        this.city = city;
        return;
    }
    public void setStreet(String street) {
        this.street = street;
        return;
    }
    public void setPc(int pc) {
        this.pc = pc;
        return;
    }
}   