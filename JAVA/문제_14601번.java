import java.util.*;
import java.io.*;

public class Main{
    static int map[][];
    static int cnt;
    //이미 칠해진 곳인지 체크
    static boolean ck(int x, int y, int size){
        for(int i = x;i<x + size;i++){
            for(int j = y;j<y+size;j++){
                if(map[i][j] != 0)return false;
            }
        }
        return true;
    }
    static void fillmap(int x, int y, int size){
        cnt++;
        //상단 왼쪽
        if(ck(x, y, size / 2))
            map[x + size/2 -1][y + size/2 - 1] = cnt;
        //상단 오른쪽
        if(ck(x, y + size/2, size/2))
            map[x + size / 2 - 1][y + size/2] = cnt;
        //아래 왼쪽
        if(ck(x + size/2, y, size/2))
            map[x + size/2][y+size/2 - 1] = cnt;
        //아래 오른쪽
        if(ck(x + size/2, y + size/2, size/2))
            map[x + size/2][y + size/2] = cnt;

        //기저
        if(size == 2)return;

        fillmap(x, y, size/2);
        fillmap(x, y + size/2, size/2);
        fillmap(x + size/2, y, size/2);
        fillmap(x + size/2, y + size/2, size/2);
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        String input[] = br.readLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        map = new int[(int)Math.pow(2, k) + 1][(int)Math.pow(2, k) + 1];
        map[y-1][x-1] = -1;
        fillmap(0, 0, (int)Math.pow(2,k));
        for(int i = (int)Math.pow(2, k) - 1;i>=0;i--){
            for(int j = 0;j<(int)Math.pow(2, k);j++){
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}