import java.util.*;
import java.io.*;

public class Main{
    static char map[][];
    static void div(int size, int x1, int y1, int x2, int y2){
        if(size == 1){
            map[x2][y2] = '*';
            return;
        }

        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i == 1 && j == 1)
                    continue;
                div(size/3, x1 + i*(size/3), y1 + j*(size/3), x1 + (i+1)*(size/3) - 1, y1 + (j+1)*(size/3) - 1);
            }
        }
    }
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        map = new char[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                map[i][j] = ' ';
            }
        }
        div(n, 0, 0, n-1, n-1);
        for(int i = 0;i<n;i++){
            bw.write(map[i]);
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}