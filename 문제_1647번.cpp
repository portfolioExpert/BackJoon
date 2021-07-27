//문제 1647번 도시 분할 계획 -> 최소 스패닝 트리, 유니온 파인드
#include <queue>
priority_queue<pair<int,pair<int,int>>>pq;
int parent[100001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2)
        parent[node2] = node1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    int result = 0;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m;i++){
        int num1, num2, cost;
        cin >> num1 >> num2 >> cost;
        pq.push({-cost,{num1, num2}});
    }
    int before = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(find(from) != find(to)){
            merge(from, to);
            result+=cost;
            before = cost;
        }
    }
    cout << result - before;
}