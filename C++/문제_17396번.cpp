//문제 17396번 백도어 -> 다익스트라
typedef long long ll;
#include <vector>
#include <queue>
vector<pair<int,int>>v[100001];
bool sight[100001];
ll dp[100001];
int n, m;
void dijkstra(){
    priority_queue<pair<ll,int>>pq;
    dp[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int now = pq.top().second;
        ll weight = -pq.top().first;
        pq.pop();
        if(dp[now] < weight)
            continue;
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i].first;
            ll cost = v[now][i].second + weight;
            if(dp[next] > cost){
                dp[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> sight[i];
        dp[i] = 1e10;
    }
    for(int i = 0;i<m;i++){
        int from, to , cost;
        cin >> from >> to >> cost;
        if(sight[from] || sight[to]){
            if(from != n-1 && to != n-1)
                continue;
        }
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    dijkstra();
    if(dp[n-1] == 1e10)
        cout << -1;
    else
        cout << dp[n-1];
}