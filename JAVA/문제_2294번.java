import java.util.*;
import java.io.*;

public class Main{
    static int dp[] = new int[10001];
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input [] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        for(int i = 0;i<=10000;i++){
            dp[i] = 987654321;
        }
        for(int i = 0;i<n;i++){
            int num = Integer.parseInt(br.readLine());
            if(num > 10000)
                continue;
            dp[num] = 1;
            for(int j = 1;j<=10000;j++){
                if(num*j >10000 || num*j - num <= 0)
                    break;
                dp[num*j] = Math.min(dp[num*j], dp[num*j - num] + 1);
            }
        }
        for(int i = 1;i<=k;i++) {
            for (int j = 1; j <= i; j++) {
                if(dp[i-j] < 0)break;
                dp[i] = Math.min(dp[i], dp[i-j] + dp[j]);
            }
        }
        if(dp[k] == 987654321)
            System.out.println(-1);
        else
            System.out.println(dp[k]);
    }
}