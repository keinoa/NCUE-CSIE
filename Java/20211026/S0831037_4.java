import java.util.Scanner;

abstract class Score 
{
	protected String name; // �ǥͩm�W
	protected int math; // �ƾǦ��Z
	protected int eng; // �^�妨�Z 
	public abstract void stuAvg(); //�p�����ܨC�Ӿǥͪ��������� 
}

abstract class CScore extends Score{
	private int max = (int) (-1 * Math.pow(2, 32));
	public CScore(String str,int m,int e){
		this.name = str;
		this.math = m;
		this.eng = e;
	}
	public void stuAvg() {
		System.out.println((this.math+this.math)/2);
	}
	public int showMax(CScore c[]) {
		max
		return max;
	}
}
public class S0831037_4 {
	public static void main() {
		Scanner input = new Scanner(System.in);
		int cnt = input.nextInt();
		Score [] student = new Score [cnt];
		for (int i = 0; i < cnt ; i++) {
			
		}
		input.close();
	}
	
}
