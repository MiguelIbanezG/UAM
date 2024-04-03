package fileSystem;

import java.util.Collections;
import java.util.List;

import prettyPrint.ITree;

public class File extends Element {
	private int size;
	private FileType fileType;

	public File(String name, int size, FileType fileType) {
		super(name);
		this.size = size;
		this.fileType = fileType;
	}

	@Override
	public int size() {
		return this.size;
	}
	
	@Override public String toString() {
		return super.toString()+" ["+this.fileType+"]";
	}

	@Override
	public boolean contains(Element e) {
		return this==e;
	}

	@Override
	public List<ITree> getChildren() {
		return Collections.emptyList();
	}

}
