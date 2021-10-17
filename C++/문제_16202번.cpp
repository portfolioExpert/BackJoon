//문제 16202번 mst게임 -> 최소 스패닝 트리
#include <queue>
#include <vector>
vector<pair<int,pair<int,int>>>v;
int n, m;
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
    int k;
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++){
        int num1 ,num2;
        cin >> num1 >> num2;
        v.push_back({i + 1,{num1, num2}});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<k;i++){
        int result = 0;
        for(int j = 1;j<=n;j++){
            parent[j] = j;
        }
        for(int j = i; j<v.size();j++){
            int node1 = v[j].second.first;
            int node2 = v[j].second.second;
            int cost = v[j].first;
            if(find(node1) != find(node2)){
                merge(node1, node2);
                result += cost;
            }
        }
        bool flag = true;
        for(int j = 1;j<=n;j++){
            if(find(1) != find(j))
                flag = false;
        }
        if(flag)
            cout << result << " ";
        else
            cout << 0 << " ";
    }
}