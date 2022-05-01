import java.text.DecimalFormat;
import java.util.Scanner;

public class Q7 {
	public static void main(String[] args) {
		DecimalFormat f1 = new DecimalFormat("0.0");
		Scanner input = new Scanner(System.in);
		double m = Double.parseDouble(input.next());
		double s = Double.parseDouble(input.next());
		double len = Double.parseDouble(input.next());
		double hr = (m/60) + (s/3600);
		System.out.println("Speed = " + f1.format((len/hr)/1.6));
		input.close();
	}
}