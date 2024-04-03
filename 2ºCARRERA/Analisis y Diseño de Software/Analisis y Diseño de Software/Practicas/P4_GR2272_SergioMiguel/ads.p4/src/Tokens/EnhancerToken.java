package Tokens;

public class EnhancerToken implements IToken {

    /**
     *
     * Este método inicializa una ficha potenciadora
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public EnhancerToken() {
    }

    public boolean canBeOverwritten() {
        return true;
    }

    public String toString() {
        String s = "EN";
        return s;
    }
}
