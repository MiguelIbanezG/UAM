package semiGroup.exceptions;

public abstract class SemiGroupException extends Exception {
	protected Integer elem;
	
	public SemiGroupException(Integer e) {
		this.elem = e;
	}
}
