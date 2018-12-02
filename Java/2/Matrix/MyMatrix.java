import java.util.*;

public class MyMatrix {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input the row: ");
		int row = sc.nextInt();
		System.out.print("Input the column: ");
		int column = sc.nextInt();
		System.out.println("Input the matrix: ");
		double[][] mat = new double[row][column];
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				mat[i][j] = sc.nextInt();
			}
		}
		Matrix m = new Matrix();
		m.SetMatrix(row, column);
		System.out.println("The total: "+m.Summatrix(mat));
		System.out.println("After transation: ");
		double[][] nmat = m.TransMatrix(mat);
		for(int i = 0; i < column; i++)
		{
			for(int j = 0; j < row; j++)
			{
				System.out.print(nmat[i][j]+"\t");
			}
			System.out.println();
		}
	}
}
class Matrix 
{
	private static int row, column;
	private double[][] matrix;
	public void SetMatrix(int r, int c)
	{
		row = r;
		column = c;
	}
	public static double Summatrix(double [][]m)
	{
		double tot = 0;
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				tot += m[i][j];
			}
		}
		return tot;
	}
	public static double[][] TransMatrix(double [][]m)
	{
		double[][] nextm = new double[column][row];
		for(int i = 0; i < column; i++)
		{
			for(int j = 0; j < row; j++)
			{
				nextm[i][j] = m[j][i];
			}
		}
		return nextm;
	}
}