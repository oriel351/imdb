package application;

import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws IOException {

		Parent root = FXMLLoader.load(getClass().getResource("gui_def.fxml"));
		
		Scene scene = new Scene(root, 825, 400);
		scene.getStylesheets().add(getClass().getResource("gui_def.css").toExternalForm());
		
		primaryStage.setTitle("Movies Box");	
		primaryStage.setScene(scene);		
		primaryStage.show();

	}

	public static void main(String[] args) {
		launch(args);
	}
}
