package fileSystem;

import java.util.*;

import prettyPrint.ITree;

public class Folder extends Element implements ITree {
	private List<Element> elements = new ArrayList<>();

	public Folder(String name) {
		super(name);
	}
	@Override
	public int size() {
		int acum = 0;
		for (Element e : this.elements ) 
			acum += e.size();
		return acum;
	}
	
	@Override public String toString() {
		return super.toString()+" with elements: "+this.elements;
	}
	
	public Folder add(Element e) {
		if (this.canAdd(e))
			this.elements.add(e);
		return this;
	}
	
	private boolean canAdd(Element e) {
		return !this.contains(e) && !e.contains(this);
	}
	
	public boolean contains(Element e) {
		if (this==e) return true;
		for (Element elem: this.elements)
			if (elem.contains(e)) return true;
		return false;
	}
	
	@Override
	public List<ITree> getChildren() {
		return new ArrayList<ITree>(this.elements);
	}

}
