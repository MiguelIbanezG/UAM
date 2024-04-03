import java.util.TreeSet;

/**
 * Esta clase calcula los divisores propios de un número entero
 * 
 * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
 *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
 * 
 */
public class Divisores {
    private int num; // para almacenar el número
    // usamos un conjunto que mantiene los divisores de num ordenados
    private TreeSet<Integer> divisores = new TreeSet<Integer>();

    /**
     * Constructor, con el número
     * 
     * @param n número del que se quieren calcular los divisores propios
     */
    public Divisores(int n) {
        this.num = n;
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                this.divisores.add(i);
    }

    /**
     * @return el conjunto de divisores
     */
    public TreeSet<Integer> getDivisores() {
        return this.divisores;
    }

    /**
     * @return el número
     */
    public int getNumero() {
        return this.num;
    }

    /**
     *
     * @return Cadena que representa este objeto
     */
    public String toString() {
        return "Los divisores propios de " + this.num + " son: " + this.divisores;
    }

    /**
     * 
     * @return true si el número es perfecto, false si no
     * 
     */
    public boolean esPerfecto() {
        int j = 0;

        /* Se crea una array en la que se introducen todos los divisores */
        Object a[] = this.divisores.toArray();

        for (int i = 0; i < this.getDivisores().size(); i++) {

            /* Se suman todos los divisores de la array */
            j += (int) a[i];

        }

        /* Si la suma es igual al número, es perfecto */
        if (this.getNumero() == j) {
            return true;

        }

        return false;
    }

    /**
     * 
     * @return true si dos números son amigos, false si no
     * 
     */
    public boolean esAmigo(Divisores div2) {
        int j = 0, k = 0;

        /* Se crea una array en la que se introducen todos los divisores */
        Object a[] = div2.divisores.toArray();

        /* Se suman todos los divisores de la array */
        for (int i = 0; i < div2.getDivisores().size(); i++) {

            j += (int) a[i];

        }

        /* Se repite para el otro número */
        Object b[] = this.divisores.toArray();

        for (int i = 0; i < this.getDivisores().size(); i++) {

            k += (int) b[i];
        }

        /*
         * Si la suma de los divisores del primer número son iguales
         * al segundo número y viceversa, son amigos
         */
        if ((this.getNumero() == j) && (div2.getNumero() == k)) {
            return true;

        }

        return false;
    }

    /**
     * Punto de entrada a la aplicación.
     *
     * Este método imprime los divisores de los números que se introducen por la
     * linea de comando
     * 
     * @param args Los argumentos de la línea de comando. Se esperan enteros, como
     *             cadenas
     */
    public static void main(String[] args) {
        if (args.length == 0)
            System.err.println("Se espera al menos un número como parámetro");
        else
            for (String num : args) {
                Divisores divis = new Divisores(Integer.valueOf(num));
                System.out.println(divis.getNumero() + " tiene " + divis.getDivisores().size() + " divisores propios");
                System.out.println(divis);
            }
    }
}