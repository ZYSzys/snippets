import java.net.*;
import java.io.*;

public class ChatClient {
    private DatagramSocket s;
    private InetAddress hostAddress;
    private byte[] buf = new byte[1000];
    private DatagramPacket dp = new DatagramPacket(buf, buf.length);

    public ChatClient() {
        try {
            s = new DatagramSocket();
            hostAddress = InetAddress.getByName("localhost");
            System.out.println("Client start.........");
            while(true)
            {
                String outMessage = "";
                BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
                try {
                    outMessage = stdin.readLine();
                }catch (IOException ie) {
                    System.err.println("IO error!");
                }

                System.out.println("One line Done");

                if(outMessage.equals("bye")) break;
                String outString = "Client says: " + outMessage;
                byte[] buf = outString.getBytes();

                DatagramPacket out = new DatagramPacket(buf, buf.length, hostAddress, ChatServer.PORT);
                s.send(out);

                s.receive(dp);
                String rcvd = "rcvd from " + dp.getAddress() + ", " + dp.getPort() + ": " + new String(dp.getData(), 0, dp.getLength());
                System.out.println(rcvd);
            }
        }catch (UnknownHostException e) {
            System.out.println("Unknown----Can't open socket");
            System.exit(1);
        }catch (SocketException e) {
            System.out.println("SocketE----Can't open socket");
            e.printStackTrace();
            System.exit(1);
        }catch (IOException e) {
            System.err.println("IOE-----Communication error");
            e.printStackTrace();
            System.exit(1);
        }catch (Exception e) {
            System.err.println("Communication error");
            e.printStackTrace();
            System.exit(1);
        }
        System.out.println("ChatClient over");
    }

    public static void main(String[] args){
        new ChatClient();
    }
}
