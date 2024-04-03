package password.policies;

import password.IPasswordPolicy;
import password.exceptions.InvalidPasswordException;
import password.exceptions.MinimumLengthException;

public class MinimumLengthPolicy implements IPasswordPolicy {
	private int length;
		
	public MinimumLengthPolicy(int i) {
		this.length = i;
	}

	@Override
	public void check(String password) throws InvalidPasswordException {
		if (password.length()<this.length)
			throw new MinimumLengthException(password, this.length);
	}

}
