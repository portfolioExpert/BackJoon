import java.util.*;
import java.io.*;

public class Main{
    static int dp[][];
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        dp = new int[n+1][n+1];
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = 987654321;
            }
            dp[i][i] = 0;
        }
        for(int j = 0;j<m;j++){
            input = br.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            dp[from][to] = 1;
            dp[to][from] = 1;
        }

        //플로이드로 돌려서 지점사이 최단거리 구하기
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                for(int k = 1;k<=n;k++){
                    dp[j][k] = Math.min(dp[j][k], dp[j][i] + dp[i][k]);
                }
            }
        }
        int first = 0;
        int second = 0;
        int result = 987654321;
        if(n == 2){
            System.out.println(1 + " " + 2 + " " + 0);
            return;
        }
        for(int i = 1;i<=n;i++){
            for(int j = i + 1;j<=n;j++){
                int sum = 0;
                for(int k = 1;k<=n;k++){
                    if(dp[k][i] != 987654321 && dp[k][j] != 987654321)
                        sum += Math.min(dp[k][i], dp[k][j]);
                }
                if(sum != 0 && result > sum){
                    first = i;
                    second = j;
                    result = sum;
                }
            }
        }
        System.out.println(first + " " + second + " " + result * 2);
    }
}