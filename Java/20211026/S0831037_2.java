class CCShape // 父類別CShape
{
  public double area()
  {
    return 0.0;
  }
}

class CCSquare extends CCShape // 父類別CShape
{
  private static double edge;
  public CCSquare(double edge){
	  CCSquare.edge = edge;
  }
  public double area()
  {
    return Math.pow(CCSquare.edge, 2);
  }
}

class CCTriangle extends CCShape // 父類別CShape
{
	private static double base;
	private static double height;
	public CCTriangle(double base, double height){
		CCTriangle.base = base;
		CCTriangle.height = height;
	}
	public double area()
	{
	  return (CCTriangle.base*CCTriangle.height)/2;
	}
}

class CCCircle extends CCShape // 父類別CShape
{
	private static double radius;
	private static double pi = 3.14;
	public CCCircle(double radius){
		CCCircle.radius = radius;
	}
	public double area()
	{
	  return Math.pow(CCCircle.radius, 2) * pi;
	}
}

public class S0831037_2 {

	public static void main(String[] args) {
		CCShape shp[]=new CCShape[6];
		double max = -1 * Math.pow(2, 64);
		shp[0]=new CCCircle(2.0);
		max = largest(max, shp[0].area());
		System.out.println("面積1 = " + shp[0].area());
		
		shp[1]=new CCCircle(3.0);
		max = largest(max, shp[1].area());
		System.out.println("面積2 = " + shp[1].area());
		
		shp[2]=new CCSquare(4.0);
		max = largest(max, shp[2].area());
		System.out.println("面積3 = " + shp[2].area());
		
		shp[3]=new CCSquare(5.0);
		max = largest(max, shp[3].area());
		System.out.println("面積4 = " + shp[3].area());
		
		shp[4]=new CCTriangle(3.0,3.0);
		max = largest(max, shp[4].area());
		System.out.println("面積5 = " + shp[4].area());
		
		shp[5]=new CCTriangle(5.0,4.0);
		max = largest(max, shp[5].area());
		System.out.println("面積6 = " + shp[5].area());
		
		System.out.println("面積最大 = " + max);
	}
	
	public static double largest(double max, double tmp) {
		return (tmp > max) ? tmp : max;
	}
	
}
