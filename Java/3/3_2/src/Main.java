import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input the number of students: ");
        int n = sc.nextInt();
        Stu[] student = new Stu[n];
        for(int i = 0; i < n; i++)
        {
            System.out.print("Input name: ");
            String name = sc.next();
            System.out.print("Input num: ");
            int num = sc.nextInt();
            System.out.print("Input sex: ");
            char sex = sc.next().charAt(0);
            System.out.print("Input three grades: ");
            double sub1 = sc.nextDouble(), sub2 = sc.nextDouble(), sub3= sc.nextDouble();
            System.out.print("Input three points: ");
            double gra1 = sc.nextDouble(), gra2 = sc.nextDouble(),gra3 = sc.nextDouble();
            student[i] = new Stu(name,num,sex,sub1,sub2,sub3,gra1,gra2,gra3);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(student[i].tot < student[j].tot)
                {
                    Stu tmp = student[i];
                    student[i] = student[j];
                    student[j] = tmp;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            student[i].Display();
        }
    }

}
class Stu {
    String name;
    int num;
    char sex;
    double sub1, sub2, sub3;
    double gra1, gra2, gra3;
    public double tot;

    Stu(String name, int num, char sex, double sub1, double sub2, double sub3, double gra1, double gra2, double gra3) {
        this.name = name;
        this.num = num;
        this.sex = sex;
        this.sub1 = sub1;
        this.sub2 = sub2;
        this.sub3 = sub3;
        this.gra1 = gra1;
        this.gra2 = gra2;
        this.gra3 = gra3;
        this.tot = sub1 * gra1 + sub2 * gra2 + sub3 * gra3;
    }

    public void Display() {
        System.out.println("Name: "+name+"\tNumber: "+num+"\tSex: "+sex+"\tTot: "+tot);
    }
}