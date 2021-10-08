import java.util.*;
import java.io.*;

public class Main{
    static int num[];

    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        num = new int[n+1];

        input = br.readLine().split(" ");
        int result = 0;
        for(int i = 1;i<=n;i++){
            num[i] = Integer.parseInt(input[i-1]);
            if(num[i] == 1){
                if(num[i-1] != 1)
                    result++;
            }
        }

        for(int i = 0;i<m;i++){
            input = br.readLine().split(" ");
            int command = Integer.parseInt(input[0]);
            if(command == 0)
                System.out.println(result);
            else{
                int innum = Integer.parseInt(input[1]);
                if(innum == n){
                    if(num[innum - 1] == 0 && num[innum] == 0)
                        result++;
                    continue;
                }
                if(num[innum] == 0 && num[innum-1] == 0 && num[innum+1] == 0) {
                    result++;
                }
                else if(num[innum] == 0 && num[innum-1] == 1 && num[innum + 1] == 1)
                    result--;
                num[innum] = 1;
            }
        }
    }
}