from __future__ import annotations

from collections import deque
from typing import AbstractSet, Collection, MutableSet, Optional, Dict, List, Optional


class RepeatedCellError(Exception):
    """Exception for repeated cells in LL(1) tables."""

class SyntaxError(Exception):
    """Exception for parsing errors."""

class Grammar:
    """
    Class that represents a grammar.

    Args:
        terminals: Terminal symbols of the grammar.
        non_terminals: Non terminal symbols of the grammar.
        productions: Dictionary with the production rules for each non terminal
          symbol of the grammar.
        axiom: Axiom of the grammar.

    """

    def __init__(
        self,
        terminals: AbstractSet[str],
        non_terminals: AbstractSet[str],
        productions: Dict[str, List[str]],
        axiom: str,
    ) -> None:
        if terminals & non_terminals:
            raise ValueError(
                "Intersection between terminals and non terminals "
                "must be empty.",
            )

        if axiom not in non_terminals:
            raise ValueError(
                "Axiom must be included in the set of non terminals.",
            )

        if non_terminals != set(productions.keys()):
            raise ValueError(
                f"Set of non-terminals and productions keys should be equal."
            )
        
        for nt, rhs in productions.items():
            if not rhs:
                raise ValueError(
                    f"No production rules for non terminal symbol {nt} "
                )
            for r in rhs:
                for s in r:
                    if (
                        s not in non_terminals
                        and s not in terminals
                    ):
                        raise ValueError(
                            f"Invalid symbol {s}.",
                        )

        self.terminals = terminals
        self.non_terminals = non_terminals
        self.productions = productions
        self.axiom = axiom

    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}("
            f"terminals={self.terminals!r}, "
            f"non_terminals={self.non_terminals!r}, "
            f"axiom={self.axiom!r}, "
            f"productions={self.productions!r})"
        )


    def compute_first(self, sentence: str) -> AbstractSet[str]:
        """
        Method to compute the first set of a string.

        Args:
            str: string whose first set is to be computed.

        Returns:
            First set of str.
        """
        
        for ch in sentence:
            for c in list(ch):
                if not (c in self.terminals or c in self.non_terminals):
                    raise ValueError
        
        first = set()
        if not sentence:
            first.add('')
            return first
                
        lambdas = 0
        listaAux = []
        flagLambda = False
        
        for elem in sentence:
            if elem == '':
                first.add(elem)
                flagLambda = True
            if elem in self.terminals:
                listaAux.append(list(elem))
                break
            listaAux.append(list(elem))
        
        for sentenceAux in listaAux:
            for elem in sentenceAux:
                if elem in self.terminals:
                    if '' in first and not(flagLambda):
                        first.remove('')
                    first.add(elem)
                    break
                elif elem in self.non_terminals:
                    for rule in self.productions:
                        if rule == elem:
                            new_elems = self.compute_first(self.productions[rule])
                            first.update(new_elems)
                            if '' in new_elems:
                                lambdas += 1
                    if '' not in first:
                        return first
                        
        if lambdas != len(listaAux) and '' in first and not(flagLambda):
            first.remove('')
        
        return first    

    def compute_follow(self, symbol: str) -> AbstractSet[str]:
        """
        Method to compute the follow set of a non-terminal symbol.
        Args:
            symbol: non-terminal whose follow set is to be computed.
        Returns:
            Follow set of symbol.
        """
        
        if not symbol in self.non_terminals:
            raise ValueError
        
        def _compute_follow(self, symbol: str, processed_symbol: Collection[Production]) -> AbstractSet[str]:
            follow = set()
            
            for initial in self.productions:
                break

            if symbol == initial:
                follow.add('$')
            
            lista = []
                
            for rule in self.productions:
                for aux in self.productions[rule]:
                    lista.append(list(aux))
                for listaAux in lista:    
                    if symbol in listaAux:
                        indice = listaAux.index(symbol)
                        if len(listaAux) == indice+1 and rule == initial:
                            follow.add('$')
                            break
                        rightpart = listaAux[indice+1:]
                        if rightpart != '':
                            add = self.compute_first(rightpart)
                            if '' in add:
                                add.remove('')
                                if rule not in processed_symbol:
                                    processed_symbol.append(rule)
                                    follow.update(_compute_follow(self, rule, processed_symbol))
                            follow.update(add)
                        else:
                            if rule not in processed_symbol:
                                processed_symbol.append(rule)
                                follow.update(_compute_follow(self, rule, processed_symbol))
                lista.clear()                
            
            return follow
        
        """
        Method to compute the follow set of a non-terminal symbol.
        Args:
            symbol: non-terminal whose follow set is to be computed.
        Returns:
            Follow set of symbol.
        """    
        
        def _compute_follow2(self, symbol: str, auxdict: Dict[str, Optional[AbstractSet[str]]]) -> AbstractSet[str]:
            lista = []
            
            for rule in self.productions:
                for aux in self.productions[rule]:
                    lista.append(list(aux))
                for listaAux in lista:    
                    if symbol in listaAux:
                        indice = listaAux.index(symbol)
                        if len(listaAux) == indice+1:
                            auxdict[symbol] |= auxdict[rule]
                lista.clear()
    
            return auxdict[symbol]
        
        processed_symbol = []
        auxdict = {t: None for t in self.productions} 
        
        for pr in self.productions:
            auxdict[pr] = _compute_follow(self, pr, processed_symbol)
            processed_symbol.clear()
        
        return _compute_follow2(self, symbol, auxdict)
        


    def get_ll1_table(self) -> Optional[LL1Table]:
        """
        Method to compute the LL(1) table.

        Returns:
            LL(1) table for the grammar, or None if the grammar is not LL(1).
        """
        
        table = LL1Table(self.non_terminals, self.terminals)
        
        for production in self.productions:
            
            first = self.compute_first(self.productions[production])
            follow = self.compute_follow(production)
            for terminal in self.terminals:
                if terminal in first:
                    table.add_cell(production, terminal, self.productions[production])

            if '' in first:
                for terminal in self.terminals:
                    if terminal in follow:
                        table.add_cell(production, terminal, self.productions[production])
            
            if '' in first and '$' in follow:
                table.add_cell(production, '$', self.productions[production])
                
                
        return table

    def is_ll1(self) -> bool:
        return self.get_ll1_table() is not None


