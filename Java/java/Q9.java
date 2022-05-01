import java.util.Scanner;

public class Q9 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int count = input.nextInt();
		int ans = ugly(count);
		System.out.print(ans);
		input.close();
	}
	
	public static int ugly(int index){
		for (int cnt = 1, num = 2;; num++)
		{
			int rig = num;
			while (rig % 5 == 0)
				rig /= 5;
			while (rig % 3 == 0)
				rig /= 3;
			while (rig % 2 == 0)
				rig /= 2;
			if (rig == 1)
				cnt++;
			if (cnt == index)
				return num;
		}
    }
	
}