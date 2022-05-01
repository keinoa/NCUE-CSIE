import java.util.Scanner;

public class Q14 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num = input.nextInt();
		boolean [] used = new boolean[1000];
		int [] dp = new int[1000];
		System.out.print(climbStairs(num, used, dp));
		input.close();
	}
	public static int climbStairs(int n, boolean [] used, int [] dp ) 
	{
	    if (n == 1) return 1;
	    if (n == 2) return 2;
	    if (used[n]) return dp[n];
	    used[n] = true;
	    dp[n] = climbStairs(n-1, used, dp) + climbStairs(n-2, used, dp); // ¹ê§@ª¬ºAÂà²¾
	    return dp[n];
	} 
}