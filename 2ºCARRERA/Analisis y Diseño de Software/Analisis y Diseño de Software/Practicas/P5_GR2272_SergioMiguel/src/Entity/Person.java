package Entity;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Person implements Comparable<Person> {
    private LocalDate birthDate;
    private String name;
    private List<Mascot> mascots;

    /**
     * Creates a person
     * 
     * @param name
     * @param birthDate
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public Person(String name, LocalDate birthDate) {
        this.name = name;
        this.birthDate = birthDate;
        this.mascots = new ArrayList<>();
    }

    /**
     * 
     * @return the compare of 2 persons
     */
    @Override
    public int compareTo(Person p2) {
        return this.name.compareTo(p2.name);
    }

    /**
     * 
     * @return Birth date
     */
    public LocalDate getBirthDate() {
        return this.birthDate;
    }

    /**
     * 
     * @return Person string
     */
    @Override
    public String toString() {
        return this.name + " " + this.birthDate;
    }

    /**
     * 
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * 
     * @return age
     */
    public int getAge() {
        LocalDate n = LocalDate.now();

        /* If it doesnt exist yet (born after actual date) returns error (-1) */
        if (n.getYear() < this.birthDate.getYear()) {
            return -1;
        }

        /* If the day of the actual year its greater, only returns the difference */
        if (n.getDayOfYear() > this.birthDate.getDayOfYear()) {

            return n.getYear() - this.birthDate.getYear();
        }

        /* If not, one year less of diference (his birthday didnt happen yet) */
        return n.getYear() - this.birthDate.getYear() - 1;
    }

    /**
     * Function that adds mascots to the array
     * 
     * @param m a collection of mascots
     */
    public void addMascots(Mascot... m) {
        for (Mascot mascot : m) {

            this.mascots.add(mascot);
        }
    }

    /**
     * 
     * @return the mascots
     */
    public List<Mascot> getMascots() {
        return mascots;
    }
}
