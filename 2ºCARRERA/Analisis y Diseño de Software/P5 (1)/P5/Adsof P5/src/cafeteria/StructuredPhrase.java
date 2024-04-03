package cafeteria;

import java.util.*;

public class StructuredPhrase {

    private String phrase;
    private Map<String, Object> parameters;

    public StructuredPhrase() {
        this.phrase = "";
        this.parameters = new HashMap<String, Object>();
    }

    public StructuredPhrase with(String s) {
        this.phrase += s + " ";
        return this;
    }

    public StructuredPhrase with(String s, Object o) {
        this.phrase += "#" + s + "# ";
        this.parameters.put(s, o);
        return this;
    }

    public StructuredPhrase setting(String s, Object o) {
        this.parameters.put(s, o);
        return this;
    }

    public Object getValue(String s) {
        return this.parameters.get(s);
    }

    public String getPhrase() {
        return this.phrase;
    }

    public String toString() {
        String parts[] = this.phrase.split(" ");
        String result = "";

        int i = 0;
        for (String s : parts) {
            if (i < parts.length - 1) {
                result += s + " ";
            } else {
                result += s;
            }
            i++;
        }

        for (String s : this.parameters.keySet()) {
            result = result.replace("#" + s + "#", "[" + s + ":" + this.parameters.get(s).getClass().getSimpleName()
                    + "(" + this.parameters.get(s) + ")]");
        }

        return result;
    }

}
