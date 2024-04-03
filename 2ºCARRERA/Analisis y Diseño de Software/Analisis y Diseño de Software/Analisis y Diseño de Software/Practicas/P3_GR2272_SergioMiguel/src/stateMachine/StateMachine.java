package stateMachine;

import java.util.List;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class StateMachine extends State {

    private List<State> states;

    private List<String> events;

    private State next;

    /* Constructores para cada caso de inicialización de la máquina */
    public StateMachine(String name) {

        super(name);

        states = new ArrayList<State>();

        events = new ArrayList<String>();
    }

    public StateMachine() {

        super("StateMachine");

        states = new ArrayList<State>();
        events = new ArrayList<String>();
    }

    /* Métodos para crear el estado */
    public State createState(String name, String descr) {

        if (checkWord(name) == false) {
            State s = new State();

            return s;
        }
        State s = new State(name, descr);

        this.states.add(s);

        return s;
    }

    public State createState(String name) {

        if (checkWord(name) == false) {
            State s = new State();

            return s;
        }

        State s = new State(name);

        for (State st : this.states) {
            if (st.getName() == name) {
                return s;
            }
        }

        this.states.add(s);

        return s;
    }

    /* Métodos para comprobar si el nombre es correcto */
    protected boolean checkWord(String name) {

        for (int i = 0; i < name.length(); i++) {

            if (((int) name.charAt(i) >= 48 && (int) name.charAt(i) <= 57) || ((int) name.charAt(i) >= 65
                    && (int) name.charAt(i) <= 90) || ((int) name.charAt(i) >= 97 && (int) name.charAt(i) <= 122)) {

            } else {
                return false;
            }
        }

        for (String str : this.events) {
            if (str.equals(name)) {
                return false;
            }
        }

        return true;
    }

    /* función para pasar a cadena */
    @Override
    public String toString() {

        String s = new String();

        s = this.getName() + " with states:\n[";

        for (State st : this.states) {
            s = s + "State[" + st.toString() + "]";
            s = s + ", ";
        }
        s = s.substring(0, s.length() - 2) + "]";

        return s;
    }

    /* getter de la lista de estados */
    public List<State> states() {

        return Collections.unmodifiableList(this.states);
    }

    @Override
    /* getter de la lista de estados */
    protected List<State> getStates() {

        return this.states;
    }

    public List<String> events() {

        return Collections.unmodifiableList(this.events);
    }

    /* Método para añadir eventos a la máquina de estados */
    public void addEvents(String... event) {

        for (int i = 0; i < event.length; i++) {
            if (checkWord(event[i]) == false) {
                return;
            }

            this.events.add(event[i]);

        }

    }

    /*
     * Métodos para conectar dos estados ya sea mediante un evento o de forma
     * inmediata
     */
    public boolean connect(String st1, String st2, String nameEvent) {

        /* Comprobará primero si el nombre es valido */
        if (checkEvent(nameEvent) == false) {
            return false;
        }

        int istate2 = 0;
        /* Después se busca cual es el estado al que se va a pasar */
        for (State state2 : this.states) {
            if (state2.getName() == st2) {
                istate2 = this.states.indexOf(state2);

                break;
            }
        }

        for (State st : this.states) {
            if (st.getName() == st1) {
                /*
                 * Aquí se busca en que estado se está
                 */
                if (this.states.indexOf(st) > istate2 && istate2 == 0
                        && this.states.indexOf(st) != this.states.size() - 1) {
                    return false;
                }

                /*
                 * Se llama a la función de transición con los parámetros de los índices
                 * obtenidos anteriormente
                 */
                /* Y se modifica el estado en el que se está el bucle */
                TriggeredTransition trans = new TriggeredTransition(this.states.get(istate2), nameEvent);
                this.states.get(this.states.indexOf(st)).addTransition(trans);

                if (this.states.get(this.states.indexOf(st)).getStates() != null) {

                    for (State state : this.states.get(this.states.indexOf(st)).getStates()) {
                        state.addTransition(trans);
                    }
                }
            }
        }

        return true;
    }

    /*
     * Este método sigue los mismos pasos que el anterior pero más simple pues no
     * hay que encontrar el evento
     */
    public boolean connect(String st1, String st2, Color c) {

        int ist2 = 0;
        for (State state2 : this.states) {
            if (state2.getName() == st2) {
                ist2 = this.states.indexOf(state2);
                break;
            }
        }

        for (State st : states) {
            if (st.getName() == st1) {

                ImmediateTransition trans = new ImmediateTransition(this.states.get(ist2), c);

                this.states.get(this.states.indexOf(st)).addTransition(trans);

            }
        }

        return true;
    }

    public void setInitial(String nameInitial) {
        for (State st : this.states) {

            if (st.getName() == nameInitial) {
                st.setStateInitial(true);
                this.setStateNext(st);
            }
        }

    }

    public State getInitial(String nameInitial) {

        return this.getStateNext();
    }

    protected void setStateNext(State st) {
        this.next = st;
    }

    protected State getStateNext() {
        return this.next;
    }

    protected boolean checkEvent(String event) {
        for (String event_o : this.events) {
            if (event_o.equals(event)) {
                return true;
            }
        }

        return false;
    }

    protected boolean checkEvents(List<String> events) {

        for (String string : events) {
            if (checkEvent(string) == false) {
                System.out.println("Error: invalid event " + string);
                return false;
            }

        }

        return true;
    }

    /* Simulate simulará la máquina de estados */
    public void simulate(List<String> events) {

        /* Comprobará primero si el nombre es valido */
        if (checkEvents(events) == false) {
            return;
        }

        if (events.size() == 1) {

            for (Transition trans : this.next.transitions) {

                if (trans.getEvent().equals(events.get(0)) == true) {
                    if (trans.getNextState().getStateNext() != null) {
                        System.out.println(
                                this.next.getName() + trans.toString() + trans.getNextState().getStateNext().getName());
                        this.next = trans.getNextState().getStateNext();

                    } else {

                        System.out.println(this.next.getName() + trans.toString() + trans.getNextState().getName());
                        this.next = trans.getNextState();
                    }

                    return;

                } else if (trans.toString() == "---->") {
                    if (trans.getNextState().getStateNext() != null) {
                        System.out.println(
                                this.next.getName() + trans.toString() + trans.getNextState().getStateNext().getName());
                        this.next = trans.getNextState().getStateNext();

                    } else {
                        System.out.println(this.next.getName() + "====>" + trans.getNextState().getName());
                        this.next = trans.getNextState();
                    }
                    return;

                }

            }
        }

        for (Transition trans : this.next.transitions) {

            /*
             * Si las transiciones del estado siguiente contienen dicha transición
             * e se imprimirá por pantalla
             */
            if (trans.getEvent().equals(events.get(0)) == true) {

                if (trans.getNextState().getStateNext() != null) {
                    System.out.println(
                            this.next.getName() + trans.toString() + trans.getNextState().getStateNext().getName());
                    this.next = trans.getNextState().getStateNext();

                } else {
                    /* En el caso de ser un estado inmediato se imprimirá el otro tipo de flecha */

                    System.out.println(this.next.getName() + trans.toString() + trans.getNextState().getName());

                    /* Se avanza al siguiente estado */
                    this.next = trans.getNextState();
                }
                List<String> aux = events.subList(1, events.size());
                simulate(aux);
                return;

            }

            else if (trans.toString() == "---->") {

                if (trans.getNextState().getStateNext() != null) {
                    System.out.println(this.next.getName() + "====>" + trans.getNextState().getStateNext().getName());
                    this.next = trans.getNextState().getStateNext();

                } else {
                    System.out.println(this.next.getName() + "====>" + trans.getNextState().getName());

                    /* Se avanza al siguiente estado */
                    this.next = trans.getNextState();
                }

                this.simulate(events);
                return;

            }

        }

    }

    public CompositeState createCompositeState(String name) {

        CompositeState c = new CompositeState(name, this);

        c.addEvents(this.events().toString());

        this.states.add(c);

        return c;
    }

    public void addState(State s) {
        this.states.add(s);
    }

    public void toPlantUML(String filename) {
        FileWriter fichero = null;
        PrintWriter pw = null;
        try {
            fichero = new FileWriter("../txt/" + filename);
            pw = new PrintWriter(fichero);
           
            pw.println("@startuml");

            for (State st : this.states) {
                pw.print("state " + st.getName() + st.getDescr());

                if (st.getStates() != null) {
                    pw.println("{");

                    for (State st2 : st.getStates()) {
                        pw.println("    state " + st2.getName());

                        if (st2.getStateInitial()) {
                            pw.println("    [*]-->"+st2.getName());
                            
                        }

                    }

                    for (State st2 : st.getStates()) {

                        for (Transition transition : st2.transitions) {
                            
                                
                            if (this.states.get(this.states.indexOf(st) + 1 ).getName() == transition.getNextState().getName()) {
                                
                            }
                            else{

                                pw.println("    " + st2.getName() + "-->" + transition.getNextState().getName() + ": " + transition.getEvent());
                            }
                            
                        }                  
                            
                    }

                    
                    pw.print("}");


                }
                pw.println("");


                if (st.getStateInitial()) {
                    pw.println("[*]-->" + st.getName());
                    
                }

                for (Transition transition : st.transitions) {
                    if (transition.getColor() != null) {
                        
                        pw.println(st.getName() + "-" + "[#" + transition.getColor() + "]->" + transition.getNextState().getName());
                    
                    }
                    if (transition.getEvent() != "") {
                        pw.println(st.getName() + "-->" + transition.getNextState().getName()  + ": " + transition.getEvent() );
                    }

                }
                
            }
            pw.println("@enduml");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (null != fichero)
                    fichero.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }
}
