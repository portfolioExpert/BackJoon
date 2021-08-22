//문제 10282번 해킹 -> 다익스트라
//마지막으로 감염된 컴퓨터를 못찾아서 계속 틀림
#include <vector>
#include <queue>
int n, d, c;
int dp[10001];
void dijkstra(int go, vector<pair<int,int>>v[]){
    priority_queue<pair<int,int>>pq;
    pq.push({0, go});
    dp[go] = 0;
    while(!pq.empty()){
        int gogo = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0;i<v[gogo].size();i++){
            int next = v[gogo][i].first;
            int nextcost = cost + v[gogo][i].second;
            if(dp[next] > nextcost){
                dp[next] = nextcost;
                pq.push({-nextcost, next});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> d >> c;
        fill_n(dp, n+1, 987654321);
        vector<pair<int,int>>v[10001];
        for(int i = 0;i<d;i++){
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a,s});
        }
        dijkstra(c, v);
        int cnt = 0, value = 0;
        for(int i = 1;i<=n;i++){
            if(dp[i] != 987654321){
                cnt++;
                if(dp[i] > value)
                    value = dp[i];
            }
        }
        cout << cnt << " " << value << "\n";
    }
}