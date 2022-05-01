
class CTriangle{
	private int base;
	private int height;
	private String color;
	
	public CTriangle() {
		this.base = 10;
		this.height = 5;
		this.color = "blue";
	}
	
	public CTriangle(int b, int h, String c) {
		this.base = b;
		this.height = h;
		this.color = c;
	}
	
	public void setB(int base) {
		this.base = base;
	}
	
	public void setH(int height) {
		this.height = height;
	}
	
	public void setColor(String color) {
		this.color = color;
	}
	
	public void show() {
		System.out.println("Color=" + this.color);
		System.out.println("base=" + this.base + ", height=" + this.height + "\n");
	}
}

//(a) 定義setB()、setH()與setColor()，使得它們可以分別用來設定CTriangle 物件的base、height 與color 成員的值。
//(b) 設計一個沒有引數的建構元CTriangle()，使得當此建構元被呼叫時，會自動設定base=10，height=5 ，color="blue" 。
//(c) 設計一個建構元CTriangle(int b, int h, String c)，當此建構元被呼叫時，便會利用(a)所定義的method自動設定三角形的底、高與顏色。
//(d) 設計一個show() method，可印出三角形的 底、高與顏色。
//(e) 分別利用(b)及(c)產生二個新的物件，並印出三角形的 底、高與顏色。

public class S0831037_2 {
	public static void main(String[] args) {
		CTriangle triangle = new CTriangle();
		triangle.show();
		triangle = new CTriangle(30, 10, "Red");
		triangle.show();
		System.out.println("Process completed.");
	}
}

