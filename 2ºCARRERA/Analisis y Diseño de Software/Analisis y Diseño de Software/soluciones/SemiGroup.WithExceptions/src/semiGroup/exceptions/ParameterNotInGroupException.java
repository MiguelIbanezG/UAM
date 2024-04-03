package semiGroup.exceptions;

public class ParameterNotInGroupException extends SemiGroupException {

	public ParameterNotInGroupException(Integer e) {
		super(e);
	}
	
	@Override public String toString() {
		return "Parameter "+this.elem+" is not an element of the semigroup";
	}

}
