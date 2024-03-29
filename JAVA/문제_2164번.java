import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1;i<=n;i++){
            q.add(i);
        }
        while(q.size()>1){
            q.poll();
            int now = q.poll();
            q.add(now);
        }
        System.out.println(q.poll());
    }
}