import java.io.*;
import java.util.*;

public class Main{
    static int map[] = new int[201];
    static boolean visit[] = new boolean[201];
    static int n, k;
    static ArrayList<Integer>robot = new ArrayList<>();
    //회전하는 것
    static void move(){
        int save = map[n*2 - 1];
        boolean save2 = visit[n*2 - 1];
        for(int i = n*2 - 1;i>=1;i--){
            map[i] = map[i-1];
            visit[i] = visit[i-1];
        }
        visit[0] = save2;
        map[0] = save;
        //움직일 때 로봇이 움직이는 것
        for(int i = 0;i<robot.size();i++){
            robot.set(i, robot.get(i) + 1);
        }
        if(!robot.isEmpty() && robot.get(0) == n-1) {
            robot.remove(0);
            visit[n - 1] = false;
        }
    }
    //로봇 이동
    static void robotMove(){
        for(int i = 0;i<robot.size();i++){
            int pos = robot.get(i);
            //내구도가 있고 위치에 아무것도 없을 경우
            if(map[pos + 1] > 0 && visit[pos+1] == false){
                visit[pos] = false;
                map[pos + 1]--;
                //내리는 곳일 경우
                if(pos + 1 == n-1) {
                    robot.remove(i);
                    i--;
                }
                //이동 성공의 경우
                else{
                   visit[pos + 1] = true;
                   robot.set(i, pos + 1);
                }
            }
        }
    }
    //로봇 올리기
    static void getRobot(){
        if(map[0] > 0 && visit[0] == false){
            visit[0] = true;
            robot.add(0);
            map[0]--;
        }
    }
    //k개 이상인지 아닌지 체크
    static boolean check(){
        int sum = 0;
        for(int i = 0;i<2*n;i++){
            if(map[i] == 0)
                sum++;
        }
        if(k <= sum)
            return false;
        else
            return true;
    }
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int time = 0;
        String input[] = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        for(int i = 0;i<2*n;i++){
            map[i] = Integer.parseInt(input[i]);
        }
        while(check()){
            time++;
            move();
            robotMove();
            getRobot();
        }
        System.out.println(time);
    }
}