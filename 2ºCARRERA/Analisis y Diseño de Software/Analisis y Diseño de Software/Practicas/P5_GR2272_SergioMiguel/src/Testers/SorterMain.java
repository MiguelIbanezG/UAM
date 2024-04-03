package Testers;

import SortedList.SortedList;

import java.util.List;

import Entity.Person;

import java.time.LocalDate;
import java.util.Comparator;

public class SorterMain {

	public static void main(String[] args) {
		SortedList<Person> sorted = createPeopleList();
		List<Person> list = sorted;		// SortedList is compatible with List
		System.out.println(list);
		sorted.addCriterion(new Comparator<>() {
			@Override
			public int compare(Person o1, Person o2) {
				return o1.getBirthDate().compareTo(o2.getBirthDate());
			}			
		});
		System.out.println(list);
	}

	public static SortedList<Person> createPeopleList() {
		Person people[] = { 
				new Person("Peter", LocalDate.of(2005, 10, 12)),
				new Person("Peter", LocalDate.of(1974, 3, 29)),
				new Person("Paul",  LocalDate.of(2014, 6, 19)),
				new Person("Mary",  LocalDate.of(2001, 1, 1))};

		SortedList<Person> sorted = new SortedList<>(List.of(people));
		return sorted;
	}
}
