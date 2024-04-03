package Tokens;


public class WallToken implements IToken {

    /**
     *
     * Este método inicializa una ficha muralla
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public WallToken() {
    }

    public boolean canBeOverwritten() {
        return false;
    }

    public String toString() {
        String s = "WA";
        return s;
    }

}
