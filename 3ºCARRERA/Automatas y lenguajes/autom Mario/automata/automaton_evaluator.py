"""Evaluation of automata."""
from collections import defaultdict, deque
from pickle import TRUE
from typing import Set

from automata.automaton import FiniteAutomaton, State


error = 0

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
        # ---------------------------------------------------------------------
        # TO DO: Implement this method...

        states: Set[State] = set()

        for st in self.current_states:
            for tr in st.transitions:
                if tr.symbol == symbol:
                    for st2 in self.automaton.states:
                        if tr.state == st2.name:
                            states.add(st2)


        self.current_states = states
        self._complete_lambdas(self.current_states)

        # raise NotImplementedError("This method must be implemented.")
        # ---------------------------------------------------------------------

    def _complete_lambdas(self, set_to_complete: Set[State]) -> None:
        """
        Add states reachable with lambda transitions to the set.

        Args:
            set_to_complete: Current set of states to be completed.
        """
        # ---------------------------------------------------------------------
        # TO DO: Implement this method...
        lambda_states = set()
        for stc in set_to_complete:
            for tr in stc.transitions:
                if tr.symbol == None:
                    for st in self.automaton.states:
                        if st.name == tr.state:
                            lambda_states.update(self._lambdas_from_state(st))
        
        set_to_complete.update(lambda_states)

        # raise NotImplementedError("This method must be implemented.")
        # ---------------------------------------------------------------------

    def _lambdas_from_state(self, state: State) -> Set[State]:
        lambda_states = set()
        for tr in state.transitions:
            if tr.symbol == None:
                for st in self.automaton.states:
                    if st.name == tr.state:
                        lambda_states.update(self._lambdas_from_state(st))
        lambda_states.add(state)
        return lambda_states

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
        # ---------------------------------------------------------------------
        # TO DO: Implement this method...

        for cur in self.current_states:
            if cur.is_final:
                return True

        return False
        # raise NotImplementedError("This method must be implemented.")
        # ---------------------------------------------------------------------

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
