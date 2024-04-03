package Template;

import java.util.ArrayList;
import java.util.List;
import java.util.function.*;

public class TemplateUnit<T extends Comparable<T>> {

    private String o;
    private List<Function<? super T, ? extends Object>> functions = new ArrayList<>();
    private List<Predicate<T>> functions2 = new ArrayList<>();

    /**
     * Creates a template unit (1 string)
     * 
     * @param o        string of the template
     * @param function collection of functions
     */
    @SafeVarargs
    public TemplateUnit(String o, Function<? super T, ? extends Object>... function) {

        this.o = o;

        for (Function<? super T, ? extends Object> functioni : function) {
            this.functions.add(functioni);
        }
    }

    /**
     * Creates a template unit (no functions)
     * 
     * @param o string of the template
     */
    public TemplateUnit(String o) {

        this.o = o;

    }

    /**
     * Creates a template unit with a predicate function
     * 
     * @param o
     * @param function
     */
    public TemplateUnit(String o, Predicate<T> function) {

        this.o = o;

        this.functions2.add(function);
    }

    /**
     * Gets the functions
     * 
     * @return the functions
     */
    public List<Function<? super T, ? extends Object>> getFunctions() {
        return functions;
    }

    /**
     * Apply the lambda expressions and changes the characters '##'
     * for the correct object string
     * 
     * @param obj object to be applied the function from the lambda expression
     * @return the message
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public String applyTemplate(T obj) {

        String s = new String("");
        
        for (int j = 0; j < this.functions.size(); j++) {
            
            int i = 0;
            
            while (i < this.o.length()) {

                if (this.o.charAt(i) == '#') {
                    if (j < this.functions.size()) {
                        s = s + this.functions.get(j).apply(obj).toString();
                        i++;
                        i++;
                        j++;
                    }
                }

                s = s + this.o.charAt(i);
                i++;

            }

        }
        for (int j = 0; j < this.functions2.size(); j++) {
            int i = 0;

            if (this.functions2.get(i).test(obj)) {

                while (i < this.o.length()) {

                    if (this.o.charAt(i) == '#') {
                        if (j < this.functions.size()) {
                            s = s + this.functions.get(j).apply(obj).toString();
                            i++;
                            i++;
                            j++;
                        }
                    }

                    s = s + this.o.charAt(i);
                    i++;

                }
            }

        }
        s = s + "\n";

        return s;
    }

}
