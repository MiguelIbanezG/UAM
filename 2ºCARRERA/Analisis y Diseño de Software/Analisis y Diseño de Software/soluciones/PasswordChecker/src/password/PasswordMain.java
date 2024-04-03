package password;

import password.exceptions.InvalidPasswordException;
import password.policies.HasDigitPolicy;
import password.policies.MinimumLengthPolicy;

public class PasswordMain {

	public static void main(String[] args) {
		PasswordChecker pc = new PasswordChecker(new MinimumLengthPolicy(5),
				  								 new HasDigitPolicy());
		
		try {
			pc.check("admin");
		} catch (InvalidPasswordException ex) {
			System.err.println(ex);
		}
	}
}
