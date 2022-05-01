import java.util.Scanner;

public class Q1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String name = input.next(); 
		int sc1 = input.nextInt();
		int sc2 = input.nextInt();
		int sc3 = input.nextInt();
		System.out.println(name + " " + sc1 + "," + sc2 + "," + sc3 );
		input.close();
	}
}
