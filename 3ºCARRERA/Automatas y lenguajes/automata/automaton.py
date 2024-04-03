"""Automaton implementation.
Giancarlo Lazo y Miguel Ibañez
"""
from os import stat_result
from typing import (
    Optional,
    Set,
    List,
    Dict,
)

class State():
    """
    Definition of an automaton state. 

    Args:
        name: Name of the state.
        is_final: Whether the state is a final state or not.
        transitions: The list of transitions starting at this state.

    """

    name: str
    is_final: bool
    transitions: List['Transition']

    def __init__(self, name: str, is_final: bool = False) -> None:
        self.name = name
        self.is_final = is_final
        self.transitions = []

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, type(self)):
            return NotImplemented

        return (
            self.name == other.name
        )

    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}({self.name!r}, is_final={self.is_final!r}, transitions={self.transitions!r})"
        )

    def __hash__(self) -> int:
        return hash(self.name)

    def add_transitions(self, transitions: List['Transition']) -> None:
        """
        Convert to set and back to list to avoid repeated transitions.
        """
        self.transitions.extend(transitions)
        self.transitions = list(set(self.transitions))
    


class Transition():
    """
    Definition of an automaton transition. Since all transitions 
    'belong' to a given state, the initial state is not specified. 

    Args:
        symbol: Symbol consumed in the transition.
            ``None`` for a lambda transition.
        state: Name of the final state of the transition.

    """

    symbol: Optional[str]
    state: str

    def __init__(
        self,
        symbol: Optional[str],
        state: str,
    ) -> None:
        self.symbol = symbol
        self.state = state

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, type(self)):
            return NotImplemented

        return (
            self.symbol == other.symbol
            and self.state == other.state
        )

    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}("
            f"{self.symbol!r}, {self.state!r})"
        )

    def __hash__(self) -> int:
        return hash((self.symbol, self.state))




