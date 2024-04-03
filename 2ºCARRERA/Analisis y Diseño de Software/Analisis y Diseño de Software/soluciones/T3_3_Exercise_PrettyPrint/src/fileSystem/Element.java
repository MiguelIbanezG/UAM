package fileSystem;

import prettyPrint.ITree;

public abstract class Element implements ITree{
	protected String name;
	
	public Element(String name) {
		this.name = name;
	}
	
	@Override public String toString() {
		return this.getName();
	}

	public abstract int size();
	public abstract boolean contains(Element e);
	
	@Override
	public String getName() {
		return this.name+" ("+this.size()+" bytes)";
	}
}
