package semiGroup;

import java.util.*;

import semiGroup.exceptions.IllFormedSemiGroupException;
import semiGroup.exceptions.ParameterNotInGroupException;
import semiGroup.exceptions.ResultOutOfGroupException;
import semiGroup.exceptions.SemiGroupException;

public class SemiGroup {
	private Set<Integer> set = new LinkedHashSet<Integer>();
	private IOperation oper;
	
	public SemiGroup(IOperation oper, Collection<Integer> elems) throws IllFormedSemiGroupException{
		this.oper = oper;
		this.set.addAll(elems);
		this.checkSemiGroup();
	}

	private void checkSemiGroup() throws IllFormedSemiGroupException{
		for (Integer p1 : this.set)
			for (Integer p2 : this.set)
				try {
					this.calculate(p1, p2);
				} catch (SemiGroupException e) {
					throw new IllFormedSemiGroupException(p1, p2, this.oper);
				}
	}

	public Integer calculate(Integer i, Integer j) throws SemiGroupException{
		if (!this.set.contains(i)) throw new ParameterNotInGroupException(i);
		if (!this.set.contains(j)) throw new ParameterNotInGroupException(j);
		Integer res = this.oper.operate(i, j);
		if (!this.set.contains(res)) throw new ResultOutOfGroupException(res);
		return res;
	}

	@Override
	public String toString() {
		return this.set.toString()+" with operation "+this.oper;
	}
}
