import java.util.Scanner;

public class Q12 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String text = input.next();
		int len = text.length();
		int begin = 0, max = 0, cnt = 0;
		String [] rig = new String[200];
		for (int index = 0; index < len; index++)
		{
			int right = index, left = index;
			if (index + 1  < len)
				while (index < len && text.charAt(index + 1) == text.charAt(index))
				{
					index++;
					right++;
				}
			while (right < len && left >= 0 && text.charAt(right) == text.charAt(left))
			{
				right++;
				left--;
			}
			right--;
			left++;
			if (right - left + 1 >= max)
			{
				max = right - left + 1;
				begin = left;
				rig[cnt] = text.substring(begin, right + 1);
				cnt++;
			}
		}
		for (int index = 0; index < cnt; index++)
			if (rig[cnt - 1].length() == rig[index].length())
				System.out.print(rig[index] + " ");
		input.close();
	}	
}