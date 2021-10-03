//문제 16398번 행성 연결 -> 최소 스패닝 트리, 크루스칼
#include <vector>
vector<pair<int,pair<int,int>>>v;
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
    int n;
    long long result = 0;
    cin >> n;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int cost;
            cin >> cost;
            if(i<j)
                v.push_back({cost,{i, j}});
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<v.size();i++){
        int gx = v[i].second.first;
        int gy = v[i].second.second;
        int cost = v[i].first;
        if(find(gx) != find(gy)){
            merge(gx, gy);
            result+=cost;
        }
    }
    cout << result;
}