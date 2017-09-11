package application;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class LogoController {

	@FXML
	BorderPane border;

	@FXML
	Button exit;

	@FXML
	Button save;

	@FXML
	TextField textIp;

	@FXML
	TextField textPort;

	// ********************** LOCAL CLASSES WHICH ARE
	// THREADS**********************

	// ******************* MainController class logic: *************************

	@FXML
	void initialize() {

		initialText();
		quit();
		save();

	}

	public void initialText() {
		ConnectInfo con = ConnectInfo.getInstance();

		System.out.println(con.getIp());

		textIp.setText(con.getIp());
		textPort.setText(Integer.toString(con.getPort()));

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

	public void save() {

		save.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {

				ConnectInfo con = ConnectInfo.getInstance();

				if (!textIp.getText().equals(con.getIp())) {
					con.setIp(textIp.getText());
				}

				if (!textPort.getText().equals(Integer.toString(con.getPort()))) {
					con.setPort(Integer.parseInt(textPort.getText()));
				}

				if (con.isSocketChanged() && con.isConnected()) {
					con.closeSocket();// will close only
				}

				if (!con.isConnected()) {
					con.setConnection();
				}

				System.out.println(con.getConnection().getSocket());
				Stage stage = (Stage) save.getScene().getWindow();
				stage.close();

			}

		});

	}

}