class LL1Table:
    """
    LL1 table. Initially all cells are set to None (empty). Table cells
    must be filled by calling the method add_cell.

    Args:
        non_terminals: Set of non terminal symbols.
        terminals: Set of terminal symbols.

    """

    def __init__(
        self,
        non_terminals: AbstractSet[str],
        terminals: AbstractSet[str],
    ) -> None:

        if terminals & non_terminals:
            raise ValueError(
                "Intersection between terminals and non terminals "
                "must be empty.",
            )

        self.terminals: AbstractSet[str] = terminals
        self.non_terminals: AbstractSet[str] = non_terminals
        self.cells: Dict[str, Dict[str, Optional[str]]] = {nt: {t: None for t in terminals} for nt in non_terminals}

    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}("
            f"terminals={self.terminals!r}, "
            f"non_terminals={self.non_terminals!r}, "
            f"cells={self.cells!r})"
        )

    def add_cell(self, non_terminal: str, terminal: str, cell_body: str) -> None:
        """
        Adds a cell to an LL(1) table.

        Args:
            non_terminal: Non termial symbol (row)
            terminal: Terminal symbol (column)
            cell_body: content of the cell 

        Raises:
            RepeatedCellError: if trying to add a cell already filled.
        """
        listaAux = []
        
        for elem in cell_body:
            listaAux.append(list(elem))
            
        if non_terminal not in self.non_terminals:
            raise ValueError(
                "Trying to add cell for non terminal symbol not included "
                "in table.",
            )
        if terminal not in self.terminals:
            print(self.terminals)
            raise ValueError(
                "Trying to add cell for terminal symbol not included "
                "in table.",
            )
        for cell_bodyAux in listaAux:
            if not all(x in self.terminals | self.non_terminals for x in cell_bodyAux):
                raise ValueError(
                    "Trying to add cell whose body contains elements that are "
                    "not either terminals nor non terminals.",
                )            
        if self.cells[non_terminal][terminal] is not None:
            raise RepeatedCellError(
                f"Repeated cell ({non_terminal}, {terminal}).")
        else:
            self.cells[non_terminal][terminal] = cell_body

    def analyze(self, input_string: str, start: str) -> ParseTree:
        """
        Method to analyze a string using the LL(1) table.

        Args:
            input_string: string to analyze.
            start: initial symbol.

        Returns:
            ParseTree object with either the parse tree (if the elective exercise is solved)
            or an empty tree (if the elective exercise is not considered).

        Raises:
            SyntaxError: if the input string is not syntactically correct.
        """
        
        pila = ["$", start]
        pila_in = list(input_string)

        fg = True

        for item in pila_in:

            if (item not in self.terminals) and (item not in self.non_terminals):
                fg = False

        while fg and pila:
            item2 = pila.pop()

            if item2 in self.terminals:
                elem = pila_in.pop(0)

                if elem != item2:
                    fg = False

            elif item2 in self.non_terminals:
                if self.cells[item2][pila_in[0]]:
                    pila.extend(list(reversed(self.cells[item2][pila_in[0]])))

                elif self.cells[item2][pila_in[0]] == None:
                    fg = False

            if (pila and not pila_in) or (pila_in and not pila):
                fg = False

        if not fg:
            raise SyntaxError("The input string is not syntactically correct.",)
        else:
            return ParseTree("", None) 

        

class ParseTree():
    """
    Parse Tree.

    Args:
        root: root node of the tree.
        children: list of children, which are also ParseTree objects.
    """
    def __init__(self, root: str, children: Collection[ParseTree] = []) -> None:
        self.root = root
        self.children = children

    def __repr__(self) -> str:
        return (
            f"{type(self).__name__}({self.root!r}: {self.children})"
        )

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, type(self)):
            return NotImplemented
        return (
            self.root == other.root
            and len(self.children) == len(other.children)
            and all([x.__eq__(y) for x, y in zip(self.children, other.children)])
        )

    def add_children(self, children: Collection[ParseTree]) -> None:
        self.children = children