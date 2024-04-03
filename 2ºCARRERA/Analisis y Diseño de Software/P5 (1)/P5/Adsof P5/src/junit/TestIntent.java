package junit;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import chatbot.*;
import cafeteria.*;
import java.util.*;

public class TestIntent {

    @Test
    public void testerConstructor() {
        Intent greeting = new Intent("Greeteing intent", List.of(new StructuredPhrase().with("Hello")));
        assertEquals("Greeteing intent", greeting.toString());
        assertEquals(true, greeting.matches("Hello"));
        assertEquals(false, greeting.matches("Hi"));
    }

    @Test
    public void testerReplies() {
        Intent greeting = new Intent("Greeteing intent", List.of(new StructuredPhrase().with("Hello")));
        greeting.replies("Welcome to Java Cafe, how can I help you?");
        assertEquals("Welcome to Java Cafe, how can I help you?", greeting.getReply());
    }

    @Test
    public void hasObject() {
        Intent greeting = new Intent("Greeteing intent", List.of(new StructuredPhrase().with("Hello")));
        assertEquals(false, greeting.hasObject());
    }

}
