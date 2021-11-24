import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Deque<Integer> dq = new LinkedList<>();
        for(int i = 0;i<n;i++){
            String command;
            String input[] = br.readLine().split(" ");
            command = input[0];
            int num = 0;
            if(command.equals("push_back") || command.equals("push_front")){
                num = Integer.parseInt(input[1]);
            }
            switch(command){
                case "push_front":
                    dq.addFirst(num);
                    break;
                case "push_back":
                    dq.addLast(num);
                    break;
                case "pop_front":
                    if(!dq.isEmpty()) {
                        System.out.println(dq.pollFirst());
                    }
                    else
                        System.out.println(-1);
                    break;
                case "pop_back":
                    if(!dq.isEmpty()) {
                        System.out.println(dq.pollLast());
                    }
                    else
                        System.out.println(-1);
                    break;
                case "size":
                    System.out.println(dq.size());
                    break;
                case "empty":
                    if(dq.isEmpty())
                        System.out.println(1);
                    else
                        System.out.println(0);
                    break;
                case "front":
                    if(!dq.isEmpty()) {
                        System.out.println(dq.peekFirst());
                    }
                    else
                        System.out.println(-1);
                    break;
                case "back":
                    if(!dq.isEmpty()) {
                        System.out.println(dq.peekLast());
                    }
                    else
                        System.out.println(-1);
                    break;
            }
        }
    }
}