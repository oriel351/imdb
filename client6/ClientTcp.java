package application;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class ClientTcp {

	private Socket socket;
	private String ip;
	private int port;
	private boolean created;

	public PrintWriter out;
	public BufferedReader in;

	public ClientTcp(String ip, int port) {
		this.ip = ip;
		this.port = port;
		this.created = openSocket();
	}

	public boolean openSocket() {

		try {
			this.socket = new Socket(this.ip, this.port);
			this.out = new PrintWriter(this.socket.getOutputStream(), true);
			this.in = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
			return true;

		} catch (UnknownHostException e) {
			System.out.println("wrong socket or ip number");
			return false;
		} catch (IOException e) {
			System.out.println("could not connect to socket (inside TCP client)");
			return false;
		}
	}

	public void dataSend(String data) {

		char[] c = data.toCharArray();

		System.out.println(c);
		this.out.print(c);
		this.out.flush();
	}

	public String dataReceive() {

		char[] c = new char[4096];
		String sub = "";
		try {
			int num = this.in.read(c);
			String t = new String(c);
			sub = t.substring(0, num);

		} catch (IOException e) {
			System.out.println("coul not read data from server ( in TCP client)");
		}

		return sub;

	}

	public Socket getSocket() {
		return this.socket;
	}

	public boolean hasCreated() {
		return this.created;
	}

	public void close() {
		try {
			this.socket.close();
		} catch (IOException e) {
			System.out.println("could not close socket. probably connection \n was refused");
		} finally {
			System.out.println("could not close socket. probably connection \n was refused");

		}
	}

}
