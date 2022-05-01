class CShape // 父類別CShape
{
  public double area()
  {
    return 0.0;
  }
}

class CSquare extends CShape // 父類別CShape
{
  private static double edge;
  public CSquare(double edge){
	  CSquare.edge = edge;
  }
  public double area()
  {
    return Math.pow(CSquare.edge, 2);
  }
}

class CTriangle extends CShape // 父類別CShape
{
	private static double base;
	private static double height;
	public CTriangle(double base, double height){
		CTriangle.base = base;
		CTriangle.height = height;
	}
	public double area()
	{
	  return (CTriangle.base*CTriangle.height)/2;
	}
}

class CCircle extends CShape // 父類別CShape
{
	private static double radius;
	private static double pi = 3.14;
	public CCircle(double radius){
		CCircle.radius = radius;
	}
	public double area()
	{
	  return Math.pow(CCircle.radius, 2) * pi;
	}
}

public class S0831037_1 {

	public static void main(String[] args) {
		double max = -1 * Math.pow(2, 64);
		CCircle cir1=new CCircle(2.0);
		max = largest(max, cir1.area());
		System.out.println("面積1 = " + cir1.area());
		
		CCircle cir2=new CCircle(3.0);
		max = largest(max, cir2.area());
		System.out.println("面積2 = " + cir2.area());
		
		CSquare squ1=new CSquare(4.0);
		max = largest(max, squ1.area());
		System.out.println("面積3 = " + squ1.area());
		
		CSquare squ2=new CSquare(5.0);
		max = largest(max, squ2.area());
		System.out.println("面積4 = " + squ2.area());
		
		CTriangle tri1=new CTriangle(3.0,3.0);
		max = largest(max, tri1.area());
		System.out.println("面積5 = " + tri1.area());
		
		CTriangle tri2=new CTriangle(5.0,4.0);
		max = largest(max, tri2.area());
		System.out.println("面積6 = " + tri2.area());
		
		System.out.println("面積最大 = " + max);
	}
	
	public static double largest(double max, double tmp) {
		return (tmp > max) ? tmp : max;
	}
}
