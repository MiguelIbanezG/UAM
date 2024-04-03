"""Evaluation of automata.
Miguel Ibañez y Giancarlo Lazo
"""
from collections import defaultdict, deque
from pickle import TRUE
from typing import Set

from automata.automaton import FiniteAutomaton, State

class FiniteAutomatonEvaluator():
    """
    Definition of an automaton evaluator.

    Args:
        automaton: Automaton to evaluate.

    Attributes:
        current_states: Set of current states of the automaton.

    """

    automaton: FiniteAutomaton
    current_states: Set[State]

    def __init__(self, automaton: FiniteAutomaton) -> None:
        self.automaton = automaton
        current_states: Set[State] = {
            self.automaton.states[0],  
        }
        self._complete_lambdas(current_states)
        self.current_states = current_states


    def process_symbol(self, symbol: str) -> None:
        """
        Process one symbol.

        Args:
            symbol: Symbol to consume.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...        
        #---------------------------------------------------------------------
    
        estados: Set[State] = set()
        for state1 in self.current_states:
            for sy in state1.transitions:
                if sy.symbol == symbol:
                    for state2 in self.automaton.states:
                        if sy.state == state2.name:
                            estados.add(state2)
       
        self.current_states = estados
        self._complete_lambdas(self.current_states)
        
    def _complete_lambdas(self, set_to_complete: Set[State]) -> None:
        """
        Add states reachable with lambda transitions to the set.

        Args:
            set_to_complete: Current set of states to be completed.

        estados: Set[State] = set()
        for state1 in set_to_complete:
            for sy in state1.transitions:
                if sy.symbol == None:
                    for state2 in self.automaton.states:
                        if sy.state == state2.name:
                            estados.add(state2)
        if not estados:
            return
        set_to_complete.update(estados)
        self._complete_lambdas(estados)
        """
        # ---------------------------------------------------------------------
        # TO DO: Implement this method...
        estados = set()
        for state1 in set_to_complete:
            for sy in state1.transitions:
                if sy.symbol == None:
                    for state2 in self.automaton.states:
                        if sy.state == state2.name:
                            estados.add(state2)
        if not estados:
            return
        set_to_complete.update(estados)
        self._complete_lambdas(estados)

        estados_lambda = set()
        for state1 in set_to_complete:
            for sy in state1.transitions:
                if sy.symbol == None:
                    for state2 in self.automaton.states:
                        if state2.name == sy.state:
                            estados_lambda.update(self.state_lambdas(state2))

        set_to_complete.update(estados_lambda)

        # raise NotImplementedError("This method must be implemented.")
        # ---------------------------------------------------------------------

    def state_lambdas(self, state: State) -> Set[State]:
        estados_lambda = set()
        for sy in state.transitions:
            if sy.symbol == None:
                for state2 in self.automaton.states:
                    if state2.name == sy.state:
                        estados_lambda.update(self.state_lambdas(state2))
        estados_lambda.add(state)
        return estados_lambda
        
    def process_string(self, string: str) -> None:
        """
        Process a full string of symbols.

        Args:
            string: String to process.

        """
        for symbol in string:
            self.process_symbol(symbol)


    def is_accepting(self) -> bool:
        """Check if the current state is an accepting one."""
        #---------------------------------------------------------------------
        # TO DO: Implement this method...       
        #---------------------------------------------------------------------
        for state1 in self.current_states:
            if state1.is_final == True:
                return True
        return False
        

    def accepts(self, string: str) -> bool:
        """
        Return if a string is accepted without changing state.

        Note: This function is NOT thread-safe.

        """
        old_states = self.current_states
        try:
            self.process_string(string)
            accepted = self.is_accepting()
        finally:
            self.current_states = old_states

        return accepted

