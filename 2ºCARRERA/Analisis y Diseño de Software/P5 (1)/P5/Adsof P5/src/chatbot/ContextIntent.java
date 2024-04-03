package chatbot;

import cafeteria.*;

import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

public class ContextIntent<C> extends Intent {
    private C object;
    private Function<ContextIntent<C>, C> function;
    private Map<String, Predicate<String>> predicates;
    private Map<String, Function<String, Object>> functions;
    private Map<String, Object> parameters;

    public ContextIntent(String name, List<StructuredPhrase> phrases) {
        super(name, phrases);
        this.predicates = new HashMap<String, Predicate<String>>();
        this.functions = new HashMap<String, Function<String, Object>>();
        this.parameters = new HashMap<String, Object>();
    }

    @SuppressWarnings("unchecked")
    public <T> T getParam(String name) {
        if (!parameters.containsKey(name)) {
            return null;
        }
        try {
            T t = (T) parameters.get(name);
            return t;
        } catch (Exception e) {
            return null;
        }
    }

    public ContextIntent<C> resultObject(Function<ContextIntent<C>, C> function) {
        this.function = function;
        return this;
    }

    public C getObject() {
        this.object = function.apply(this);
        return this.object;
    }

    /*
     * 
     * public String toString() {
     * return super.toString() + " " + this.coffeeOrder;
     * }
     */

    public ContextIntent<C> withParameter(String name, Predicate<String> predicate,
            Function<String, Object> function) {
        // add the predicate to the map
        this.predicates.put(name, predicate);

        // add the function to the map
        this.functions.put(name, function);

        return this;
    }

    @Override
    public ContextIntent<C> process(String s) {
        if (!this.matches(s)) {
            return this;
        }

        StructuredPhrase phrase = this.findPhrase(s);

        String words[] = s.split(" ");
        String phraseWords[] = phrase.getPhrase().split(" ");

        for (String phraseWord : phraseWords) {
            if (phraseWord.startsWith("#") && phraseWord.endsWith("#")) {
                // name of the parameter
                String parameterName = phraseWord.substring(1, phraseWord.length() - 1);

                // value of the parameter with the function
                Object parameterValue = this.functions.get(parameterName)
                        .apply(words[Arrays.asList(phraseWords).indexOf(phraseWord)]);

                this.parameters.put(parameterName, parameterValue);
            }
        }

        this.parameters.put("coffee-type", phrase.getValue("coffee-type"));
        this.parameters.put("coffee-number", phrase.getValue("coffee-number"));

        return this;
    }

    @Override
    public boolean matches(String s) {
        String words[] = s.split(" ");
        boolean flag = false;

        // for each phrase
        for (StructuredPhrase phrase : this.getPhrases()) {
            flag = true;
            String phraseWords[] = phrase.getPhrase().split(" ");

            // for each word in the phrase
            for (String phraseWord : phraseWords) {

                // if its a parameter
                if (phraseWord.startsWith("#") && phraseWord.endsWith("#")) {
                    // name of the parameter
                    String parameterName = phraseWord.substring(1, phraseWord.length() - 1);

                    // value of the parameter with the function
                    Object parameterValue = null;
                    try {
                        parameterValue = this.functions.get(parameterName)
                                .apply(words[Arrays.asList(phraseWords).indexOf(phraseWord)]);
                    } catch (Exception e) {
                        flag = false;
                        break;
                    }

                    if (!this.predicates.get(parameterName).test(parameterValue.toString())) {
                        // the frase does not match
                        flag = false;
                    }
                }
                // if its not a parameter
                else {
                    if (!phraseWord.equals(words[Arrays.asList(phraseWords).indexOf(phraseWord)])) {
                        // the frase does not match
                        flag = false;
                    }
                }

                if (!flag) {
                    break;
                }

                if (Arrays.asList(phraseWords).indexOf(phraseWord) == phraseWords.length - 1) {
                    return true;
                }
            }
        }

        return false;
    }

    public StructuredPhrase findPhrase(String s) {
        String words[] = s.split(" ");

        for (StructuredPhrase phrase : this.getPhrases()) {
            String phraseWords[] = phrase.getPhrase().split(" ");

            // for each word in the phrase
            for (String phraseWord : phraseWords) {

                // if its a parameter
                if (phraseWord.startsWith("#") && phraseWord.endsWith("#")) {
                    // name of the parameter
                    String parameterName = phraseWord.substring(1, phraseWord.length() - 1);

                    // value of the parameter with the function
                    Object parameterValue = null;
                    try {
                        parameterValue = this.functions.get(parameterName)
                                .apply(words[Arrays.asList(phraseWords).indexOf(phraseWord)]);
                    } catch (Exception e) {
                        break;
                    }

                    if (!this.predicates.get(parameterName).test(parameterValue.toString())) {
                        // the frase does not match
                        break;
                    }
                }
                // if its not a parameter
                else {
                    if (!phraseWord.equals(words[Arrays.asList(phraseWords).indexOf(phraseWord)])) {
                        // the frase does not match
                        break;
                    }
                }

                if (Arrays.asList(phraseWords).indexOf(phraseWord) == phraseWords.length - 1) {
                    return phrase;
                }
            }

        }
        return null;
    }

    @Override
    public ContextIntent<C> replies(String s) {
        super.replies(s);
        return this;
    }

    @Override
    public String getReply() {
        String words[] = super.getReply().split(" ");
        String reply = "";

        for (String word : words) {
            if (word.startsWith("#") && word.endsWith("#")) {
                String parameterName = word.substring(1, word.length() - 1);
                if (parameterName.equals("coffee-number")) {
                    reply += (this.parameters.get("coffee-number") + " ");
                }
                if (parameterName.equals("coffee-type")) {
                    reply += (this.parameters.get("coffee-type") + " ");
                }
            } else {
                reply += (word + " ");
            }
        }
        return reply;
    }

    @Override
    public Boolean hasObject() {
        return true;
    }

}
