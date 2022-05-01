import java.util.Scanner;

public class Q8 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String str1 = input.nextLine();
		String [] str2 = str1.split(" ");
		int M = 0, N = 0;
		for (int i = 0; i < str2[0].length(); i++)
			for (int j = 0; j < str2[0].length(); j++)
			{
				if (str2[0].charAt(i) == str2[1].charAt(j) && i == j) 
					M++;
				else if (str2[0].charAt(i) == str2[1].charAt(j))
					N++;
			}
		System.out.print(M + " " + N);	
		input.close();
	}
}