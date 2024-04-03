package Strategy;

import java.time.LocalDate;

public class TimeStamper<T> implements Strategy<T> {

    /**
     * Creates a time stamper
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public TimeStamper() {

    }



    /**
     * Implementation of the interface, places the actual date on the message
     */
    public String functStrategy(String s, T obj) {
        String aux = new String("");

        aux = LocalDate.now() + "\n";
        aux = aux + s;

        return aux;
    }

}
