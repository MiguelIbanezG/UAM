package semiGroup;
import java.util.Arrays;
import semiGroup.exceptions.*;

public class SemiGroupMain {
	public static void main(String[] args) {		
		try {
			SemiGroup sg = new SemiGroup(new AddModulo(4), Arrays.asList(0, 1, 2));
		} 
		catch (IllFormedSemiGroupException ex) {
			System.err.println("Malformed!: "+ex);
		}
		catch (SemiGroupException ex) {
			System.err.println(ex);
		}
		
		try {
			SemiGroup sg = new SemiGroup(new AddModulo(3), Arrays.asList(0, 1, 2));
			sg.calculate(0, 3);
		} catch (SemiGroupException ex) {
			ex.printStackTrace();
		}
	}
}
