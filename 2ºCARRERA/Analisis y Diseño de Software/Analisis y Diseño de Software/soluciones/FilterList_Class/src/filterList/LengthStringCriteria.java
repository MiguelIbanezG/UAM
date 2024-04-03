package filterList;

public class LengthStringCriteria extends StringCriteria {

	private int len;

	public LengthStringCriteria(int len) {
		this.len = len;
	}

	@Override
	public boolean test(String s) {
		return s.length()<this.len;
	}

}
