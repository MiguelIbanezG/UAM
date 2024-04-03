package filterList;

import java.util.*;

public class FilterList {

	private static List<String> filter(List<String> myList,
									   StringCriteria sc) {
		List<String> toDelete = new ArrayList<>();
		for (String s : myList) 
			if (sc.test(s)) toDelete.add(s);
		myList.removeAll(toDelete);
		return myList;
	}
	
	public static void main(String[] args) {
		List<String> myList = new ArrayList<>();
		myList.addAll(List.of("Esto", "es", "una", "prueba"));
		System.out.println(myList);
		myList = FilterList.filter(myList, new LengthStringCriteria(4));
		System.out.println(myList);
	}
}
