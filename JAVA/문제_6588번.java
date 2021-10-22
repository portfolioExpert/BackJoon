import java.util.*;
import java.io.*;

public class Main{
    static boolean ck[] = new boolean[1000001];
    static void fx(int n){
        ck[1] = true;
        for(int i = 2;i<=n;i++){
            if(ck[i] == true)continue;
            for(int j = i + i;j<=n;j+=i){
                ck[j] = true;
            }
        }
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        fx(1000000);
        while(true){
            int num = Integer.parseInt(br.readLine());
            if(num == 0)break;
            for(int i = 2;i<=num/2;i++){
                if(ck[i] == false && ck[num-i] == false){
                    System.out.println(num + " = " + i + " + " + (num - i));
                    break;
                }
            }
        }
    }
}