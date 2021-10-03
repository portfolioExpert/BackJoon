//문제 1922번 네트워크 연결 -> 최소 스패닝 트리(크루스칼) 기본
#include <vector>
#include <queue>
vector<int>v[1001];
int parent[1001];
priority_queue<pair<int,pair<int,int>>>pq;
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        parent[node2] = node1;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a, b , c;
        cin >> a >> b >> c;
        pq.push({-c,{a,b}});
    }
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        int cost = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if(find(from) != find(to)){
            merge(from, to);
            result+=cost;
        }
    }
    cout << result;
}