//문제 18223번 민준이와 마산 그리고 건우 -> 다익스트라
#include <vector>
#include <queue>
vector<pair<int,int>>node[5001];
int v, e, p;
int dp[5001];
int dijkstra(int go, int goal){
    for(int i = 1;i<=v;i++){
        dp[i] = 987654321;
    }
    dp[go] = 0;
    priority_queue<int>pq;
    pq.push(go);
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        for(int i = 0;i<(int)node[now].size();i++){
            int next = node[now][i].first;
            int cost = node[now][i].second;
            if(dp[next] > dp[now] + cost){
                pq.push(next);
                dp[next] = dp[now] + cost;
            }
        }
    }
    return dp[goal];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> v >> e >> p;
    for(int i = 0;i<e;i++){
        int a, b ,c;
        cin >> a >> b >> c;
        node[a].push_back({b,c});
        node[b].push_back({a,c});
    }
    if(dijkstra(1, p) + dijkstra(p, v) <= dijkstra(1, v)){
        cout << "SAVE HIM";
    }
    else
        cout << "GOOD BYE";
}