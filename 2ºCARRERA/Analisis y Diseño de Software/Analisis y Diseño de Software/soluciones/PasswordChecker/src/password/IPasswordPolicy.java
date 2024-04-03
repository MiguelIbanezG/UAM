package password;

import password.exceptions.InvalidPasswordException;

public interface IPasswordPolicy {
	void check(String password) throws InvalidPasswordException;
}
