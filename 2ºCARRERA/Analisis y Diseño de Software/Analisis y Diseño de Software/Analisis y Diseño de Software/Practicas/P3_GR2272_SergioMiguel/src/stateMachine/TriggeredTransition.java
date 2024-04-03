package stateMachine;

public class TriggeredTransition extends Transition {

    private String event;

    public TriggeredTransition(State state2, String event)
    {
        super(state2);
        this.event = event;
    }

    @Override
    public String getEvent(){
        return this.event;
    }

    @Override
    public String toString() {   
        return "--" + this.event + "-->";
    }
}
