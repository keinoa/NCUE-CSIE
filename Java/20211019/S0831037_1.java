import java.util.Scanner;

class CSphere
{
	private boolean error = false;
	private int x = 0; // 圓心的x 座標
  	private int y = 0; // 圓心的y 座標
  	private int z = 0; // 圓心的z 座標
  	private double pi = 3.14;
  	private double radius; // 圓球的半徑
  	
  	public void setLocation(int x, int y, int z) {
	  this.x = x;
	  this.y = y;
	  this.z = z;
	}
  	public void setRadius(int radius) {
  		if (radius > 0)
		  this.radius = radius;
  		else 
  			this.error = true;
  	}
  	public void surfaceArea() {
  		if (this.error == false)
  			System.out.println(4.0 * this.pi * Math.pow(this.radius, 2));
  		else 
  			System.out.println("type error!");
	}
  	public void volume() {
  		if (this.error == false)
  			System.out.println((4.0 / 3.0) * this.pi * Math.pow(this.radius, 3));
  		else 
  			System.out.println("type error!");
	}
  	public void showCenter() {
  		if (this.error == false)
  			System.out.println("x = " + this.x + " y = " + this.y + " z = " + this.z);
  		else 
  			System.out.println("type error!");
	}
}

//(a) 試在CSphere 類別裡加入setLocation() method，用來設定圓球之圓心的位置。
//(b) 試在CSphere 類別裡加入setRadius() method，用來設定圓球之半徑。
//(c) 試在CSphere 類別裡加入surfaceArea() method，用來傳回CSphere 物件的表面積(4πr²)。
//(d) 試在CSphere 類別裡加入volume() method，用來傳回CSphere 物件的體積(4/3πr³)。
//(e) 試在CSphere 類別裡加入showCenter() method，用來顯示CSphere 物件之圓心座標。
//(f) 輸入球體的中心點及半徑，利用CSphere 類別建立一個圓球物件，並顯示球體的中心點、表面積及體積。

public class S0831037_1 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		CSphere sphere = new CSphere();
		int [] rig = new int[4];
		for (int i = 0; i < 4; i++)
			rig[i] = input.nextInt();
		sphere.setLocation(rig[0], rig[1], rig[2]);
		sphere.setRadius(rig[3]);
		sphere.showCenter();
		sphere.surfaceArea();
		sphere.volume();
		input.close();
	}
}
