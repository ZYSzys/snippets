import java.net.*;
import java.io.*;

public class WebPing {
	public static void main(String[] args) {
		try {
			InetAddress addr;
			Socket sock = new Socket("zyszys.github.io", 80);
			addr = sock.getInetAddress();
			System.out.println("Connecting to " + addr);
			sock.close();
		}catch(Exception e)
		{
			System.out.println("Cannot connect to " + args[0]);
			System.out.println(e);
		}
	}
}