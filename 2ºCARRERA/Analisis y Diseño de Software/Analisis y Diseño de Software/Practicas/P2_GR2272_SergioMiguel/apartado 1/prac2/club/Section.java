package prac2.club;

public abstract class Section {
    private String code;
    private int yearFederate;

    public Section(String cod, int y) {
        this.code = cod;
        this.yearFederate = y;
    }

    @Override
    public String toString() {
        return "code " + this.code + ", year of federation " + this.yearFederate + ", with " +
                this.numberOfPlayers() + " player(s) by team, category: " + this.getCategory();
    }

    public abstract int numberOfPlayers();

    public SectionCategory getCategory() {
        return SectionCategory.getCategory(this.yearFederate);
    }

}
