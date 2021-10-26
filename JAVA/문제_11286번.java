import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //pq를 작은것 부터 정렬하는 방법
        PriorityQueue<Integer>pq = new PriorityQueue<>((o1, o2) -> {
            int first = Math.abs(o1);
            int second = Math.abs(o2);
            //기준을 정하고 작으면 참이라 해주기
            if(first == second) return o1 > o2 ? 1 : -1;
            return first - second;
        });
        int n = Integer.parseInt(br.readLine());
        for(int i = 0;i<n;i++){
            int num = Integer.parseInt(br.readLine());
            if(num == 0){
                if(pq.isEmpty())
                    System.out.println(0);
                else
                System.out.println(pq.poll());
            }
            else{
                pq.add(num);
            }
        }
    }
}