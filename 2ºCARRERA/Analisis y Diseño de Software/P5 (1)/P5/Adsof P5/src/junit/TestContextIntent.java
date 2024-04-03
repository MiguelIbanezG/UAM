package junit;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

import cafeteria.CoffeeOrder;
import chatbot.*;
import java.util.*;
import cafeteria.*;

public class TestContextIntent {

    @Test
    public void testerConstructor() {
        List<StructuredPhrase> phrases = new ArrayList<StructuredPhrase>();
        phrases.add(new StructuredPhrase().with("I'd like a").with("coffee-type", CoffeeType.CAPUCCINO)
                .setting("coffee-number", 1));
        phrases.add(new StructuredPhrase().with("I'd like a coffee").setting("coffee-number", 1)
                .setting("coffee-type", CoffeeType.ESPRESSO));
        phrases.add(new StructuredPhrase().with("Can I have").with("coffee-number", 2)
                .with("coffee-type", CoffeeType.ESPRESSO)
                .with("please?"));

        ContextIntent<CoffeeOrder> contextIntent = new ContextIntent<CoffeeOrder>("Coffee Order", phrases)
                .withParameter("coffee-number",
                        s -> s.matches("\\d+"),
                        s -> Integer.valueOf(s))
                .withParameter("coffee-type",
                        s -> IntentHelper.containsIgnoreCase(s, CoffeeType.values()),
                        s -> CoffeeType.valueOf(s.toUpperCase()))
                .resultObject(c -> new CoffeeOrder(c.<Integer>getParam("coffee-number"),
                        c.<CoffeeType>getParam("coffee-type")))
                .replies("All right, you ordered #coffee-number# #coffee-type#");

        assertEquals(true, contextIntent.matches("I'd like a capuccino"));
        assertEquals(true, contextIntent.matches("I'd like a coffee"));
        assertEquals(true, contextIntent.matches("Can I have 1 espresso please?"));
        assertEquals(true, contextIntent.matches("Can I have 2 espresso please?"));

    }

    @Test
    public void testerProcess() {
        List<StructuredPhrase> phrases = new ArrayList<StructuredPhrase>();
        phrases.add(new StructuredPhrase().with("I'd like a").with("coffee-type", CoffeeType.CAPUCCINO)
                .setting("coffee-number", 1));
        phrases.add(new StructuredPhrase().with("I'd like a coffee").setting("coffee-number", 1)
                .setting("coffee-type", CoffeeType.ESPRESSO));
        phrases.add(new StructuredPhrase().with("Can I have").with("coffee-number", 2)
                .with("coffee-type", CoffeeType.ESPRESSO)
                .with("please?"));

        ContextIntent<CoffeeOrder> contextIntent = new ContextIntent<CoffeeOrder>("Coffee Order", phrases)
                .withParameter("coffee-number",
                        s -> s.matches("\\d+"),
                        s -> Integer.valueOf(s))
                .withParameter("coffee-type",
                        s -> IntentHelper.containsIgnoreCase(s, CoffeeType.values()),
                        s -> CoffeeType.valueOf(s.toUpperCase()))
                .resultObject(c -> new CoffeeOrder(c.<Integer>getParam("coffee-number"),
                        c.<CoffeeType>getParam("coffee-type")))
                .replies("All right, you ordered #coffee-number# #coffee-type#");

        assertEquals("All right, you ordered 1 CAPUCCINO ", contextIntent.process("I'd like a capuccino").getReply());
        assertTrue(1 == (int) contextIntent.getParam("coffee-number"));
        assertEquals(CoffeeType.CAPUCCINO, contextIntent.getParam("coffee-type"));

        assertEquals("All right, you ordered 1 ESPRESSO ", contextIntent.process("I'd like a coffee").getReply());
        assertTrue(1 == (int) contextIntent.getParam("coffee-number"));
        assertEquals(CoffeeType.ESPRESSO, contextIntent.getParam("coffee-type"));

    }
}
