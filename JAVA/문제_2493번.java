import java.util.*;
import java.io.*;

public class Main{
    static class Pair{
		int x, y;
		public Pair(int x ,int y) {
			this.x = x;
			this.y = y;
		}
		public int first() {
			return x;
		}
		public int second() {
			return y;
		}
	}
	
	public static void main(String []args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack <Pair>st = new Stack<Pair>();
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(br.readLine());
		int num[] = new int[n + 1];
		String str[] = br.readLine().split(" ");
		for(int i = 1;i<=n;i++){
			num[i] = Integer.parseInt(str[i-1]);
		}
		int result[] = new int[n + 1];
		for(int i = n;i>=1;i--) {
			if(st.empty()) {
				st.push(new Pair(num[i], i));
				continue;
			}
			while(!st.empty() && st.peek().first() <= num[i]) {
				result[st.peek().second()] = i;
				st.pop();
			}
			st.push(new Pair(num[i], i));
		}
		while(!st.empty()) {
			result[st.peek().second()] = 0;
			st.pop();
		}
		for(int i = 1;i<=n;i++) {
			System.out.print(result[i] + " ");
		}
	}
}