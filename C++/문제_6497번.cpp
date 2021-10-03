//문제 6497번 전력난 -> 최소 스패닝 트리
#include <queue>
priority_queue<pair<int,pair<int,int>>>pq;
int parent[200001];
int n,m;
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
    while(true){
        cin >> m >> n;
        int result = 0;
        int sum = 0;
        if(m == 0 && n == 0)
            break;
        for(int i = 0;i<m;i++){
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            int num1, num2, cost;
            cin >> num1 >> num2 >> cost;
            pq.push({-cost,{num1, num2}});
            sum+=cost;
        }
        while(!pq.empty()){
            int weight = -pq.top().first;
            int from = pq.top().second.first;
            int to = pq.top().second.second;
            pq.pop();
            if(find(from) != find(to)){
                merge(from, to);
                result+=weight;
            }
        }
        cout << sum - result << "\n";
    }
}