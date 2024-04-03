package fileSystem;

import java.util.*;

public class Folder extends FSElement {
	private List<FSElement> content = new ArrayList<>();

	public Folder(String name) {
		super(name);		
	}

	@Override
	public int size() {
		int acum = 0;
		for (FSElement e : this.content) 
			acum += e.size();
		
		return acum;
	}

	public Folder add(FSElement e) {
		if (this.contains(e) || e.contains(this)) return this;
		this.content.add(e);
		return this;
	}
	
	@Override
	protected boolean contains(FSElement e) {
		if (super.contains(e)) return true;
		for (FSElement element : this.content) 
			if (element.contains(e)) return true;
		
		return false;
	}
	
	@Override
	public String toString() {
		String ret = super.toString()+" folder:";
		for (FSElement e : this.content)
			ret += "\n  "+e;
		return ret;
	}
}
