package productos;

public enum TipoIva {
	EXENTO(0), SUPERREDUCIDO(6), REDUCIDO(15), NORMAL(23);
	
	private double iva;
	
	private TipoIva(double valor) {
		this.iva = valor;
	}
	
	@Override
	public String toString() {
		return super.toString()+" ("+this.iva+"%)";
	}

	public double getIva() {		
		return this.iva;
	}
}
