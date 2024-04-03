package stateMachine;


public abstract class Transition {

    private State s2;

    protected Transition(State state2) {
        this.s2 = state2;
    }



    public State getNextState() {
        return this.s2;
    }

    public String getEvent(){
        return "";
    }


    public Color getColor()
    {
        return null;
    }


}
