package Tokens;


public class ForbiddenToken extends Exception {

    /**
     *
     * Este método inicializa una excepcion de ficha
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public ForbiddenToken(String errorMessage) {
        super(errorMessage);
    }

    @Override
    public String toString() {
        return "Error: " + this.getMessage();
    }
}
