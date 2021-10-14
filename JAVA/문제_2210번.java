import java.util.*;
import java.io.*;

public class Main{
    static int map[][];
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    static Set<Integer> s = new HashSet<>();
    static void dfs(int x, int y, int cnt, int sum){
        if(cnt == 6){
            s.add(sum);
            return;
        }
        for(int i = 0;i<4;i++){
            int gox = x + dx[i];
            int goy = y + dy[i];
            if(gox >= 0 && gox < 5 && goy>= 0 && goy < 5){
                dfs(gox, goy, cnt + 1, sum + map[gox][goy] * (int)Math.pow(10, cnt));
            }
        }
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        map = new int[5][5];
        for(int i = 0;i<5;i++){
            String input[] = br.readLine().split(" ");
            for(int j = 0;j<5;j++){
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                dfs(i, j, 1, map[i][j]);
            }
        }
        System.out.println(s.size());
    }
}