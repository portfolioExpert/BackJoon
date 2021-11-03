import java.util.*;
import java.io.*;

public class Main{
    static int num[][] = new int[1100][1100];
    static int sum[][] = new int[1100][1100];

    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        for(int i = 1;i<=n;i++) {
            input = br.readLine().split(" ");
            for (int j = 1; j <= n; j++) {
                num[i][j] = Integer.parseInt(input[j - 1]);
            }
        }
        for(int i = 1;i<=n;i++){
            sum[1][i] = num[1][i] + sum[1][i-1];
            sum[i][1] = num[i][1] + sum[i-1][1];
        }
        for(int i = 2;i<=n;i++){
            for(int j = 2;j<=n;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + num[i][j] - sum[i-1][j-1];
            }
        }
        for(int i = 0;i<m;i++){
            input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);
            System.out.println(sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]);
        }
    }
}