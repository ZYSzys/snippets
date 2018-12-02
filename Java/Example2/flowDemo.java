import java.util.*;

public class flowDemo {
	public static void main(String[] args) {
		int iPara1 = 0, iPara2 = 0, iEnd = 0;

		if(args.length != 3)
		{
			System.out.println("USE: java flowDemo parameter1 parameter2 circle");
			System.out.println("parameter1: compare condition1, int type");
			System.out.println("parameter2: compare condition2, int type");
			System.out.println("circle: circulation times");
			System.out.println("ego: java flowDemo 1 2 5");
		}else{
			iPara1 = Integer.parseInt(args[0]);
			iPara2 = Integer.parseInt(args[1]);
			iEnd = Integer.parseInt(args[2]);
		}

		if(iPara1 < iPara2)
		{
			System.out.println("if condition satified!");
			System.out.println("First number < Second number.");
		}else {
			System.out.println("if condition didn't satify!");
			System.out.println("First number >= Second number.");
		}

		for (int i = 0; i < iEnd; i++) {
			System.out.println("This is circulation "+i);
		}
	}
}