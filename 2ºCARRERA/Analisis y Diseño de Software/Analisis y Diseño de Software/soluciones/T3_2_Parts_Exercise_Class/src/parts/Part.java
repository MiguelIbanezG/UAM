package parts;

public class Part {
	private double weight;
	private int id;
	private static int numParts = 0;
	private static Part heaviest = null;
	
	public Part(double weight) {
		this.weight = weight;
		this.id = Part.numParts++;
		this.updateHeaviest();
	}

	private void updateHeaviest() {
		if (Part.heaviest==null ||
			this.weight>Part.heaviest.weight)
			Part.heaviest = this;
	}

	@Override
	public String toString() {
		return "Part [weight=" + this.weight + 
			   ", id=" + this.id + "]";
	}

	public static Part heaviest() {
		return Part.heaviest;
	}
}
