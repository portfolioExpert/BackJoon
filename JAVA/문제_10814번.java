import java.io.*;
import java.util.*;


public class Main{
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<String>> v = new ArrayList<>();
        for(int i = 0;i<=200;i++){
            v.add(new ArrayList<>());
        }
        for(int i = 0;i<n;i++){
            String input[] = br.readLine().split(" ");
            int age = Integer.parseInt(input[0]);
            String name = input[1];
            v.get(age).add(name);
        }
        for(int i = 0;i<=200;i++){
            if(v.get(i).size() != 0){
                Iterator<String>it = v.get(i).iterator();
                while(it.hasNext()){
                    System.out.println(i + " " +it.next());
                }
            }
        }
    }
}