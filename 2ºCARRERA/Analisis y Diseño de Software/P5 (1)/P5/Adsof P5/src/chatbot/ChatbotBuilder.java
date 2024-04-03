package chatbot;

public class ChatbotBuilder<C> {
    private Chatbot<C> chatbot;

    public ChatbotBuilder(String name) {
        chatbot = new Chatbot<C>(name);
    }

    public ChatbotBuilder<C> withIntent(Intent intent) {
        chatbot.withIntent(intent);
        return this;
    }

    public ChatbotBuilder<C> withFallback(String fallback) {
        chatbot.withFallback(fallback);
        return this;
    }

    public Chatbot<C> build() {
        return chatbot;
    }

}
