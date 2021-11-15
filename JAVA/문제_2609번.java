import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m;
        String input[] = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        int maxval = Math.max(n, m);
        int minval = Math.min(n, m);
        //유클리드 호제법으로 최대공약수를 구하고
        while (minval != 0) {
            int save = maxval % minval;
            maxval = minval;
            minval = save;
        }
        System.out.println(maxval);
        //최소공배수는 두개를 곱해서 최대공약수로 나누어주면 된다.
        System.out.println(n * m / maxval);
    }
}