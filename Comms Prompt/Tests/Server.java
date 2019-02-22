import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Base64;

public class Server {
    private final int PORT = 5000;
    private ServerSocket server;
    private Socket socket;

    private DataInputStream input;
    private DataOutputStream output;

    public Server() {}

    public void init() {
        try {
            server = new ServerSocket(PORT);
            socket = server.accept();

            output = new DataOutputStream(socket.getOutputStream());
            input = new DataInputStream(socket.getInputStream());

            System.out.println("Connection bound");
        } catch (IOException e) {
            System.out.println("IO Error");
        }
    }

    public String read() {
        try {
            byte[] buffer = new byte[100];
            input.read(buffer);
            return new String(buffer);
        } catch (IOException e) {
            System.out.println("Read error");
        }
        return null;
    }

    public void send(String msg) {
        try {
            output.write(msg.getBytes());
            output.flush();
        } catch (IOException e) {
            System.out.println("Send error");
        }
    }


}
