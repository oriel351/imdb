package application;

import java.util.ArrayList;
import java.util.List;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class ProController {

	private List<TextField> fields;
	private List<String> movies;
	private boolean hasMovie;
	private boolean hasMessage;
	private int moviesCounter;
	private String type;
	private String gender;

	@FXML
	Label message;

	@FXML
	Button discard;

	@FXML
	TextField id;

	@FXML
	TextField name;

	@FXML
	TextField age;

	@FXML
	TextField description;

	@FXML
	MenuItem actor;

	@FXML
	MenuItem producer;

	@FXML
	MenuItem screenwriter;

	@FXML
	MenuItem director;

	@FXML
	MenuItem man;

	@FXML
	MenuItem woman;

	@FXML
	TextField movie0;

	@FXML
	TextField movie1;

	@FXML
	TextField movie2;

	@FXML
	VBox moviesPlace;

	@FXML
	Button addMovie;

	@FXML
	HBox misdetail;

	@FXML
	VBox whereNewField;
	@FXML
	Button submit;

	public ProController() {

		this.fields = new ArrayList<TextField>();
		this.movies = new ArrayList<String>();
		this.hasMovie = false;
		this.hasMessage = false;
		this.moviesCounter = 0;
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
		actor();
		screenwriter();
		producer();
		director();
		man();
		woman();

	}

	// if clicked "actor" set the type to actor's type =01;
	private void actor() {
		actor.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				type = "1";

			}

		});

	}

	// if clicked "director" set the type to director's type =01;
	private void director() {
		director.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				type = "0";

			}

		});

	}

	// if clicked "screenwriter" set the type to screenwriter's type =2;
	private void screenwriter() {
		screenwriter.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				type = "2";

			}

		});

	}

	// if clicked "producer" set the type to producer's type =3;
	private void producer() {
		producer.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				type = "3";

			}

		});

	}

	// if clicked "woman" set the gender to female;
	private void woman() {
		woman.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				gender = "female";

			}

		});

	}

	// if clicked "man" set the gender to male;
	private void man() {
		man.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				gender = "male";

			}

		});

	}

	public void quit() {

		discard.setOnMouseClicked(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {

				Stage stage = (Stage) discard.getScene().getWindow();
				stage.close();

			} // END OF HANDLE
		});
	}

	private void addTextField() {

		addMovie.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				/**
				 * first time we take the movie name from the field was there
				 * already. next times we take it each time from the last
				 * element in fields list.
				 */
				TextField newField = new TextField();
				fields.add(newField);
				whereNewField.getChildren().add(newField);
				if (!hasMovie) {
					movies.add(movie0.getText());
					hasMovie = true;

				} else {
					movies.add(fields.get(moviesCounter).getText());
					moviesCounter++;
				}

			}

		});

	}

	private void addAction() {

		submit.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				ConnectInfo con = ConnectInfo.getInstance();

				/**
				 * first we check all field entered correctly.
				 */
				if (id.getText().isEmpty() || name.getText().isEmpty() || age.getText().isEmpty()

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

					String command = "2" + " " + type + " " + id.getText() + " " + age.getText() + " "

							+ description.getText() + " " + gender + " " + name.getText();
					try {
						System.out.println(con.getConnection().getSocket());
						con.getConnection().dataSend(command);
					} catch (Exception e) {
						System.out.println("Could not send info to server");
					}
				}

				if (con.getConnection().dataReceive().equals("Success")) {
					for (int i = 0; i < movies.size(); i++) {
						con.getConnection().dataSend("4" + " " + id.getText() + " " + movies.get(i));
						con.getConnection().dataReceive();
					}
				}
				// close the window:
				((Stage) discard.getScene().getWindow()).close();
				;

			}

		});

	}

}