//문제 16562번 친구비 -> 유니온파인드
#include <vector>
vector<int>v[10001];
int parent[10001];
vector<pair<int,int>> cost;
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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 1;i<=n;i++){
        int weight;
        cin >> weight;
        cost.push_back({weight, i});
    }
    sort(cost.begin(), cost.end());
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        merge(num1, num2);
    }
    int result = 0;
    for(int i = 0;i<cost.size();i++){
        if(0 != find(cost[i].second)){
            merge(0, cost[i].second);
            result+=cost[i].first;
        }
    }
    if(result <= k)
        cout << result;
    else
        cout << "Oh no";
}