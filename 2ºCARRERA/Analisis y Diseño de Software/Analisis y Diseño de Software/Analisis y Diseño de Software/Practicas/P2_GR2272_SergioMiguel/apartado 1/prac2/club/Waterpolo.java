package prac2.club;

public class Waterpolo extends Section {

    private boolean professional;

    /*constructor */
    public Waterpolo(String c, int y, boolean professional, String a) {
        super(c, y);
        this.professional = professional;
    }

    @Override
    /*Getter del número de jugadores*/
    public int numberOfPlayers() {

        return 6;
    }

    @Override
    /*Devuelve la informacion del Waterpolo*/
    public String toString() {

        return "Waterpolo " + (this.professional ? "national" : "regional") + ", " + super.toString();
    }

    @Override
    /*Override para que siempre aparezca como NEW */
    public SectionCategory getCategory() {

        return SectionCategory.NEW;
    }

    /*Getter*/
    public boolean getProfessional() {
        return this.professional;
    }

    /*Setter*/
    public void setProfessional(boolean p) {
        this.professional = p;
    }

}
