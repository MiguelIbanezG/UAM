"""Conversion from regex to automata.
Miguel Ibañez y Giancarlo Lazo
"""
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
        lista = []
        self.state_counter = 0
        
        name = str(self.state_counter)
        is_final = False        
        
        estado = State(name, is_final)
        lista.append(estado)

        self.state_counter += 1
        
        name = str(self.state_counter)
        is_final = True
        
        estado = State(name, is_final)
        
        lista.append(estado)    
        
        automata = FiniteAutomaton(lista)
        
        return automata
        
        

    def _create_automaton_lambda(
        self,
    ) -> FiniteAutomaton:
        """
        Create an automaton that accepts the empty string.

        Returns:
            Automaton that accepts the empty string.

        """
        lista = []
        transitions = set()
        
        self.state_counter = 0
        
        name = str(self.state_counter)
        is_final = True
        
        estado = State(name, is_final)
        
        transitions.add(Transition(None, name))
        
        estado.add_transitions(transitions)
        
        lista.append(estado)
        
        automata = FiniteAutomaton(lista)
        
        return automata


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
        state1 = State(str(self.state_counter) ,False)
        self.state_counter += 1
        cad = str(self.state_counter)
        state2 = State(str(self.state_counter), True)
        self.state_counter += 1
        lista_estados = [state1, state2]

        transicion = Transition(symbol, cad)
        lista_transicion = [transicion]
        state1.add_transitions(lista_transicion)

        return FiniteAutomaton(lista_estados)


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

        state1 = State(str(self.state_counter), False)
        self.state_counter += 1
        state2 = State(str(self.state_counter), True)
        self.state_counter += 1
        
        inicio = Transition(None, automaton.states[0].name)
        final = Transition(None, state2.name)
        state1.add_transitions([inicio, final])

        for state in automaton.states:
            if state.is_final:
                state.is_final = False
                state.add_transitions([inicio, final])
                
        lista_estados = [state1] + automaton.states + [state2] 
        return FiniteAutomaton(lista_estados)
    
    
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
        
        state1 = State(str(self.state_counter), False)
        self.state_counter += 1
        state2 = State(str(self.state_counter), True)
        self.state_counter += 1
        estado1 = automaton1.states[0]
        estado2 = automaton2.states[0]
        lista_estados = []

        for state in automaton1.states:
            if state.is_final:
                state.is_final = False
                lista_estados.append(state)
                
        for state in automaton2.states:
            if state.is_final:
                state.is_final = False
                lista_estados.append(state)

        transicion1 = Transition(None, estado1.name)
        transicion2 = Transition(None, estado2.name)
        transicion_final = Transition(None, state2.name)
        tr_s = [transicion1,transicion2]
        state1.add_transitions(tr_s)

        for state in lista_estados:
            state.add_transitions([transicion_final])

        list_states = [state1] + automaton1.states + automaton2.states + [state2]
        return FiniteAutomaton(list_states)
       
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

        inicio = Transition(None, automaton2.states[0].name)

        for state in automaton1.states:
            if state.is_final:
                state.is_final = False
                state.add_transitions([inicio])

        lista_estados = automaton1.states + automaton2.states
        return FiniteAutomaton(lista_estados)

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
