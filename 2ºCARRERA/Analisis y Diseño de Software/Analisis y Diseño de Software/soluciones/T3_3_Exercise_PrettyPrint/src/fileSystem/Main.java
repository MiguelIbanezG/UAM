package fileSystem;

import prettyPrint.PrettyPrinter;

public class Main {

	public static void main(String[] args) {
		File[] files = {new File("init.cfg", 200, FileType.RW),
						new File("system.ini", 100, FileType.R),
						new File("HelloWorld.class", 560, FileType.RW)};
			 
		Folder fld = new Folder("root"),
		       bin = new Folder("bin"),
		       src = new Folder("src");
		
		bin.add(files[2]);
		
		/*fld.add(files[0]).
	    	add(files[1]).
	    	add(bin);*/
		
		  fld.add(files[0]).
		    add(files[1]).
		    add(bin). 
		    add(src).
		    add(fld);
		
		src.add(new File("HelloWorld.java", 145, FileType.RW));
		
		PrettyPrinter.print(fld);
	}

}
