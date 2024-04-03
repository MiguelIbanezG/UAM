package fileSystem;

public class File extends FSElement {
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
	
	@Override
	public String toString() {
		return super.toString()+" "+this.fileType;
	}
}
