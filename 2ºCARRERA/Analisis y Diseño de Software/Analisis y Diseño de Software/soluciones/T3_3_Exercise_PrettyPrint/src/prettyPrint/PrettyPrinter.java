package prettyPrint;

public class PrettyPrinter {
	private static void print(ITree tree, String indent) {
		System.out.println(indent+tree.getName());
		for (ITree t : tree.getChildren())
			print(t, indent+"  ");
	}
	
	public static void print(ITree tree) {
		print(tree, "");
	}
}
