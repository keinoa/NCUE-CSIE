import java.util.Scanner;

class Subject // 父類別Subject
{
	double mid_score; // 期中考成績
	double final_score;// 期末考成績
	double quiz; // 小考成績

	public Subject() {
	}

	public Subject(double m, double f, double q) {
		this.mid_score = m;
		this.final_score = f;
		this.quiz = q;
	}

	public double score() {
		return mid_score * 0.4 + final_score * 0.4 + quiz * 0.2;
	}
}

class Chinese extends Subject{
	
	public Chinese(double m, double f) {
		// TODO Auto-generated constructor stub
		this.mid_score = m;
		this.final_score = f;
	}
	
	public double score() {
		return mid_score * 0.5 + final_score * 0.5;
	}
	
}

class English extends Subject{
	public English(double f, double q) {
		// TODO Auto-generated constructor stub
		this.final_score = f;
		this.quiz = q;
	}
	
	public double score() {
		return final_score * 0.7 + quiz * 0.3;
	}
}

public class S0831037_3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Chinese score_Chinese;
		English score_English;
		double max = -1 * Math.pow(2, 64);
		int cnt = input.nextInt();
		for (int i = 0; i < cnt; i++) 
		{
			int subject = input.nextInt();
			int [] arr = new int[2];
			for (int j = 0; j < 2; j++)
				arr[j] = input.nextInt();
			if (subject == 1) {
				score_Chinese = new Chinese(arr[0], arr[1]);
				max = (score_Chinese.score() > max) ? score_Chinese.score() : max;
			}
			else if (subject == 2) {
				score_English = new English(arr[0], arr[1]);
				max = (score_English.score() > max) ? score_English.score() : max;
			}
		}
		System.out.println(max);
		input.close();
	}
}
