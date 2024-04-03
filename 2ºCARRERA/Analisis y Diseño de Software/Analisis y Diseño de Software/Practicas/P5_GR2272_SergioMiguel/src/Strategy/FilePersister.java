package Strategy;

import java.util.function.Function;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.File;

public class FilePersister<T> implements Strategy<T> {

    private Function<? super T, ? extends Object> o;

    /**
     * Creates a file persister
     * 
     * @param o the function that its used to identify the object
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public FilePersister(Function<? super T, ? extends Object> o) {
        this.o = o;
    }

    /**
     * Implementation of the interface, creates and writes the new file
     */
    public String functStrategy(String s, T obj) {

        FileWriter fw;
        BufferedWriter bw;

        try {
            /* Creates a file */
            int i = 0;
            File f = new File("../txt/" + this.o.apply(obj).toString() + i + ".txt");

            /*
             * While it exists, it will be trying with the next number (filename1, filename2
             * ...)
             */
            while (f.exists()) {
                f = new File("../txt/" + this.o.apply(obj).toString() + i + ".txt");
                i++;
            }

            fw = new FileWriter(f.getAbsolutePath());

            bw = new BufferedWriter(fw);
            bw.write(s);
            bw.close();
            fw.close();
        } catch (IOException ioe) {
            System.out.println(ioe);
        }

        return s;

    }

}
