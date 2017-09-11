package application;

public class Expert implements Printable {

	private String name; // all experts return their name from server
	private String secondField; // each expert returns different
								// description(age, job, etc...)

	public Expert(String name, String field) {
		this.name = name;
		this.secondField = field;
	}

	@Override
	public String print() {
		return this.name + this.secondField + "\n";
	}
	
	

}
