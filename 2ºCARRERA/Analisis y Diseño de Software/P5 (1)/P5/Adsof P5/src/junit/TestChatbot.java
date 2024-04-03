package junit;

import org.junit.jupiter.api.Test;

import chatbot.*;
import cafeteria.*;

import java.util.*;

class TestChatbot {

	@Test
	public void testerConstructor() {
		Chatbot<CoffeeOrder> chatbot = new Chatbot<CoffeeOrder>("Prueba");
		chatbot.withIntent(new Intent("Greetings",
				List.of(new StructuredPhrase().with("Hello"))).replies("Welcome to Java Cafe, how can I help you?"))
				.withFallback("Sorry, I did not understand that, but I may help you ordering coffee");
		chatbot.reactTo("Hello"); // it prints the reply ("Welcome to Java Cafe, how can I help you?")
		chatbot.reactTo("How are you?"); // it prints the fallback message("Sorry, I did not understand that, but I may
											// help you ordering coffee")

	}

}
