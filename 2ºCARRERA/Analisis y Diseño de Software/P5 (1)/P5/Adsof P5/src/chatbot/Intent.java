package chatbot;

import cafeteria.*;
import java.util.*;

public class Intent {
    private String name;
    private List<StructuredPhrase> phrases;
    private String answer;

    public Intent(String name, List<StructuredPhrase> phrases) {
        this.name = name;
        this.phrases = phrases;
        this.answer = "";
    }

    public Intent replies(String s) {
        this.answer = s;
        return this;
    }

    public boolean matches(String s) {
        for (StructuredPhrase p : this.phrases) {
            if (p.toString().equals(s)) {
                return true;
            }
        }
        return false;
    }

    public Intent process(String s) {
        return this;
    }

    public String toString() {
        return this.name;
    }

    public String getReply() {
        return this.answer;
    }

    public List<StructuredPhrase> getPhrases() {
        return this.phrases;
    }

    public Boolean hasObject() {
        return false;
    }
}
