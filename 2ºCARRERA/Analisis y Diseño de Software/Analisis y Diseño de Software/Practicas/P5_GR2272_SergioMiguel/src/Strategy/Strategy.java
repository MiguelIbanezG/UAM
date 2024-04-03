package Strategy;

public interface Strategy <T>{

    /**
     * Function that will do the strategy
     * @param s string that we want to transform
     * @param obj object that we are using
     * @return the string transformed
     */
    public String functStrategy(String s, T obj);
}
