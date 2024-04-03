package password;

import java.util.*;

import password.exceptions.InvalidPasswordException;
import password.policies.HasDigitPolicy;
import password.policies.MinimumLengthPolicy;

public class PasswordChecker {
	private List<IPasswordPolicy> policies = new ArrayList<>();
	
	public PasswordChecker(IPasswordPolicy ...policies) {
		this.policies.addAll(Arrays.asList(policies));
	}

	public void check(String passw) throws InvalidPasswordException{
		for (IPasswordPolicy pp: this.policies) 
			pp.check(passw);
	}

}
