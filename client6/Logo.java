package application;

import java.io.IOException;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class Logo {

	public void show() throws IOException {
				
		Stage stage = new Stage();
		
		Parent root = FXMLLoader.load(getClass().getResource("logo.fxml"));
		
		// FXMLLoader loader = new 
		
		
		//loader.setLocation(location);
		//loader.setBuilderFactory(new JavaFXBuilderFactory());
								// loader.load();
		

		stage.setTitle("Server's Info");
				
		// setting controller for the scene:

	// 	loader.setController(new LogoController());				
		//root = (Parent) loader.load();
				
		Scene scene = new Scene(root, 300, 250);		
		scene.getStylesheets().add(getClass().getResource("LogoDefinition.css").toExternalForm());

		stage.initModality(Modality.APPLICATION_MODAL);
		stage.setScene(scene);

		// setting initial server's ip and port:		
	
		stage.show();

	}

}
