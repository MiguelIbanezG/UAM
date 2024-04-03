package SortedList;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;

public class SortedList<T extends Comparable<T>> extends ArrayList<T> {

    private Comparator<T> c;

    /**
     * Creates a sorted list
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public SortedList() {
        super();
        this.c = Comparator.naturalOrder();
    }

    /**
     * Creates a sorted list based on a collection
     * 
     * @param collec
     */
    public SortedList(Collection<T> collec) {
        super(collec);
        this.c = Comparator.naturalOrder();
        this.sort(c);
    }

    /**
     * Adds a new criterion to order the list
     * 
     * @param cToAdd comparator to add to the criterions
     */
    public void addCriterion(Comparator<T> cToAdd) {
        this.c = this.c.thenComparing(cToAdd);
        this.sort(c);
    }

}
