package prac2.club;

public class Padel extends Section {

    private boolean professional;

    /*constructor */
    public Padel(String c, int y, boolean professional, String a) {
        super(c, y);
        this.professional = professional;
    }

    @Override
    /*Getter del número de jugadores*/
    public int numberOfPlayers() {
        if (professional == true) {
            return 2;
        }

        return 1;
    }

    @Override
    /*Devuelve la informacion del Padel*/
    public String toString() {
        return "Padel " + (this.professional ? "pairs" : "individual") + ", " + super.toString();
    }

    @Override
    /*Override para que siempre aparezca como UNKNOWN*/
    public SectionCategory getCategory() {

        return SectionCategory.UNKNOWN;
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
