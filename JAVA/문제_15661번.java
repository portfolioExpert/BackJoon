import java.util.*;
import java.io.*;

public class Main{
    static int result = 0;
    static int map[][];
    static int n;
    static boolean visit[];

    static public void dfs(int index){
        if(index == n){
            int start = 0;
            int link = 0;
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(visit[i] == true && visit[j] == true)
                        start += map[i][j];
                    else if(visit[i] == false && visit[j] == false)
                        link += map[i][j];
                }
            }

            result = Math.min(result, Math.abs(start - link));
            return;
        }
        for(int i = index + 1;i<=n;i++){
            if(visit[i] == false) {
                visit[i] = true;
                dfs(i);
                visit[i] = false;
            }
        }
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visit = new boolean[n+1];
        result = 987654321;
        map = new int[n + 1][n + 1];
        for(int i = 1;i<=n;i++){
            String input[] = br.readLine().split(" ");
            for(int j =0;j<n;j++){
                map[i][j+1] = Integer.parseInt(input[j]);
            }
        }
        for(int i = 1;i<=n;i++){
            visit[i] = true;
            dfs(i);
            visit[i] = false;
        }
        System.out.println(result);
    }
}