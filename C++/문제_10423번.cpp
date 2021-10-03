//문제 10423번 전기가 부족해 -> 최소 스패닝 트리 응용
#include <queue>
priority_queue<pair<int,pair<int,int>>>pq;
int n, m, k;
int parent[1001];
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
    int result = 0;
    cin >> n >> m >> k;
    int before = 0;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<k;i++){
        int num;
        cin >> num;
        if(before != 0)
            merge(before, num);
        before = num;
    }
    for(int i = 0;i<m;i++){
        int num1, num2, cost;
        cin >> num1 >> num2 >> cost;
        pq.push({-cost,{num1, num2}});
    }
    while(!pq.empty()){
        int gx = pq.top().second.first;
        int gy = pq.top().second.second;
        int weight = -pq.top().first;
        pq.pop();
        if(find(gx) != find(gy)){
            merge(gx, gy);
            result+=weight;
        }
    }
    cout << result;
}