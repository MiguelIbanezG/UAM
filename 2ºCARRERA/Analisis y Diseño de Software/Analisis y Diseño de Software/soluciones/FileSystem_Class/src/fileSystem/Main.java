package fileSystem;

public class Main {

	public static void main(String[] args) {
		File f1 = new File("init.cfg", 200, FileType.RW);
		File f2 = new File("system.ini", 100, FileType.R);
		Folder fld = new Folder("root");
		Folder bin = new Folder("bin");
		
		bin.add(new File("config.sys", 10, FileType.R));
		
		fld.add(f1).
		    add(f2).
		    add(bin).
		    add(f1).
		    add(fld);
		
		/*fld.add(f1).
	    	add(f2).
	    	add(bin);*/
			
		System.out.println(f1.size() + " "+fld.size());
		System.out.println(f1+"\n"+f2+"\n"+fld);
	}

}
