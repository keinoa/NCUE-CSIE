import java.util.Scanner;

public class Q10 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int count = input.nextInt();
		String [] pd = new String [count];
		for (int i = 0; i < count; i++)
		{
			pd[i] = "";
			String qua = input.next();
			for (int j = 0; j < 6; j++)
			{
				char ch1 = qua.charAt(j+1);
				char ch2 = qua.charAt(j);
				int rig = ch1-ch2;
				rig = (rig < 0) ? rig * -1 : rig;
				pd[i] += rig;
			}
		}
		for (int i = 0; i < count; i++)
			System.out.println(pd[i]);
		input.close();
	}
}