package parts;

import java.util.List;

public class PartsExercise {
	public static void main(String[] args) {
		List<Part> parts = List.of(	new Part(5.4), 
									new Part(10), 
									new Part(3));		
		System.out.println(parts);
		System.out.println(Part.heaviest());
	}
}
