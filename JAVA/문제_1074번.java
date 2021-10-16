import java.io.*;

public class Main{
    static int n, r, c;
    static long result;
    static void div(int x, int y, int size, long numbering){
        if(x + size < r || x > r || y + size < c || y > c)
            return;
        if(x == r && y == c) {
            result = numbering;
            return;
        }
        if(size == 2){
            int cnt = 0;
            for(int i = x;i<x + size;i++){
                for(int j = y;j<y + size;j++){
                    if(i == r && j == c) {
                        result = cnt + numbering;
                        return;
                    }
                    cnt++;
                }
            }
            return;
        }
        //왼쪽 상단
        div(x, y, size/2, numbering);
        //오른쪽 상단
        div(x, y + size / 2, size/2, numbering + (size/2 * size/2));
        //왼쪽 하단
        div(x + size/2, y, size/2, numbering + (size/2 * size/2) + (size/2 * size/2));
        //오른쪽 하단
        div(x + size/2, y + size/2 , size/2,  numbering + (size/2 * size/2) + (size/2 * size/2) + (size/2 * size/2));
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        r = Integer.parseInt(input[1]);
        c = Integer.parseInt(input[2]);
        div(0, 0, (int)Math.pow(2, n),0);
        System.out.println(result);
    }
}