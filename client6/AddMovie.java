package application;

import java.io.IOException;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class AddMovie {

	public void show() throws IOException {

		Stage stage = new Stage();

		Parent root = FXMLLoader.load(getClass().getResource("addMovie.fxml"));

		// FXMLLoader loader = new

		// loader.setLocation(location);
		// loader.setBuilderFactory(new JavaFXBuilderFactory());
		// loader.load();

		stage.setTitle("Add movie");

		// setting controller for the scene:

		// loader.setController(new LogoController());
		// root = (Parent) loader.load();

		Scene scene = new Scene(root, 350, 600);
		scene.getStylesheets().add(getClass().getResource("gui_def.css").toExternalForm());

		stage.initModality(Modality.APPLICATION_MODAL);
		stage.setScene(scene);

		// setting initial server's ip and port:

		stage.show();

	}

}
