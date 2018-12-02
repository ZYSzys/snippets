import java.util.*;
import java.lang.Math;
public class Grade_1{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("The total number of students: ");
		int n = sc.nextInt();
		Grade[] g = new Grade[n];
		double m = 0;
		for(int i = 0; i < n; i++)
		{
			g[i] = new Grade();
			System.out.print("Input the number of Student "+(i+1)+": ");
			double num = sc.nextDouble();
			g[i].SetNumber(num);
			m = Math.max(m, num);
		}
		for(int i = 0; i < n; i++)
		{
			g[i].SetGrade(m);
			System.out.println("The grade of Student "+(i+1)+": "+g[i].GetGrade());
		}
	}
}
class Grade
{
	private double number;
	private char grade;
	public void SetNumber(double n)
	{
		this.number = n;
	}
	public void SetGrade(double cmp)
	{
		if(this.number >= cmp-10)
		{
			this.grade = 'A';
		}
		else if(this.number >= cmp-20)
		{
			this.grade = 'B';
		}
		else if(this.number >= cmp-30)
		{
			this.grade = 'C';
		}
		else if(this.number >= cmp-40)
		{
			this.grade = 'D';
		}
		else
		{
			this.grade = 'F';
		}
	}
	public double GetNumber()
	{
		return this.number;
	}
	public char GetGrade()
	{
		return this.grade;
	}
}
