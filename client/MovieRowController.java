package application;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;

public class MovieRowController implements RowController {

	private Printable item;

	@FXML
	TextArea tt;

	@FXML
	Label name;

	public MovieRowController(Printable item) {
		this.item = item;
	}

	@Override
	@FXML
	public void initialize() {

		Movie a = (Movie) item;
		name.setText(a.getName());
	}
}
