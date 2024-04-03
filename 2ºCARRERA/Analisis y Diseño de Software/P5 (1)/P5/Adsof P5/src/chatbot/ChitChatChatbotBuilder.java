package chatbot;

import java.util.*;
import cafeteria.*;

public class ChitChatChatbotBuilder<C> extends ChatbotBuilder<C> {

    public ChitChatChatbotBuilder(String name) {
        super(name);

        List<Intent> intents = new ArrayList<Intent>();

        intents.add(new Intent("Greetings", List.of(new StructuredPhrase().with("Hello")))
                .replies("Welcome to Java Cafe, how can I help you?"));

        intents.add(new Intent("Check", List.of(new StructuredPhrase().with("How are you?")))
                .replies("I'm good, what can I do for you today?"));

        intents.add(new Intent("Check", List.of(new StructuredPhrase().with("Bye bye!")))
                .replies("Thank you, please call again!"));

        for (Intent i : intents) {
            super.withIntent(i);
        }
    }

}
