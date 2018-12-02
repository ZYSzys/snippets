/*
import java.net.InetAddress;
import java.net.UnknownHostException;
 
public class GetIP {
    public static void main(String[] args) {
        InetAddress address = null;
        try {
            address = InetAddress.getByName("zyszys.github.io");
        }
        catch (UnknownHostException e) {
            System.exit(2);
        }
        System.out.println(address.getHostName() + "=" + address.getHostAddress());
        System.exit(0);
    }
}
*/


import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.*;

public class GetIP{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        InetAddress address = null;
        try{
            address = InetAddress.getByName(str);
        }
        catch(UnknownHostException e)
        {
            System.exit(2);
        }
        System.out.println(address.getHostName() + " = " + address.getHostAddress());
        System.exit(0);
    }
}