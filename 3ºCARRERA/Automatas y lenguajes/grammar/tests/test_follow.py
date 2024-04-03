import sys
import os
sys.path.append(os.path.join(os.path.dirname(__file__), "..", ".."))
sys.path.append(os.path.join(os.path.dirname(__file__), ".."))

import unittest

from grammar.grammar import Grammar, LL1Table, ParseTree, SyntaxError
from grammar.utils import GrammarFormat
from typing import Optional, Type
from typing import AbstractSet, DefaultDict, Dict, List


class TestFollow(unittest.TestCase):
    def _check_follow(
        self,
        grammar: Grammar,
        symbol: str,
        follow_set: AbstractSet[str],
    ) -> None:
        with self.subTest(string=f"Follow({symbol}), expected {follow_set}"):
            computed_follow = grammar.compute_follow(symbol)
            self.assertEqual(computed_follow, follow_set)

    def test_case1(self) -> None:
        """Test Case 1."""
        grammar_str = """
        E -> TX
        X -> +E
        X ->
        T -> iY
        T -> (E)
        Y -> *T
        Y ->
        """

        grammar = GrammarFormat.read(grammar_str)
        self._check_follow(grammar, "E", {'$', ')'})
        self._check_follow(grammar, "T", {'$', ')', '+'})
        self._check_follow(grammar, "X", {'$', ')'})
        self._check_follow(grammar, "Y", {'$', ')', '+'})


if __name__ == '__main__':
    unittest.main()
