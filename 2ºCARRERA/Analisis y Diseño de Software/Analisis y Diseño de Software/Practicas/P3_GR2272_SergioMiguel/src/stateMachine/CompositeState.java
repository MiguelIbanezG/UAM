package stateMachine;
import java.time.*;


public class CompositeState extends StateMachine {

    private StateMachine statemachine;

    protected CompositeState() {
        super("state");
    }

    protected CompositeState(String name, StateMachine statemachine) {
        super(name);
        this.statemachine = statemachine;

    }

    protected CompositeState(String name) {
        super(name);

    }


    @Override
    public CompositeState createState(String name) {

        if (checkWord(name) == false) {
            CompositeState s = new CompositeState();

            return s;
        }

        
        CompositeState s = new CompositeState(name);


        this.addState(s);

        return s;
    }

    protected boolean checkWord(String name) {

        for (int i = 0; i < name.length(); i++) {

            if (((int) name.charAt(i) >= 48 && (int) name.charAt(i) <= 57) || ((int) name.charAt(i) >= 65
                    && (int) name.charAt(i) <= 90) || ((int) name.charAt(i) >= 97 && (int) name.charAt(i) <= 122)) {

            } else {
                return false;
            }
        }

        return true;
    }

 

    /* función para pasar a cadena */
    @Override
    public String toString() {

        String s = new String();

        if (this.getStates().isEmpty()) {
            s = this.getName();

        } else {
            s = this.getName() + "]" + " with states: {[";

            for (State st : this.states()) {
                s = s + "State[" + st.toString() + "]";
                s = s + ", ";
            }
            s = s.substring(0, s.length() - 2) + "]}";
        }
        

        return s;
    }

    @Override
    public boolean connect(String st1, String st2, String nameEvent) {
        
        for (String str : this.statemachine.events()) {
            this.addEvents(str);
        }

        /* Comprobará primero si el nombre es valido */
        if (checkEvent(nameEvent) == false) {
            return false;

        }

        int istate2 = 0;
        /* Después se busca cual es el estado al que se va a pasar */
        for (State state2 : this.states()) {
            if (state2.getName() == st2) {
                istate2 = this.states().indexOf(state2);

                break;
            }
        }
        
        for (State st : this.states()) {
            if (st.getName() == st1) {
                /*
                 * Aquí se busca en que estado se está
                 */
                if (this.states().indexOf(st) > istate2 && istate2 == 0
                        && this.states().indexOf(st) != this.states().size() - 1) {
                    return false;
                }

                /*
                 * Se llama a la función de transición con los parámetros de los índices
                 * obtenidos anteriormente
                 */
                /* Y se modifica el estado en el que se está el bucle */
                TriggeredTransition trans = new TriggeredTransition(this.states().get(istate2), nameEvent);
                
                this.states().get(this.getStates().indexOf(st)).addTransition(trans);


              
            }
        }

        return true;
    }

}    



























