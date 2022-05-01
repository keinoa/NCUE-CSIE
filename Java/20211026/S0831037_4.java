import java.util.Scanner;

abstract class Score 
{
	protected String name; // 學生姓名
	protected int math; // 數學成績
	protected int eng; // 英文成績 
	public abstract void stuAvg(); //計算並顯示每個學生的平均分數 
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
