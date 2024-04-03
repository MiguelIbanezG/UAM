package password.exceptions;

public abstract class InvalidPasswordException extends Exception {
	private String password;
	
	public InvalidPasswordException(String p) {
		this.password = p;
	}
	
	@Override public String toString() {
		return "Invalid password "+this.password+", reason:\n";
	}
}
