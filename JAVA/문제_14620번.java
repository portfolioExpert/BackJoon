import java.util.*;
import java.io.*;

public class Main{
    static int n;
    static int map[][];
    static boolean visit[][];
    static int result = 987654321;
    static int dx[] = {1,-1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    static public void dfs(int r, int c, int sum, int cnt){
        if(cnt == 3 || (r == n - 2 && c == n - 2)){
            if(cnt < 3)
                return;
            result = Math.min(result, sum);
            return;
        }
        for(int i = r;i<n-1;i++){
            for(int j = 1;j<n-1;j++){
                int sum2 = map[i][j];
                boolean flag = false;
                for(int k = 0;k<4;k++){
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    if(visit[gox][goy] == true){
                        flag = true;
                        break;
                    }
                }
                if(visit[i][j] == true || flag)
                    continue;
                for(int k = 0;k<4;k++) {
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    sum2 += map[gox][goy];
                    visit[gox][goy] = true;
                }
                visit[i][j] = true;
                dfs(i, j, sum + sum2, cnt + 1);
                visit[i][j] = false;
                for(int k = 0;k<4;k++) {
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    visit[gox][goy] = false;
                }
            }
        }
    }
    public static void main(String arg[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        visit = new boolean[n+1][n+1];
        for(int i = 0;i<n;i++){
            String input[] = br.readLine().split(" ");
            for(int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
        for(int i = 1;i<n-1;i++){
            for(int j = 1;j<n-1;j++){
                int sum = map[i][j];
                for(int k = 0;k<4;k++) {
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    sum += map[gox][goy];
                    visit[gox][goy] = true;
                }
                visit[i][j] = true;
                dfs(i, j, sum, 1);
                visit[i][j] = false;
                for(int k = 0;k<4;k++) {
                    int gox = i + dx[k];
                    int goy = j + dy[k];
                    visit[gox][goy] = false;
                }
            }
        }
        System.out.println(result);
    }
}