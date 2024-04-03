package recordsTable;

import java.util.*;

public class RecordsTable {
	private String title;
	private Map<String, Double> table = new TreeMap<>();

	public RecordsTable(String title) {
		this.title = title;
	}

	public boolean set(String prueba, double tiempo) {
		if (tiempo<0) return false;
		this.table.put(prueba, tiempo);
		return true;
	}

	@Override
	public String toString() {
		return this.title+": "+this.table;
	}
}
