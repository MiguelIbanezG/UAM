public class Amigos {
    /**
     * 
     * Punto de entrada a la aplicación.
     *
     * Este método llama a la función imprime amistad
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     * Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     * 
     * @param args Los argumentos de la línea de comando. Se esperan enteros, como
     *             cadenas
     */
    public static void main(String[] args) {
        if (args.length != 2)
            System.err.println("Se esperan dos números como parámetros");
        else {
            /* Se sacan los divisores de ambos */
            Divisores div1 = new Divisores(Integer.valueOf(args[0])),
                    div2 = new Divisores(Integer.valueOf(args[1]));

            imprimeAmistad(div1, div2);
        }
    }

    /**
     *
     * Este método imprime los divisores de ambos números y si son amigos
     * y/o perfectos
     * 
     * @param args Los argumentos de la línea de comando. Se esperan enteros, como
     *             cadenas
     */
    private static void imprimeAmistad(Divisores div1, Divisores div2) {

        System.out.println(div1);
        System.out.println(div2);
        if (div1.esPerfecto())
            System.out.println(div1.getNumero() + " es un número perfecto");
        if (div2.esPerfecto())
            System.out.println(div2.getNumero() + " es un número perfecto");
        if (div1.esAmigo(div2))
            System.out.println(div1.getNumero() + " y " + div2.getNumero() + " son amigos");
        else
            System.out.println(div1.getNumero() + " y " + div2.getNumero() + " no son amigos");
    }
}
