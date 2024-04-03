package junit;

import cafeteria.*;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class TestSturcturePhrase {

    @Test
    public void testConstructor() {
        StructuredPhrase sp = new StructuredPhrase();
        assertEquals("", sp.getPhrase());
        sp.with("I want a");
        assertEquals("I want a ", sp.getPhrase());
    }

    @Test
    public void testWith() {
        StructuredPhrase sp = new StructuredPhrase();
        sp.with("I want a").with("coffee-type", CoffeeType.CAPUCCINO).setting("coffee-number", 2);
        assertEquals("I want a #coffee-type# ", sp.getPhrase());
        assertEquals(CoffeeType.CAPUCCINO, sp.getValue("coffee-type"));
        assertEquals(2, sp.getValue("coffee-number"));
    }

    @Test
    public void testToString() {
        StructuredPhrase sp = new StructuredPhrase();
        sp.with("I want a").with("coffee-type", CoffeeType.CAPUCCINO).setting("coffee-number", 1);
        assertEquals("I want a [coffee-type:CoffeeType(CAPUCCINO)]", sp.toString());
    }

}