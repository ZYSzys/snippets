import java.util.Scanner;
import java.lang.Math;

public class MyTriangle{
	public static void main(String[] args) {
		System.out.print("Input three length: ");
		Scanner scan = new Scanner(System.in);
		double la = scan.nextDouble();
		double lb = scan.nextDouble();
		double lc = scan.nextDouble();
		Triangle tri = new Triangle();
		if(tri.isValid(la, lb, lc))
		{
			tri.SetLength(la, lb, lc);
			System.out.println("It can be a triangle!\nThe area is: "+tri.area(la, lb, lc));
		}
		else
		{
			System.out.println("It can not construct a triangle!");
		}
	}
}
class Triangle
{
	private double a, b, c;
	private double area;
	public static boolean isValid(double la, double lb, double lc)
	{
		if((la + lb > lc) && (lb + lc) > la && (la + lc) > lb)
		{
			return true;
		}
		return false;
	}
	public static double area(double la, double lb, double lc)
	{
		double p =(la + lb + lc) / 2;
		double ss = p*(p-la)*(p-lb)*(p-lc);
		double s = Math.sqrt(ss);
		return s;
	}
	public void SetLength(double la, double lb, double lc)
	{
		this.a = la;
		this.b = lb;
		this.c = lc;
		this.area = this.area(la, lb, lc);
	}
}