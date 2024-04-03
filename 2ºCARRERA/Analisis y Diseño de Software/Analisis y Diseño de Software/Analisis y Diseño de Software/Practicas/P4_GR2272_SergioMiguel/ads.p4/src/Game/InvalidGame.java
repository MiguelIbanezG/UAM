package Game;

public class InvalidGame extends Exception {

      /**
     *
     * Este método crea una excepción que se lanzará cuando el juego sea inválido
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public InvalidGame(String errorMessage) {
        super(errorMessage);
    }

    @Override
    public String toString() {
        return "Error: " + this.getMessage();
    }
}
