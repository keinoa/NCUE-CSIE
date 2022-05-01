import java.util.Scanner;

class Point{
	private double x;
	private double y;
	public Point(double x ,double y) {
		this.x = x;
		this.y = y;
	}
	public double distance() {
		return Math.sqrt(Math.pow(this.x-0, 2) + Math.pow(this.y-0, 2));
	}
	public double distance(Point p) {
		return Math.sqrt(Math.pow(this.x-p.x, 2) + Math.pow(this.y-p.y, 2));
	}
}

public class S0831037_4 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Point myPoint;
		boolean end = false;
		double [][] arr = new double [3][2];
		while(true) {
			System.out.print("請輸入三個點的座標 : ");
			for (int i = 0; i < 3 && end == false; i++)
				for (int j = 0; j < 2 && end == false; j++)
				{
					String tmp = input.next();
					if	(tmp.charAt(0) == 'q')
					{
						end = true;
						break;
					}
					arr[i][j] = Double.parseDouble(tmp);
				}
			if (end == true)
				break;
			System.out.print("與原點距離 : ");
			myPoint = new Point(arr[0][0], arr[0][1]);
			System.out.print(myPoint.distance() + " ");
			myPoint = new Point(arr[1][0], arr[1][1]);
			System.out.print(myPoint.distance() + " ");
			myPoint = new Point(arr[2][0], arr[2][1]);
			System.out.println(myPoint.distance());
			
			double max = -1 * Math.pow(2, 64);
			String ans = "";
			
			System.out.print("任兩點距離 : ");
			myPoint = new Point(arr[0][0], arr[0][1]);
			if (myPoint.distance(new Point(arr[1][0], arr[1][1])) > max) {
				max = myPoint.distance(new Point(arr[1][0], arr[1][1]));
				ans = "A B";
			}
			System.out.print(myPoint.distance(new Point(arr[1][0], arr[1][1])) + " ");
			myPoint = new Point(arr[0][0], arr[0][1]);
			if (myPoint.distance(new Point(arr[2][0], arr[2][1])) > max) {
				max = myPoint.distance(new Point(arr[2][0], arr[2][1]));
				ans = "A C";
			}
			System.out.print(myPoint.distance(new Point(arr[2][0], arr[2][1])) + " ");
			myPoint = new Point(arr[1][0], arr[1][1]);
			if (myPoint.distance(new Point(arr[1][0], arr[1][1])) > max) {
				max = myPoint.distance(new Point(arr[2][0], arr[2][1]));
				ans = "B C";
			}
			System.out.println(myPoint.distance(new Point(arr[2][0], arr[2][1])) + " ");
			System.out.println("距離最遠的兩個點 : " + ans);
		}
		input.close();
	}
}
