import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {

    //Server variables
    private static Socket socket;
    private static int port = 5000;
    private static String hostIP;

    //Stream variables
    private DataInputStream input = null;
    private DataOutputStream output = null;

    //Zero-parameter constructor
    public Client() {}

    //Initialize hostIP constructor
    public Client(String ip)  { hostIP = ip; }

    //Socket methods
    public boolean init() throws IOException {
        socket = new Socket(hostIP, port);
        output = new DataOutputStream(socket.getOutputStream());
        input = new DataInputStream(socket.getInputStream());
        return socket.isConnected();
    }

    public void close() throws IOException {
        output.flush();
        output.close();
        input.close();
    }

    public void send(byte[] packet) throws IOException {
        output.write(packet);
        output.flush();
    }

    public byte[] read() throws  IOException {
        byte[] b = new byte[20];
        input.read(b);
        String s = new String(b);
        System.out.println(s);
        // for(byte a : b) System.out.println(a);
        return b;
    }

}
