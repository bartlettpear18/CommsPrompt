import java.io.IOException;
import java.util.Scanner;

public class ServerTester {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Server server = new Server();
        server.init();

        Thread sender = new Thread(new Runnable() {
            public void run() {
                while(true) {
                    if(scan.hasNextLine()) {
                        server.send(scan.nextLine());
                    }
                }
            }
        });

        Thread reader = new Thread(new Runnable() {
            public void run() {
                while(true){
                    System.out.println(server.read());
                }
            }
        });

        sender.start();
        reader.start();
    }
}
