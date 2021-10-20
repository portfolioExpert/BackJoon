import java.util.*;
import java.io.*;

public class Main{
    static boolean num[] = new boolean[10001];
    static void fx(int n){
        for(int i = 2;i<=n;i++) {
            if(num[i] == true)continue;
            //true가 소수가 아닌 것
            for (int j = i+i; j <= n; j+=i) {
                num[j] = true;
            }
        }
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        fx(10000);
        for(int i = 0;i<n;i++){
            int number = Integer.parseInt(br.readLine());
            int dis = 987654321;
            int small = 0, big = 0;
            for(int j = 2;j<=number;j++){
                if(number - j < 0)break;
                if(num[number-j] == false && num[j] == false && dis > Math.abs(number - j - j)) {
                    small = Math.min(number -j, j);
                    big = Math.max(number - j, j);
                    dis = Math.abs(number - j -j);
                }
            }
            System.out.println(small + " " + big);
        }
    }
}