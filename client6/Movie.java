package application;

public class Movie implements Printable {

	private String name;
	private String length;
	private String year;
	private String rank;
	private String imageLink;
	private String description;

	public Movie(String name, String length, String year, String rank, String imageLink, String description) {

		this.name = name;
		this.length = length;
		this.year = year;
		this.rank = rank;
		this.imageLink = imageLink;
		this.description = description;
	}

	@Override
	public String print() {
		// TODO Auto-generated method stub
		return null;
	}

	public String getName() {
		return name;
	}

	public String getLength() {
		return length;
	}

	public String getYear() {
		return year;
	}

	public String getRank() {
		return rank;
	}

	public String getImageLink() {
		return imageLink;
	}

	public String getDescription() {
		return description;
	}

}
