import java.util.*;
import java.io.*;

public class Main{
    static ArrayList<Integer>al = new ArrayList<>();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static void dfs(int n ,int m, int length) throws IOException {
        if(al.size() == m){
            String str = "";
            for(int y : al) {
                str += y;
                str += ' ';
            }
            bw.write(str);
            bw.write("\n");
            return;
        }
        for(int i = 1;i<=n;i++){
            al.add(i);
            dfs(n, m, length + 1);
            al.remove(al.size() - 1);
        }
    }
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        dfs(n, m, 0);
        bw.flush();
        bw.close();
    }
}