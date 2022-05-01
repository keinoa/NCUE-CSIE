import java.util.Scanner;

public class Q13 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int row = input.nextInt();
		int column = input.nextInt();
		int [][] arr = new int[100][100];
		int [][] tmp = new int[100][100];		
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				arr[i][j] = input.nextInt();
		for (int i = 0; i < column; i++)
			for (int j = 0; j < row; j++)
				tmp[i][j] = arr[j][i];
		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
				System.out.print(tmp[i][j] + " ");
			System.out.println("");
		}
		input.close();
	}	
}