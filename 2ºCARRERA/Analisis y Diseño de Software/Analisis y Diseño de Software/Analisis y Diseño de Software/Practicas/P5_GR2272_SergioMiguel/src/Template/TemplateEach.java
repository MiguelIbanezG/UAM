package Template;

import java.util.List;
import java.util.function.Function;

public class TemplateEach<T extends Comparable<T>, E extends Comparable<E>> extends TemplateUnit<T> {

    Function<? super T, List<? extends E>> funct;
    TemplateUnit<E> tmp;

    /**
     * Creates a template for each subclass (is like a sub template unit)
     * 
     * @param o function
     * @param s string
     * 
     * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
     *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
     */
    public TemplateEach(Function<? super T, List<? extends E>> o, String s) {
        super(s);
        this.funct = o;

    }

    /**
     * Creates a template for each subclass
     * 
     * @param o  function that subtracts the subobject
     * @param s  string with the message
     * @param o2 collection of functions
     */
    @SafeVarargs
    public TemplateEach(Function<? super T, List<? extends E>> o,
            String s, Function<? super E, ? extends Object>... o2) {
        super(s);
        this.funct = o;
        this.tmp = new TemplateUnit<E>(s, o2);
    }

    /**
     * Function that applies the template (it extracts the objects, then it calls
     * the
     * unit function)
     * 
     * @param obj
     * @return
     */
    @Override
    public String applyTemplate(T obj) {

        List<? extends E> objs = this.funct.apply(obj);

        String msg = "";

        for (E o : objs) {
            msg += this.tmp.applyTemplate(o);
        }

        return msg;
    }
}
