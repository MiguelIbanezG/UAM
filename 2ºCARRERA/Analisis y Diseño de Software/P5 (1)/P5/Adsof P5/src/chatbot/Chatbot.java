package chatbot;

import java.util.*;

public class Chatbot<C> {
    private String name;
    private List<Intent> intents;
    private String fallback;
    private C object;

    public Chatbot(String name) {
        this.name = name;
        this.intents = new ArrayList<Intent>();
        this.fallback = "";
    }

    public Chatbot<C> withIntent(Intent intent) {
        this.intents.add(intent);
        return this;
    }

    public Chatbot<C> withFallback(String fallback) {
        this.fallback = fallback;
        return this;
    }

    @SuppressWarnings("unchecked")
    public Chatbot<C> reactTo(String s) {
        System.out.println("User> " + s);
        for (Intent i : this.intents) {
            if (i.matches(s)) {

                if (i.hasObject()) {
                    i.process(s);
                    ContextIntent<C> ci = (ContextIntent<C>) i;
                    this.object = ci.getObject();
                }

                System.out.println(this.name + "> " + i.getReply());
                return this;
            }
        }
        System.out.println(this.name + "> " + this.fallback);
        return this;
    }

    public C getObject() {
        return this.object;
    }

    public String toString() {
        return this.name;
    }

}
