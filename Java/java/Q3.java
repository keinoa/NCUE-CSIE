import java.text.DecimalFormat;
import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		DecimalFormat f1 = new DecimalFormat("0.00");
		Scanner input = new Scanner(System.in);
		double  temp = Double.parseDouble(input.next());
		double  cal = (temp - 32) * 5 / 9;
		System.out.printf("Fahrenheit " + f1.format(temp) + " ---> Celsius " + f1.format(cal));
		input.close();
	}
}
