import java.util.*;
import java.io.*;

public class Main{
    static class Pair{
        int x, y;
        public Pair(int x ,int y){
            this.x = x;
            this.y = y;
        }

        public int first(){
            return x;
        }

        public int second(){
            return y;
        }
    }

    //남 북 동 서
    static int dx[] = {1, -1 ,0, 0};
    static int dy[] = {0, 0, 1, -1};
    static int map[][];
    static int dp[][];

    static int n, m;
    static int sizex, sizey, fromx, fromy, tox, toy;

    //방향에 맞는 방향 한줄만 보면 된다
    static public boolean check(int x, int y, int dir){
        switch(dir){
            case 0:
                for(int i = y;i<y + sizey;i++){
                    if(map[x+sizex][i] == 1)
                        return false;
                }
                break;
            case 1:
                for(int i = y;i<y + sizey;i++){
                    if(map[x-1][i] == 1)
                        return false;
                }
                break;
            case 2:
                for(int i = x;i<x + sizex;i++){
                    if(map[i][y + sizey] == 1)
                        return false;
                }
                break;
            case 3:
                for(int i = x;i<x + sizex;i++){
                    if(map[i][y - 1] == 1)
                        return false;
                }
                break;
        }
        return true;
    }

    static public void bfs(){
        Queue<Pair>q = new LinkedList<>();
        q.add(new Pair(fromx, fromy));
        dp[fromx][fromy] = 0;
        while(!q.isEmpty()){
            int gox = q.peek().first();
            int goy = q.peek().second();
            q.poll();
            for(int i = 0;i<4;i++){
                int gx = gox + dx[i];
                int gy = goy + dy[i];
                if(gx >= 1 && gx + sizex  - 1<= n && gy >= 1 && gy + sizey - 1 <= m && map[gx][gy] == 0 && dp[gx][gy] == -1 && check(gox, goy, i)){
                    dp[gx][gy] = dp[gox][goy] + 1;
                    q.add(new Pair(gx, gy));
                }
            }
        }
    }

    public static void main(String arg[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        map = new int[n+1][m+1];
        dp = new int[n+1][m+1];

        for(int i = 1; i<=n;i++){
            input = br.readLine().split(" ");
            for(int j = 0;j<m;j++){
                map[i][j+1] = Integer.parseInt(input[j]);
                dp[i][j+1] =-1;
            }
        }
        input = br.readLine().split(" ");
        sizex = Integer.parseInt(input[0]);
        sizey = Integer.parseInt(input[1]);
        fromx = Integer.parseInt(input[2]);
        fromy = Integer.parseInt(input[3]);
        tox = Integer.parseInt(input[4]);
        toy = Integer.parseInt(input[5]);
        bfs();
        System.out.println(dp[tox][toy]);
    }
}