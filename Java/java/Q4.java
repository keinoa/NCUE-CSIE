import java.text.DecimalFormat;
import java.util.Scanner;

public class Q4 {
	public static void main(String[] args) {
		DecimalFormat f1 = new DecimalFormat("0.0");
		Scanner input = new Scanner(System.in);
		double rig, sum = 0, average;
		for(int i = 0; i < 5; i++)
		{
			rig = Double.parseDouble(input.next());
			sum += rig;
		}
		average = sum/5;
		System.out.println("Sum = " + f1.format(sum));
		System.out.println("Average = " + f1.format(average));
		input.close();
	}
}
