import java.text.DecimalFormat;
import java.util.Scanner;

public class Q5 {
	public static void main(String[] args) {
		DecimalFormat f1 = new DecimalFormat("0.00");
		Scanner input = new Scanner(System.in);
		double [] x = new double [2];
		double [] y = new double [2];
		for(int i = 0; i < 2; i++)
		{
			x[i] = Double.parseDouble(input.next());
			y[i] = Double.parseDouble(input.next());
		}
		double total = Math.sqrt(Math.pow((x[0]-x[1]),2) + Math.pow((y[0]-y[1]),2));
		System.out.println("Distance = " + f1.format(total));
		input.close();
	}
}
