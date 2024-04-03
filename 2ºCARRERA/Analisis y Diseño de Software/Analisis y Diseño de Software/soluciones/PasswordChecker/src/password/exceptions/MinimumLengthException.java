package password.exceptions;

public class MinimumLengthException extends InvalidPasswordException {
	private int length;
	
	public MinimumLengthException(String password, int length) {
		super(password);
		this.length = length;
	}

	@Override public String toString() {
		return super.toString()+"Does not have minimum size "+this.length;
	}
}
