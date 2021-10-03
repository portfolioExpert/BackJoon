//문제 1774번 우주신과의 교감 -> 최소 스패닝 트리 -> 크루스칼
#include <queue>
#include <vector>
#include <cmath>
vector<pair<long long,long long>>v;
priority_queue<pair<double, pair<int,int>>>pq;
int parent[1001];
double result;
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
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<n;i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0;i<m;i++){
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            if(i != j){
                long long dx = v[i].first - v[j].first;
                long long dy = v[i].second - v[j].second;
                long long dis = pow(dx, 2) + pow(dy, 2);
                long double cost = sqrt(dis);
                pq.push({-cost, {i+1 , j+1}});
            }
        }
    }
    while(!pq.empty()){
        double cost =-pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(find(x) != find(y)){
            merge(x, y);
            result+=cost;
        }
    }
    printf("%.2lf", result);
}