package password.policies;

import password.IPasswordPolicy;
import password.exceptions.InvalidPasswordException;
import password.exceptions.NoDigitException;

public class HasDigitPolicy implements IPasswordPolicy{

	@Override
	public void check(String password) throws InvalidPasswordException {
		if (!password.matches(".*\\d.*"))
			throw new NoDigitException(password);
	}

}
