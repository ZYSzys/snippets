import java.util.*;

public class NumberCount {
	public static void main(String[] args) {
		int N = 101;
		int[] a = new int[N];
		Arrays.fill(a, 0);

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n != 0)
		{
			if(n > 100)
			{
				System.out.println("Wrong Input.Retry !");
				break;
			}
			a[n]++;
			n = sc.nextInt();
		}
		for(int i = 1; i < N; i++)
		{
			if(a[i] == 0)
				continue;
			System.out.println("The number "+i+" appears "+a[i]+" times");
		}
	}
}