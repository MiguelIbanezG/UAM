package prac2.club;

public class Soccer extends Section {
    private boolean professional;

    public Soccer(String c, int y, boolean professional) {
        super(c, y);
        this.professional = professional;
    }

    @Override
    public int numberOfPlayers() {
        return 11;
    }

    @Override
    public String toString() {
        return "Soccer " + (this.professional ? "professional" : "amateur") + ", " + super.toString();
    }

    public boolean getProfessional() {
        return this.professional;
    }

    public void setProfessional(boolean p) {
        this.professional = p;
    }
}
