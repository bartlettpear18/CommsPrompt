
import java.io.IOException;

public class Tester2 {

    public static void main(String[] args) {
        Client client = new Client("127.0.0.1");
        String a = "client to server";
        byte[] test = a.getBytes();

        try {
            client.init();
            client.send(test);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException ex)
            {
                Thread.currentThread().interrupt();
            }
            client.send(test);
            // client.read();
        } catch (IOException e) {
            System.out.println("Error2");
        }
        System.out.println("done2");
    }


}
