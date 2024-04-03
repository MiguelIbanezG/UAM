import java.io.File;
import java.util.List;
import java.util.ArrayList;


import javax.imageio.ImageIO;

public class Statistics {
    private File file;
    private ImageIO image;
    private List<Bill> bills;

    public Statistics(List<Bill> bills)
    {

    }

    public void addBill(Bill bill) {
        this.bills.add(bill);
        return;
    }

}