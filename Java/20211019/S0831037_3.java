import java.util.Scanner;

class CSphere_2
{
  private static int x; // ��ߪ�x �y��
  private static int y; // ��ߪ�y �y��
  private static int z; // ��ߪ�z �y��
  private static double radius; // ��y���b�|
  
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
		System.out.println("2 �y��ߪ��Z�� = " + distance);
		System.out.println((CSphere_2.isIntersect(input.nextDouble(), distance) == true) ? "2 �y���IĲ" : "2 �y�L�IĲ");
		input.close();
	}
}
