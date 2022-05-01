import java.util.Scanner;

public class Q11 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int light = input.nextInt();
		int person_num = input.nextInt();
		short [] cmp = new short[1024]; 
		for (int i = light; i > 0; i--)
			cmp[i] = -1;
		for (int i = person_num; i > 0; i--)
		{
			if (i != 1)
				for (int j = light; j > 0; j--)
				{
					if(j <= 0)
						break;
					if (j % i == 0)
						cmp[j] *= -1;
				}
			else
				for (int j = light; j > 0; j--)
					cmp[j] *= -1;
		}
		for (int i = 1; i <= light; i++)
		{
			if(cmp[i] != -1)
				System.out.print(i + " ");
		}
		System.out.println("");
		input.close();
	}	
}