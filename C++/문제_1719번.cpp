//문제 1719번 택배 -> 다익스트라
#include <queue>
#include <vector>
vector<pair<int,int>>v[201];
int dp[201];
bool linked[201][201];
int value[201][201];
int before[201];
int followBefore(int go, int node){
    if(linked[go][node] && value[go][node] <= dp[node])
        return node;
    return followBefore(go, before[node]);
}
void dijkstra(int go){
    priority_queue<pair<int,int>>pq;
    pq.push({0, go});
    dp[go] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i].first;
            int weight = cost + v[now][i].second;
            if(dp[next] > weight){
                before[next] = now;
                pq.push({-weight, next});
                dp[next] = weight;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        dp[i] = 987654321;
    }
    for(int i = 0;i<m;i++){
        int num1, num2, weight;
        cin >> num1 >> num2 >> weight;
        v[num1].push_back({num2, weight});
        v[num2].push_back({num1, weight});
        linked[num1][num2] = 1;
        linked[num2][num1] = 1;
        value[num1][num2] = weight;
        value[num2][num1] = weight;
    }
    for(int i = 1;i<=n;i++){
        fill_n(dp, n + 1, 987654321);
        dijkstra(i);
        before[i] = 0;
        for(int j = 1;j<=n;j++){
            if(i == j)
                cout << "- ";
            else
                cout << followBefore(i, j) << " ";
        }
        cout << "\n";
    }
}