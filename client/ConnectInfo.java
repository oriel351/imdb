package application;

/**
 * 
 * this class handles the information to contact the server.
 *
 */
public class ConnectInfo {
	private static final String default_ip = "127.0.0.1";
	private static final int default_port = 5555;

	private static String ip;
	private static int port;
	private static boolean changed;
	private static boolean connected;
	private static ClientTcp connection;

	private ConnectInfo() {
		ConnectInfo.ip = default_ip;
		ConnectInfo.port = default_port;
	}

	public String getIp() {
		return ConnectInfo.ip;
	}

	public int getPort() {
		return ConnectInfo.port;
	}

	public void setIp(String ip) {
		ConnectInfo.ip = ip;
		ConnectInfo.changed = true;
	}

	public void setPort(int port) {
		ConnectInfo.port = port;
		ConnectInfo.changed = true;
	}

	public ClientTcp getConnection() {
		return ConnectInfo.connection;
	}

	public void setConnection() {

		ConnectInfo.connection = new ClientTcp(ConnectInfo.ip, ConnectInfo.port);
		if (ConnectInfo.connection.hasCreated()) {
			ConnectInfo.connected = true; // marking as connected
			ConnectInfo.changed = false; // renewing mark as unchanged
											// connection (
											// beause its ne socket !)
		}

	}

	public void closeSocket() {
		if (ConnectInfo.connection != null) {
			if (connection.getSocket() != null) {
				ConnectInfo.connection.close();
				ConnectInfo.connected = false;
			}
		}

	}

	public boolean isConnected() {
		return ConnectInfo.connected;
	}

	public boolean isSocketChanged() {
		return ConnectInfo.changed;
	}

	private static class InfoHolder {
		private final static ConnectInfo instance = new ConnectInfo();

	}

	public static ConnectInfo getInstance() {

		return InfoHolder.instance;

	}
}
