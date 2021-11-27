import java.util.*;
import java.io.*;

public class Main{
    static boolean palindrome(int num){
        String str = Integer.toString(num);
        int left = 0;
        int right = str.length() - 1;
        while(left < right){
            if(str.charAt(left) == str.charAt(right)) {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean check[] = new boolean[2000001];
        check[1] = true;
        for(int i = 2;i<=2000000;i++){
            if(check[i] == true)
                continue;
            for(int j = i + i;j<=2000000;j+=i){
                check[j] = true;
            }
        }
        for(int i = n;i<=2000000;i++){
            if(check[i] == false && palindrome(i)){
                System.out.println(i);
                break;
            }
        }
    }
}