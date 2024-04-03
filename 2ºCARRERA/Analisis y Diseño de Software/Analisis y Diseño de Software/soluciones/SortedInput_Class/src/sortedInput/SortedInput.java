package sortedInput;

import java.util.*;

public class SortedInput {

	public static void main(String[] args) {
		TreeSet<Integer> set = new TreeSet<>();
		for (String a : args)
			set.add(Integer.valueOf(a));
		System.out.println(set);
		System.out.println(set.first());
		System.out.println(set.last());
	}

}
