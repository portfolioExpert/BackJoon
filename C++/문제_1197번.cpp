//문제 1197번 최소 스패닝 트리 -> 크루스칼 해법
#include <queue>
#include <vector>
priority_queue<pair<int,pair<int,int>>>pq;
int v, e;
int parent[10001];
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
    long long result = 0;
    cin >> v >> e;
    for(int i = 1;i<=v;i++){
        parent[i] = i;
    }
    for(int i = 0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c,{a,b}});
    }
    while(!pq.empty()){
        int weight = -pq.top().first;
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        pq.pop();
        if(find(node1) != find(node2)){
            merge(node1, node2);
            result+=weight;
        }
        else
            continue;
    }
    cout << result;
}