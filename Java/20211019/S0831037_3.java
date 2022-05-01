import java.util.Scanner;

class CSphere_2
{
  private static int x; // 圓心的x 座標
  private static int y; // 圓心的y 座標
  private static int z; // 圓心的z 座標
  private static double radius; // 圓球的半徑
  
  public CSphere_2(int a, int b, int c, double r) {
	  CSphere_2.x = a;
	  CSphere_2.y = b;
	  CSphere_2.z = c;
	  CSphere_2.radius = r;
  }
  
  public static double distance(int x, int y, int z) {
	  return Math.sqrt(Math.pow(CSphere_2.x - x, 2) + Math.pow(CSphere_2.y - y, 2) + Math.pow(CSphere_2.z - z, 2));
  }
  
  public static boolean isIntersect(double radius, double distance) {
	  return (CSphere_2.radius + radius >= distance);
  }
}

public class S0831037_3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		new CSphere_2(input.nextInt(), input.nextInt(), input.nextInt(), input.nextDouble());
		double distance = CSphere_2.distance(input.nextInt(), input.nextInt(), input.nextInt());
		System.out.println("2 球圓心的距離 = " + distance);
		System.out.println((CSphere_2.isIntersect(input.nextDouble(), distance) == true) ? "2 球有碰觸" : "2 球無碰觸");
		input.close();
	}
}
