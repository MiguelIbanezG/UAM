package cafeteria;

public class CoffeeOrder {
    private int num;
    private CoffeeType ct;

    public CoffeeOrder(int num, CoffeeType ct) {
        this.num = num;
        this.ct = ct;
    }

    @Override
    public String toString() {
        return "CoffeeOrder[" + num + ", " + this.ct + "]";
    }
}