import sun.tools.asm.CatchData;

import javax.sound.midi.SysexMessage;
import java.net.*;
import java.io.*;
import java.util.*;

public class ChatServer {
    static final int PORT = 5000;
    private byte[] buf = new byte[1000];
    private DatagramPacket dgp = new DatagramPacket(buf, buf.length);
    private DatagramSocket sk;

    public ChatServer() {
        try {
            sk = new DatagramSocket(PORT);
            System.out.println("Server start.........");
            while (true) {
                sk.receive(dgp);
                String rcvd = new String(dgp.getData(),0,dgp.getLength())+", from address: " + dgp.getAddress() + ", port: " + dgp.getPort();
                System.out.println(rcvd);
                String outMessage = "";
                BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
                try {
                    outMessage = stdin.readLine();
                }catch (IOException ie) {
                    System.err.println("IO error!");
                }
                String outString = "Server say: " + outMessage;
                byte[] buf = outString.getBytes();
                DatagramPacket out = new DatagramPacket(buf, buf.length, dgp.getAddress(), dgp.getPort());
                sk.send(out);
            }
        }catch (SocketException e) {
            System.err.println("Can't open socket");
            System.exit(1);
        }catch (IOException e) {
            System.err.println("Communication error");
            e.printStackTrace();
            System.exit(1);
        }
    }
    public static void main(String[] args)
    {
        new ChatServer();
    }

}
