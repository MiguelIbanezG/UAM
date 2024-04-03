package cafeteria;

import java.util.*;

public class IntentHelper { // clase de utilidad para la definición de Intents
    public static boolean containsIgnoreCase(String s, Object[] values) {
        return List.of(values).stream().anyMatch(e -> s.toUpperCase().equals(e.toString()));
    }
}
