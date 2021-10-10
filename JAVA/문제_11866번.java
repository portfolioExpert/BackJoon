import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        Queue<Integer>q = new LinkedList<>();
        for(int i = 1;i<=n;i++){
            q.add(i);
        }
        int cnt = 0;
        System.out.print("<");
        while(!q.isEmpty()){
            if(q.size() == 1){
                System.out.print(q.poll());
                break;
            }
            cnt++;
            int now = q.peek();
            q.poll();
            if(cnt == k) {
                System.out.print(now + ", ");
                cnt = 0;
                continue;
            }
            q.add(now);
        }
        System.out.print(">");
    }
}