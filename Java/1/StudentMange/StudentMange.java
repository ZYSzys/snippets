import java.util.Scanner;
public class StudentMange
{
	public static void main(String[] args) 
	{
		System.out.println("Welcome, there are operations: ");
		Student stud = new Student();
		Scanner scan = new Scanner(System.in);
		while(true)
		{
			boolean flag = true;
			System.out.print("1.Input student messages\t2.Delete score\t3.Show all messags\t4.Quit\nInput your choice(1/2/3/4): ");
			int choice = scan.nextInt();
			switch(choice)
			{
				case 1:
				System.out.print("Input id: ");
				String id = scan.next();
				System.out.print("Input name: ");
				String name = scan.next();
				System.out.print("Input sex: ");
				char sex = scan.next().charAt(0);
				System.out.print("Input age: ");
				int age = scan.nextInt();
				System.out.print("Input ComputerScore: ");
				double cs = scan.nextDouble();
				System.out.print("Input EnglishScore: ");
				double es = scan.nextDouble();
				System.out.print("Input MathScore: ");
				double ms = scan.nextDouble();
				stud.setId(id);
				stud.setName(name);
				stud.setSex(sex);
				stud.setAge(age);
				stud.setComputerScore(cs);
				stud.setEnglishScore(es);
				stud.setMathScore(ms);
				stud.setTotalCreditAndAveScore();
				break;
				case 2:
				System.out.print("1.Delete computerScore\t2.Delete englishScore\t3.Delete mathScore\nInput your option(1/2/3): ");
				Scanner sc = new Scanner(System.in);
				int option = sc.nextInt();
				switch(option)
				{
					case 1:stud.DeleteComputer();break;
					case 2:stud.DeleteEngilsh();break;
					case 3:stud.DeleteMath();break;
				}
				break;
				case 3:
				stud.showTotalMessage();break;
				case 4:
				flag = false;
				break;
				default:
				System.out.println("No such an operation!Try again!");
			}
			if(!flag)
			{
				System.out.println("Bye");
				break;
			}
		}
	}
}
class Student
{
	private String id;
	private String name;
	private char sex;
	private int age;
	private double computerScore, englishScore, mathScore, totalCredit, aveScore;
	public String getId()
	{
		return this.id;
	}
	public String getname()
	{
		return this.name;
	}
	public char getsex()
	{
		return this.sex;
	}
	public int getage()
	{
		return this.age;
	}
	public double getComputerScore()
	{
		return this.computerScore;
	}
	public double getMathScore()
	{
		return this.mathScore;
	}
	public double getEnglishScore()
	{
		return this.englishScore;
	}
	public void setId(String id)
	{
		this.id = id;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public void setSex(char sex)
	{
		this.sex = sex;
	}
	public void setAge(int age)
	{
		this.age = age;
	}
	public void setComputerScore(double s)
	{
		this.computerScore = s;
	}
	public void setEnglishScore(double s)
	{
		this.englishScore = s;
	}
	public void setMathScore(double s)
	{
		this.mathScore = s;
	}
	public void DeleteComputer()
	{
		this.computerScore = 0;
		this.setTotalCreditAndAveScore();
	}
	public void DeleteEngilsh()
	{
		this.englishScore = 0;
		this.setTotalCreditAndAveScore();
	}
	public void DeleteMath()
	{
		this.mathScore = 0;
		this.setTotalCreditAndAveScore();
	}
	public void setTotalCreditAndAveScore()
	{
		double total = 0;
		double score = this.computerScore+this.englishScore+this.mathScore;
		int cnt = 3;
		if(this.computerScore >= 90)
			total += 2;
		else if(this.computerScore >= 60)
			total += 1.5;
		else if(this.computerScore == 0)
			cnt -= 1;
		if(this.englishScore >= 90)
			total += 2;
		else if(this.englishScore >= 60)
			total += 1.5;
		else if(this.englishScore == 0)
			cnt -= 1;
		if(this.mathScore >= 90)
			total += 2;
		else if(this.mathScore >= 60)
			total += 1.5;
		else if(this.mathScore == 0)
			cnt -= 1;
		this.totalCredit = total;
		if(cnt != 0)
			this.aveScore = score / cnt;
		else
			this.aveScore = 0;
		
	}
	public void showTotalMessage()
	{
		System.out.println("All Messages: ");
		System.out.println("Id: "+this.id);
		System.out.println("Name: "+this.name);
		System.out.println("Sex: "+this.sex);
		System.out.println("Age: "+this.age);
		System.out.println("ComputerScore: "+this.computerScore);
		System.out.println("EnglishScore: "+this.englishScore);
		System.out.println("MathScore: "+this.mathScore);
		System.out.println("TotalCredit: "+this.totalCredit);
		System.out.println("AveScore: "+String.format("%.1f", this.aveScore));
	}
}





