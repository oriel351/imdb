package application;

import java.util.ArrayList;
import java.util.List;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class AddMovieController {

	private List<TextField> fields;
	private List<String> genres;
	private boolean hasGenre;
	private boolean hasMessage;
	private int genresCounter;

	Label message;

	@FXML
	Button exit;

	@FXML
	TextField code;

	@FXML
	TextField name;

	@FXML
	TextField length;

	@FXML
	TextField year;

	@FXML
	Slider rank;

	@FXML
	TextField imageLink;

	@FXML
	TextField description;

	@FXML
	TextField addFirstGenre;

	@FXML
	VBox genresPlace;
	@FXML
	Button addGenre;

	@FXML
	HBox misdetail;
	@FXML
	Button addMovie;

	public AddMovieController() {
		this.fields = new ArrayList<TextField>();
		this.genres = new ArrayList<String>();
		this.hasGenre = false;
		this.hasMessage = false;
		this.genresCounter = 0;
		this.message = new Label();

		this.message.setText("one detail or more is missing!!");

	}

	// ********************** LOCAL CLASSES WHICH ARE
	// THREADS**********************

	// ******************* MainController class logic: *************************

	@FXML
	void initialize() {

		quit();
		addTextField();
		addAction();

	}

	public void quit() {
		System.out.println("asssssss");
		exit.setOnMouseClicked(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {

				Stage stage = (Stage) exit.getScene().getWindow();
				stage.close();

			} // END OF HANDLE
		});
	}

	private void addTextField() {

		addGenre.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				/**
				 * first time we take the igenre name from the field was there
				 * already. next times we take it each time from the last
				 * element in fields list.
				 */
				TextField newField = new TextField();
				fields.add(newField);
				genresPlace.getChildren().add(newField);
				if (!hasGenre) {
					genres.add(addFirstGenre.getText());
					hasGenre = true;

				} else {
					genres.add(fields.get(genresCounter).getText());
					genresCounter++;
				}

			}

		});

	}

	private void addAction() {

		addMovie.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				ConnectInfo con = ConnectInfo.getInstance();

				System.out.println(con.getConnection().getSocket());
				/**
				 * first we check all field entered correctly.
				 */
				if (code.getText().isEmpty() || name.getText().isEmpty() || length.getText().isEmpty()
						|| year.getText().isEmpty() || imageLink.getText().isEmpty()
						|| description.getText().isEmpty()) {

					if (!hasMessage) { // only first press we need to add the
										// label.
						misdetail.getChildren().add(message);
						hasMessage = false;
					}

				} else {
					/**
					 * only now we can build the correct string and send as
					 * command to the server.
					 */
					String command = "1" + " " + code.getText() + " " + name.getText() + " " + length.getText() + " "
							+ year.getText() + " " + Double.toString(rank.getValue()) + " " + imageLink.getText() + " "
							+ description.getText();
					try {
						System.out.println(con.getConnection().getSocket());
						con.getConnection().dataSend(command);
					} catch (Exception e) {
						System.out.println("Could not send info to server");
					}
				}

				String t = con.getConnection().dataReceive();

				if (t.equals("Success")) {
					for (int i = 0; i < genres.size(); i++) {
						String toSend = "4" + " " + code.getText() + " " + genres.get(i);
						con.getConnection().dataSend(toSend);
						System.out.println(con.getConnection().dataReceive());
					}
				}
				// close the window:
				((Stage) exit.getScene().getWindow()).close();
				;

			}

		});

	}

}
