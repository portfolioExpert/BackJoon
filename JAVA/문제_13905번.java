import java.util.*;
import java.io.*;

public class Main{
    static class Node{
        int from, to, weight;
        public Node(int from, int to, int weight){
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
    static class Edge{
        int to, weight;
        public Edge(int to, int weight){
            this.to = to;
            this.weight= weight;
        }
    }
    static int n, m;
    static int s, e;
    static ArrayList<Node> node = new ArrayList<>();
    static ArrayList<ArrayList<Edge>> v = new ArrayList<>();
    static int parent[] = new int[100001];
    static int dp[] = new int[100001];
    static int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    static void merge(int node1, int node2){
        node1 = find(node1);
        node2 = find(node2);
        if(parent[node2] != parent[node1])
            parent[node2] = node1;
    }
    static void bfs(int go){
        Queue<Integer>q = new LinkedList<>();
        q.add(go);
        dp[go] = 0;
        while(!q.isEmpty()){
            int now = q.poll();
            for(int i = 0;i<v.get(now).size();i++){
                int next = v.get(now).get(i).to;
                int weight = -v.get(now).get(i).weight;
                if(dp[next] == 987654321) {
                    if(go == now)
                        dp[next] = weight;
                    else
                        dp[next] = Math.min(dp[now], weight);
                    q.add(next);
                }
            }
        }
    }
    public static void main(String arg[])throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        input = br.readLine().split(" ");
        s = Integer.parseInt(input[0]);
        e = Integer.parseInt(input[1]);
        for(int i = 0;i<m;i++){
            input = br.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            int weight = Integer.parseInt(input[2]);
            node.add(new Node(from, to, -weight));

        }
        for(int i = 0;i<=n;i++){
            v.add(new ArrayList<>());
            dp[i] = 987654321;
        }
        //weight를 기준으로 오름차순 정렬
        node.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return Integer.compare(o1.weight, o2.weight);
            }
        });

        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<m;i++){
            if(parent[s] == parent[e])
                break;
            Node now = node.get(i);
            if(find(now.from) != find(now.to)){
                merge(now.from, now.to);
                v.get(now.from).add(new Edge(now.to, now.weight));
                v.get(now.to).add(new Edge(now.from, now.weight));
            }
        }
        bfs(s);
        if(dp[e] == 987654321)
            System.out.println(0);
        else
            System.out.println(dp[e]);
    }
}