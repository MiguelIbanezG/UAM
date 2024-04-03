/**
 * Esta aplicación muestra el mensaje "Hola mundo!" por pantalla
 *
 * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
 *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
 * 
 */
public class HolaMundo {
    /**
     * Punto de entrada a la aplicación.
     * Este método imprime el mensaje "Hola mundo!"
     *
     * @param args Los argumentos de la línea de comando
     */
    public static void main(String[] args) {
        int numero = 0;
        int i = 0;
        while(i<9){
            i=i+1;
        }
        numero = numero+i;
        System.out.println(numero); // muestra el string por stdout
    }
}