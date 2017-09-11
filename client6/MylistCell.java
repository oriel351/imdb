package application;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.ListCell;

public class MylistCell extends ListCell<Printable> {

	@Override
	protected void updateItem(Printable item, boolean empty) {

		super.updateItem(item, empty);

		if (item != null) {

			RowController control = null;

			FXMLLoader loader = null;

			if (item instanceof Movie) {
				control = new MovieRowController(item);
				try {
					loader = new FXMLLoader(getClass().getResource("movieRow.fxml"));
				} catch (Exception e) {
					System.out.println("cant load fxml file");
				}

			} else {

			}

			loader.setController(control);

			Parent root = null;
			try {
				root = loader.load();
			} catch (Exception e) {
				System.out.println("problem with movie row controller file");
			}

		}

	}

}
