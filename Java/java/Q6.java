import java.util.Scanner;

public class Q6 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		long cnt = Integer.parseInt(input.next());
		long total = 0;
		if (cnt >= 10)
		{
			total += 800*(cnt/10);
			cnt %= 10;
		}
		if (cnt >= 5)
		{
			total += 440*(cnt/5);
			cnt %= 5;
		}
		if (cnt >= 2)
		{
			total += 180*(cnt/2);
			cnt %= 2;
		}
		if (cnt != 0)
			total += 100*cnt;
		System.out.println(total);
		input.close();
	}
}
