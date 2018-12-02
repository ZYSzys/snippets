import java.net.InetAddress;

public class GetLocal {
	public static void main(String[] args) throws Exception{
		InetAddress addr = InetAddress.getLocalHost();
		System.out.println("Local HostAddress: " + addr.getHostAddress());
		System.out.println("Local HostName: " + addr.getHostName());
	}
}