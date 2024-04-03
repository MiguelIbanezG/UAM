"""Conversion from regex to automata."""
from typing import List

from automata.automaton import FiniteAutomaton, State, Transition

def _re_to_rpn(re_string: str) -> str:
    """
    Convert re to reverse polish notation (RPN).

    Does not check that the input re is syntactically correct.

    Args:
        re_string: Regular expression in infix notation.

    Returns:
        Regular expression in reverse polish notation.

    """
    stack: List[str] = []
    rpn_string = ""
    for x in re_string:
        if x == "+":
            while len(stack) > 0 and stack[-1] != "(":
                rpn_string += stack.pop()
            stack.append(x)
        elif x == ".":
            while len(stack) > 0 and stack[-1] == ".":
                rpn_string += stack.pop()
            stack.append(x)
        elif x == "(":
            stack.append(x)
        elif x == ")":
            while stack[-1] != "(":
                rpn_string += stack.pop()
            stack.pop()
        else:
            rpn_string += x

    while len(stack) > 0:
        rpn_string += stack.pop()

    return rpn_string



class REParser():
    """Class for processing regular expressions in Kleene's syntax."""

    state_counter: int

    def __init__(self) -> None:
        self.state_counter = 0

    def _create_automaton_empty(
        self,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the empty language.

        Returns:
            Automaton that accepts the empty language.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...


        string = "q" + str(self.state_counter)
        st1 = State(string, False)
        self.state_counter += 1
        st2 = State("q" + str(self.state_counter), True)
        self.state_counter += 1
        list_st = [st1, st2]

        tr = Transition(None, string)
        list_tr = [tr]
        st1.add_transitions(list_tr)

        return FiniteAutomaton(list_st)
        #---------------------------------------------------------------------
        

    def _create_automaton_lambda(
        self,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the empty string.

        Returns:
            Automaton that accepts the empty string.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...

        q1 = State("q" + str(self.state_counter), False)
        self.state_counter += 1
        string = "q" + str(self.state_counter)
        q2 = State(string, True)
        self.state_counter += 1

        q1_tr1 = Transition(None, string)
        q1.add_transitions([q1_tr1,])

        states = [q1, q2]

        return FiniteAutomaton(states)

        #---------------------------------------------------------------------


    def _create_automaton_symbol(
        self,
        symbol: str,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts one symbol.

        Args:
            symbol: Symbol that the automaton should accept.

        Returns:
            Automaton that accepts a symbol.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...

        st1 = State("q" + str(self.state_counter) ,False)
        self.state_counter += 1
        string = "q" + str(self.state_counter)
        st2 = State(string, True)
        self.state_counter += 1
        list_st = [st1, st2]

        tr = Transition(symbol, string)
        list_tr = [tr]
        st1.add_transitions(list_tr)

        return FiniteAutomaton(list_st)
        #---------------------------------------------------------------------


    def _create_automaton_star(
        self,
        automaton: FiniteAutomaton,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the Kleene star of another.

        Args:
            automaton: Automaton whose Kleene star must be computed.

        Returns:
            Automaton that accepts the Kleene star.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...

        init_state = State("q" + str(self.state_counter), False)
        self.state_counter += 1
        final_state = State("q" + str(self.state_counter), True)
        self.state_counter += 1
        

        to_start = Transition(None, automaton.states[0].name)
        to_final = Transition(None, final_state.name)

        init_state.add_transitions([to_start, to_final])

        for st in automaton.states:
            if st.is_final:
                st.is_final = False
                st.add_transitions([to_start, to_final])
                
        state_list = [init_state,] + automaton.states + [final_state,] 
        return FiniteAutomaton(state_list)
        #---------------------------------------------------------------------


    def _create_automaton_union(
        self,
        automaton1: FiniteAutomaton,
        automaton2: FiniteAutomaton,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the union of two automata.

        Args:
            automaton1: First automaton of the union.
            automaton2: Second automaton of the union.

        Returns:
            Automaton that accepts the union.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...

        if not automaton1 and automaton2:
            return automaton2
        if not automaton2 and automaton1:
            return automaton1
        if not automaton1 and not automaton2:
            return None
        
        st_s = State("q" + str(self.state_counter), False)
        self.state_counter += 1
        st_f = State("q" + str(self.state_counter), True)
        self.state_counter += 1
        st1 = automaton1.states[0]
        st2 = automaton2.states[0]
        list_st = []

        for s in automaton1.states:
            if s.is_final:
                s.is_final = False
                list_st.append(s)
                
        for s in automaton2.states:
            if s.is_final:
                s.is_final = False
                list_st.append(s)

        tr1 = Transition(None, st1.name)
        tr2 = Transition(None, st2.name)
        tr_f = Transition(None, st_f.name)
        
        tr_s = [tr1,tr2]
        st_s.add_transitions(tr_s)

        for s in list_st:
            s.add_transitions([tr_f,])

        list_states = [st_s,] + automaton1.states + automaton2.states + [st_f,]
        
        return FiniteAutomaton(list_states)
        #---------------------------------------------------------------------


    def _create_automaton_concat(
        self,
        automaton1: FiniteAutomaton,
        automaton2: FiniteAutomaton,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the concatenation of two automata.

        Args:
            automaton1: First automaton of the concatenation.
            automaton2: Second automaton of the concatenation.

        Returns:
            Automaton that accepts the concatenation.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...

        if not automaton1 and automaton2:
            return automaton2
        if not automaton2 and automaton1:
            return automaton1
        if not automaton1 and not automaton2:
            return None

        to_start = Transition(None, automaton2.states[0].name)



        
        for st in automaton1.states:
            if st.is_final:
                st.is_final = False
                st.add_transitions([to_start,])

        list_states = automaton1.states + automaton2.states


        return FiniteAutomaton(list_states)
        #---------------------------------------------------------------------


    def create_automaton(
        self,
        re_string: str,
    ) -> FiniteAutomaton:
        """
        Create an automaton from a regex.

        Args:
            re_string: String with the regular expression in Kleene notation.

        Returns:
            Automaton equivalent to the regex.

        """
        if not re_string:
            return self._create_automaton_empty()
        
        rpn_string = _re_to_rpn(re_string)

        stack: List[FiniteAutomaton] = []
        self.state_counter = 0
        for x in rpn_string:
            if x == "*":
                aut = stack.pop()
                stack.append(self._create_automaton_star(aut))
            elif x == "+":
                aut2 = stack.pop()
                aut1 = stack.pop()
                stack.append(self._create_automaton_union(aut1, aut2))
            elif x == ".":
                aut2 = stack.pop()
                aut1 = stack.pop()
                stack.append(self._create_automaton_concat(aut1, aut2))
            elif x == "λ":
                stack.append(self._create_automaton_lambda())
            else:
                stack.append(self._create_automaton_symbol(x))

        return stack.pop()
