import java.util.Arrays;
import java.util.Scanner;

public class Q15 {
	
	// 拜訪資訊
	public static boolean [] used;
	// 最後結果
	public static boolean ans;
	// 每列的資料
	public static int [] length;
	// 邊長, 棒子數, 目前計算到的邊, 邊總和
	public static int edgeLength, amount, nowEdge, sum;
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int column = input.nextInt();
		for (int index = 0; index < column; index++)
		{
			ans = false;	
			sum = nowEdge = 0;
			amount = input.nextInt();
			used = new boolean [amount];
			length = new int [amount];
			for (int i = 0; i < amount; i++)
			{
				length[i] = input.nextInt();
				sum += length[i];
			}
			
			edgeLength = sum >> 2;
			Arrays.sort(length);
			
			if (sum % 4 != 0 || length[amount-1] > (sum / 4))
				ans = false;
			else 
				ans = DFS(0, 0);
			System.out.println((ans == true) ? "yes" : "no");
		}
		input.close();
	}
	
	public static boolean DFS(int nowLength, int now) 
	{
		if (nowEdge == 3) //4個邊都找完
			return true;
		if (nowLength == edgeLength) 
		{
			nowEdge++;
			if (DFS(0, 0))
				return true;
			nowEdge--;
		}
		for (int i = now; i < amount; i++)
			if (!used[i] && (nowLength + length[i]) <= edgeLength) 
			{
				used[i] = true;
				if (DFS(nowLength + length[i], i + 1))
					return true;
				used[i] = false;
			}
		return false;
	}
	
}