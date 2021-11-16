import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        boolean visit[] = new boolean[10001];
        visit[1] = true;
        for(int i = 2;i<=10000;i++){
            if(visit[i])
                continue;
            for(int j = i + i;j<=10000;j+=i){
                visit[j] = true;
            }
        }
        boolean flag = true;
        int result = 0;
        int minval = 987654321;
        for(int i = m;i<=n;i++){
            if(visit[i] == false){
                minval = Math.min(minval, i);
                result+=i;
                flag = false;
            }
        }
        if(flag)
            System.out.println(-1);
        else{
            System.out.println(result);
            System.out.println(minval);
        }
    }
}