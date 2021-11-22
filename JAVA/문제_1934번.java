import java.util.*;
import java.io.*;

public class Main{
    static int getGcd(int num1, int num2){
        int maxval = Math.max(num1, num2);
        int minval = Math.min(num1, num2);
        while(minval > 0){
            int moduler = maxval % minval;
            maxval = minval;
            minval = moduler;
        }
        return maxval;
    }
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int i = 0;i<t;i++){
            int num1 ,num2;
            String input[] = br.readLine().split(" ");
            num1 = Integer.parseInt(input[0]);
            num2 = Integer.parseInt(input[1]);
            int GCD = getGcd(num1, num2);
            System.out.println(num1 * num2 / GCD);
        }
    }
}