class FiniteAutomaton():
    """
    Definition of an automaton.

    Args:
        states: List of states of the automaton. The first state in the 
                list is the initial state.

    """

    states: List[State]
    name2state: Dict[str, State]
    
    sumidero: Optional[State]
    
    def __init__(
        self,
        states: List[State],
    ) -> None:
        """
        Check that there are no states with the same name.
        """
        if len(set(states)) != len(states):
            raise ValueError(
                "There are states with the same name",
            )
        """
        Check that the states in all transitions exist.
        """
        if not {t.state for s in states for t in s.transitions}.issubset({s.name for s in states}):
            raise ValueError(
                "There are transitions to an undefined state",
            )
        
        self.states = states
        self.name2state = {s.name: s for s in self.states}
        
        self.sumidero = None


    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}("
            f"states={self.states!r}, "
        )

    def state_lambdas(self, state: State) -> Set[State]:
        estados_lambda = set()
        for sy in state.transitions:
            if sy.symbol == None:
                for state2 in self.states:
                    if state2.name == sy.state:
                        estados_lambda.update(self.state_lambdas(state2))
        estados_lambda.add(state)
        return estados_lambda
        
    def is_accepting(self, current_states: Set[State]) -> bool:
        """Check if the current state is an accepting one."""
        #---------------------------------------------------------------------
        # TO DO: Implement this method...       
        #---------------------------------------------------------------------
        for state1 in current_states:
            if state1.is_final == True:
                return True
        return False        

    def to_deterministic(self) -> 'FiniteAutomaton':
        """
        Return a equivalent deterministic automaton.

        Returns:
            Equivalent deterministic automaton.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...
        estado = self.states[0]
        estadoInicialLambdas = self.state_lambdas(estado) 
        
        is_final = self.is_accepting(estadoInicialLambdas) 
        
        nombreConjunto = ''
        for auxEstado in estadoInicialLambdas:
            nombreConjunto += auxEstado.name
        
        estadoInicial = State(nombreConjunto, is_final)
        
        estadosDic = {estadoInicial.name: estadoInicialLambdas}
        
        estadosLista = [estadoInicial]
        
        allSymbols = set()
        
        for symbState in self.states:
            for symbStateTrans in symbState.transitions:
                allSymbols.add(symbStateTrans.symbol) #= self.symbols  
        
        i = 0
        
        while i < len(estadosLista):
            estado = estadosLista[i]
            estadoTransitions = []
            
            transicionesDic = {} #nombre de simbolo; estados a los que llega
            
            for state in estadosDic[estado.name]: #nuevos estados a los que se llega desde el estado inicial (conformado por estados)
                trans = state.transitions
                for tr in trans:
                    if tr.symbol not in transicionesDic and tr.symbol is not None:
                        transicionesDic[tr.symbol] = {self.name2state[tr.state]} #usar el nombre del estado y con name2state sacar el estado
                    else:
                        transicionesDic[tr.symbol].add(self.name2state[tr.state])
                        
            for simbolo in transicionesDic.keys():
                is_final = False
                finded = False
                for state in transicionesDic[simbolo]:                                    
                    estadomasLambdas = self.state_lambdas(state)      
                    final = self.is_accepting(estadomasLambdas)  
                    if final is True:
                        is_final = final
                    transicionesDic[simbolo] = transicionesDic[simbolo].union(estadomasLambdas)  
                
                nombreConjunto = ''
                for auxEstado in transicionesDic[simbolo]:
                    nombreConjunto += auxEstado.name
                    
                for auxSets in estadosDic.values():
                    nombreConjunto2 = ''
                    for auxSetEstado in auxSets: 
                        nombreConjunto2 += auxSetEstado.name
                    if nombreConjunto == nombreConjunto2:
                        finded = True
                        break                            
                    
                if finded is False:
                    estadosDic[nombreConjunto] = transicionesDic[simbolo]
                    nuevoEstado = State(nombreConjunto, is_final)
                    estadosLista.append(nuevoEstado)
                    newTr = Transition(simbolo, nuevoEstado.name)
                else:
                    for stateCon in estadosLista:
                        if stateCon.name == nombreConjunto:
                            newTr = Transition(simbolo, stateCon.name)
                            break

                estadoTransitions.append(newTr)
                

            for symbol in allSymbols:
                if symbol not in transicionesDic.keys():
                    if self.sumidero is None:
                        self.sumidero = State("vacio", is_final = False)
                    estadoTransitions.append(Transition(symbol, self.sumidero.name))                                         
                                         
            estado.add_transitions(estadoTransitions)

            i += 1            
                       
        if self.sumidero is not None:
            listaSumidero = []
            for s in allSymbols:
                  listaSumidero.append(Transition(s, self.sumidero.name))
            self.sumidero.add_transitions(listaSumidero)      
            estadosLista.append(self.sumidero)               
      
        return FiniteAutomaton(estadosLista)      
                      
                      

    def accepts(self, cad):
        node = self.states[-1]
        for char in cad:
            node = self.to_deterministic(node, char)
        return self.states.__eq__(node)
        


    def to_minimized(self) -> 'FiniteAutomaton':
        """
        Return a equivalent minimal automaton.

        Returns:
            Equivalent minimal automaton.

        """
        #---------------------------------------------------------------------
        # TO DO: Implement this method...
    
        dic0 = dict()
        dic1 = dict()
        estados = [self.states[0],]
        estados_accesibles = set()
        symbols = list()
        i = 0
        
        #Para eliminar los estados inaccesibles
        for i in range(1, len(estados)):
            state = estados.pop()
            for tr in state.transitions:
                if self.name2state[tr.state] not in estados_accesibles:
                    estados.append(self.name2state[tr.state])
                if tr.symbol not in symbols:
                    symbols.append(tr.symbol)
            estados_accesibles.add(state)
            
        for acc in estados_accesibles:
            if acc.is_final:
                dic0[acc] = 1
            else:
                dic0[acc] = 0
        while dic0 != dic1:
            count = 0
            for acc in estados_accesibles:
                if acc not in dic1.keys():
                    dic1[acc] = count
                    for acc1 in estados_accesibles:
                        if acc1 not in dic1.keys():
                            if dic0[acc] == dic0[acc1]:
                                fl = True
                                for sy in symbols:
                                    for tr in acc.transitions:
                                        if tr.symbol == sy:
                                            trasn_acc = self.name2state[tr.state]
                                    for tr1 in acc1.transitions:
                                        if tr1.symbol == sy:
                                            trasn_acc1 = self.name2state[tr1.state]
                                    if dic0[trasn_acc] != dic0[trasn_acc1]:
                                        fl = False
                                if fl:
                                    dic1[acc1] = dic1[acc]
                    count += 1
                                    
            if dic0 != dic1:
                dic0 = dic1
                dic1 = dict()

        nuevo_estados = dict()


        #Creamos los estados nuevos
        for value in dic0.values():
            list_estado = set()
            for st in dic0.keys():
                if dic0[st] == value:
                    list_estado.add(st)
            list_estado = sorted(list_estado, key = lambda state: state.name)
            nuevo_estados[value] = list_estado

        states = list()
        
        for lt in nuevo_estados.values():
            string = ""
            flag = False
            for st in lt:
                string += st.name
                if st.is_final:
                    flag = True
            nuevo_estado = State(string, flag)
            for sy in symbols:
                symbol_transitions = list()
                for st in lt:
                    for tr in st.transitions:
                        if tr.symbol == sy:
                            symbol_transitions.append(self.name2state[tr.state])
                    for lt1 in nuevo_estados.values():
                        count = 0
                        if len(lt1) == len(symbol_transitions):
                            for sy1 in symbol_transitions:
                                for sy2 in lt1:
                                    if sy1.name == sy2.name:
                                        count += 1
                            if count == len(lt1):
                                cad = ""
                                for st3 in lt1:
                                    cad += st3.name
                nuevo_estado.add_transitions([Transition(sy, cad)])
            states.append(nuevo_estado)

        nombre = ""
        for est in nuevo_estados.values():
            for st in est:
                if st.name == self.states[0].name:
                    for sy1 in est:
                        nombre += sy1.name
        
        index = 0
        i = 0
        for st in states:
            if st.name == nombre:
                index = i
            i += 1
        
        states[0], states[index] = states[index], states[0]

        return FiniteAutomaton(states)     
