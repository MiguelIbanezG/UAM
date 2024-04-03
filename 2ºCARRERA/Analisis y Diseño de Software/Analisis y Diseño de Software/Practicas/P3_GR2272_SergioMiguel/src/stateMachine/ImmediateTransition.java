package stateMachine;

public class ImmediateTransition extends Transition {

    private Color col;

    public ImmediateTransition(State state2, Color col)
    {
        super(state2);
        this.col = col;
    }


    public Color getColor()
    {
        return this.col;
    }


    @Override
    public String toString() {   
        return "---->";
    }
    
}
