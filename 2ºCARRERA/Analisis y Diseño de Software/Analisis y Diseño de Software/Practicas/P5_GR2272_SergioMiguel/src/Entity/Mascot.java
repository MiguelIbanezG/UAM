package Entity;

public class Mascot implements Comparable<Mascot> {
    private String name;
    private String type;

    /**
     * Function that creates a mascot
     * 
     * @param name
     * @param type
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public Mascot(String type, String name) {
        this.name = name;
        this.type = type;
    }

    /**
     * 
     * @return the name
     */
    public String getMascotName() {
        return name;
    }

    /**
     * 
     * @return the type
     */
    public String getMascotType() {
        return type;
    }

    /**
     * 
     * @param m mascot to compare
     * @return comparation between the 2 mascots
     */
    @Override
    public int compareTo(Mascot m) {
        return this.name.compareTo(m.name);
    }
}
