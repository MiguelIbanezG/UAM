package prettyPrint;

import java.util.List;

public interface ITree {
	String getName();
	List<ITree> getChildren();
}
