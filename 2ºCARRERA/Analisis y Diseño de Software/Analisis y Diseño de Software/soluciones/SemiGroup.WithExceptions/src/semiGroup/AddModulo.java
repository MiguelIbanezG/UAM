package semiGroup;

public class AddModulo implements IOperation {
	private int modulo;
	public AddModulo(int m) {
		this.modulo = m;
	}

	@Override
	public Integer operate(Integer a, Integer b) {
		return (a+b) % this.modulo;
	}
	
	@Override
	public String toString() {
		return "+ modulo "+this.modulo;
	}
	
}
