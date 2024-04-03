package semiGroup.exceptions;

public class ResultOutOfGroupException extends SemiGroupException {

	public ResultOutOfGroupException(Integer e) {
		super(e);
	}
	
	@Override public String toString() {
		return "Result "+this.elem+" is not an element of the semigroup";
	}
}
