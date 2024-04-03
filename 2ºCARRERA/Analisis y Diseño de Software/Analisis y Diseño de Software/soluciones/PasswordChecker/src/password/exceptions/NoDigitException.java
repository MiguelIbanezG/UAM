package password.exceptions;

public class NoDigitException extends InvalidPasswordException {

	public NoDigitException(String p) {
		super(p);
	}
	
	@Override public String toString() {
		return super.toString()+"The password has no digits";
	}
}
