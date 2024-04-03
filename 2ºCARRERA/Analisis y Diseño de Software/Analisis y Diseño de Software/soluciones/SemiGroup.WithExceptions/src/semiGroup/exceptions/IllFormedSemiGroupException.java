package semiGroup.exceptions;

import semiGroup.IOperation;

public class IllFormedSemiGroupException extends SemiGroupException {
	private Integer elem2;
	private IOperation op;
	public IllFormedSemiGroupException(Integer e1, Integer e2, IOperation op) {
		super(e1);
		this.elem2 = e2;
		this.op = op;
	}
	
	@Override public String toString() {
		return "Ill-formed semigroup: operating "+this.elem+" and "+this.elem2+" yields "+
			   this.op.operate(this.elem, this.elem2)+
			   " which is not an element of the semigroup";
	}
}
