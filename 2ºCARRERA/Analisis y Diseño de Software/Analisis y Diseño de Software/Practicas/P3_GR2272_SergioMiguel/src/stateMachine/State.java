package stateMachine;

import java.util.List;

import java.util.ArrayList;

public class State {

    private String name;
    protected List<Transition> transitions;
    private String descr;
    private boolean initial;

    /* Constructores para cada caso de inicialización del estado */
    protected State() {
        this.name = "State";
        this.initial = false;
    }

    protected State(String name) {
        this.name = name;
        this.transitions = new ArrayList<Transition>();
        this.initial = false;
        this.descr = "";

    }

    protected State(String name, String descr) {
        this.name = name;
        this.descr = ": " + descr;
        this.transitions = new ArrayList<Transition>();
        this.initial = false;
    }

    /* getter del nombre */
    public String getName() {

        return this.name;
    }

    /* getter de la descripción */
    public String getDescr() {

        return this.descr;
    }

    /* seter de la descripción */
    public void setDescr(String dscr) {

        this.descr = dscr;
    }

    /* getter del inicial */
    public boolean getStateInitial() {

        return this.initial;
    }

    /* seter de la descripción */
    public void setStateInitial(boolean b) {

        this.initial = b;
    }

    public List<Transition> getListTransitions() {
        return this.transitions;
    }

    /* función para pasar a cadena */
    public String toString() {

        if (this.getDescr() == null) {
            return this.getName();
        }

        return this.getName() + this.getDescr();
    }

    /* función para crear una transición de evento */
    protected void addTransition(Transition t) {

        this.transitions.add(t);
        ;

    }

    protected State getStateNext() {
        return null;
    }

    /* getter de las transiciones */
    public String getTransitions() {
        String s = new String();

        s = "[";

        for (Transition trans : this.transitions) {

            s = s + trans.toString() + trans.getNextState().getName();
            s = s + ", ";
        }
        s = s.substring(0, s.length() - 2) + "]";

        return s;
    }

    protected void addEvents(String... event) {
    }

    protected List<State> getStates() {

        return null;
    }
}
