package fileSystem;

public abstract class FSElement {
	private String name;
	
	public FSElement(String name) {
		this.name = name;
	}
	
	public abstract int size();
	protected boolean contains(FSElement e) {
		return this == e;
	}

	@Override
	public String toString() {
		return this.name+" ("+this.size()+" bytes)";
	}
}
