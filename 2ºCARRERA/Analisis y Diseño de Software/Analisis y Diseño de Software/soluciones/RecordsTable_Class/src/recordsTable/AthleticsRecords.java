package recordsTable;

public class AthleticsRecords {
	public static void main(String[] args) {
		RecordsTable menRecords = new RecordsTable("Athletics world records");
		menRecords.set("100 meters", 9.58);
		menRecords.set("400 meters", 43.03);
		menRecords.set("200 meters", 19.19);
		if (!menRecords.set("50 meters", -0.3))
			System.out.println("Invalid value!");
		System.out.println(menRecords); // orden alfabético de pruebas
	}
}

