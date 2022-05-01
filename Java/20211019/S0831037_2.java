
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

//(a) �w�qsetB()�BsetH()�PsetColor()�A�ϱo���̥i�H���O�Ψӳ]�wCTriangle ����base�Bheight �Pcolor �������ȡC
//(b) �]�p�@�ӨS���޼ƪ��غc��CTriangle()�A�ϱo���غc���Q�I�s�ɡA�|�۰ʳ]�wbase=10�Aheight=5 �Acolor="blue" �C
//(c) �]�p�@�ӫغc��CTriangle(int b, int h, String c)�A���غc���Q�I�s�ɡA�K�|�Q��(a)�ҩw�q��method�۰ʳ]�w�T���Ϊ����B���P�C��C
//(d) �]�p�@��show() method�A�i�L�X�T���Ϊ� ���B���P�C��C
//(e) ���O�Q��(b)��(c)���ͤG�ӷs������A�æL�X�T���Ϊ� ���B���P�C��C

public class S0831037_2 {
	public static void main(String[] args) {
		CTriangle triangle = new CTriangle();
		triangle.show();
		triangle = new CTriangle(30, 10, "Red");
		triangle.show();
		System.out.println("Process completed.");
	}
}

