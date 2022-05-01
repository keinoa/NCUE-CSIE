import java.text.DecimalFormat;
import java.util.Scanner;

public class Q2 {
	public static void main(String[] args) {
		DecimalFormat f1 = new DecimalFormat("0.00");
		Scanner input = new Scanner(System.in);
		double  high = Double.parseDouble(input.next());
		double  width = Double.parseDouble(input.next());
		System.out.println("Height = "+ f1.format(high));
		System.out.println("Width = "+ f1.format(width));
		System.out.println("Perimeter = " + f1.format(high*2 + width*2));
		System.out.println("Area = " + f1.format(high*width));
		input.close();
	}
}
