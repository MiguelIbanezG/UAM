package Game;

import java.io.*;

public abstract class GameLoader {

    /**
     *
     * Este método inicializa el Game desde un archivo
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */

    public static Game load(String args) {
        Game g = null;
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;

        /* primero se abre el archivo con la informacion */
        try {
            archivo = new File("../data/" + args);
            fr = new FileReader(archivo);
            br = new BufferedReader(fr);

            /* Se comprueban los distintos parámetros */
            String aux = br.readLine();
            if (aux == null)
                return null;
            int size = Integer.parseInt(aux);

            aux = br.readLine();
            if (aux == null)
                return null;

            int turns = Integer.parseInt(aux);

            aux = br.readLine();
            if (aux == null)
                return null;
            int wallTokens = Integer.parseInt(aux);

            /* se inicializa el juego */
            g = new Game(turns, size, wallTokens);
        } catch (InvalidGame e) {

            System.out.println(e);
            return null;
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            /* Se cierra el archivo */
            try {
                if (null != fr) {
                    fr.close();
                }
            } catch (Exception e2) {
                System.out.println(e2);
            }

        }
        return g;
    }
}