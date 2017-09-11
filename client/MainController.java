package application;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.Side;
import javafx.scene.control.Button;
import javafx.scene.control.ContextMenu;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SplitMenuButton;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.util.Callback;

public class MainController {

	private List<Printable> toShow;

	public MainController() {

		this.toShow = new ArrayList<Printable>();

	}

	@FXML
	BorderPane border;

	@FXML
	Button connection;

	@FXML
	TextField text;

	@FXML
	SplitMenuButton split;

	@FXML
	Button search;

	@FXML
	Button remove;

	@FXML
	Button add;

	@FXML
	Button all;

	@FXML
	ContextMenu addMenu;

	@FXML
	MenuItem addMovie;

	@FXML
	MenuItem addProf;

	@FXML
	ContextMenu removeMenu;

	@FXML
	MenuItem remMovie;

	@FXML
	MenuItem remProf;

	@FXML
	ContextMenu allMenu;

	@FXML
	MenuItem allMovies;

	@FXML
	MenuItem allProf;

	@FXML
	MenuItem allGenr;

	@FXML
	ListView results;

	// ********************** LOCAL CLASSES WHICH ARE
	// THREADS**********************

	/**
	 * local classes used for threads:
	 */
	public class SetConnectionThread extends Thread {

		@Override
		public void run() {

			// Platform.runLater(new Runnable() {

			// @Override
			// public void run() {
			// Logo a = new Logo();
			// try {
			// a.show();
			// } catch (IOException e) {
			// TODO Auto-generated catch block
			//// e.printStackTrace();
			// }

			// }

			// });

		}

	}

	// ******************* MainController class logic: *************************

	@FXML
	void initialize() {

		setConnection();
		addMenu();
		addMovie();
		removeMenu();
		allMenu();
		addProf();
		allMovies();

	}

	private void allMovies() {

		allMovies.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				showResults();

			}

		});

	}

	@SuppressWarnings({ "unused", "unchecked", "rawtypes" })
	private void showResults() {

		this.toShow.add(new Movie("batman", "127", "1989", "8.9", "http://www.google.co.il", "description"));

		results.getItems().addAll(this.toShow);
		results.setCellFactory(new Callback<ListView, ListCell>() {

			@SuppressWarnings("rawtypes")
			@Override
			public ListCell call(ListView param) {
				return new MylistCell();
			}

		});

	}

	private void addMenu() {
		add.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				addMenu.show(add, Side.BOTTOM, 0, 0);
				/*
				 * AddMovie a = new AddMovie(); try { a.show(); } catch
				 * (IOException e) { System.out.println(
				 * "Failed open add movie window"); }
				 */
			}

		});
	}

	private void allMenu() {
		all.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				allMenu.show(all, Side.BOTTOM, 0, 0);
			}

		});
	}

	private void removeMenu() {
		remove.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				removeMenu.show(remove, Side.BOTTOM, 0, 0);
			}

		});
	}

	private void addMovie() {
		addMovie.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				AddMovie a = new AddMovie();
				try {
					a.show();

				} catch (IOException e) {
					System.out.println("Failed open add movie window");
				}

			}

		});

	}

	private void addProf() {
		addProf.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {

				AddPro a = new AddPro();
				try {
					a.show();
				} catch (IOException e) {
					e.printStackTrace();
					//System.out.println("Failed open add professional window");
				}

			}

		});

	}

	private void setConnection() {

		connection.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				// showing the server connection window:
				Logo a = new Logo();
				try {
					a.show();

				} catch (IOException e) {
					System.out.println("problem with connection file");
					e.printStackTrace();
				} catch (Exception e) {
					System.out.println("problem with connection file");

				}
			} // END OF HANDLE
		});
	}

} // END OF main controller class