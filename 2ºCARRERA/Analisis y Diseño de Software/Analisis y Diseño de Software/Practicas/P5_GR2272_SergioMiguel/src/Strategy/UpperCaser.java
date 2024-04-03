package Strategy;

public class UpperCaser<T> implements Strategy<T> {

    /**
     * Creates a upper case
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public UpperCaser() {

    }

    /**
     * Implementation of the interface, returns the string on upper case
     */
    public String functStrategy(String s, T obj) {

        String aux = new String("");

        aux = s.toUpperCase();

        return aux;
    }

}
