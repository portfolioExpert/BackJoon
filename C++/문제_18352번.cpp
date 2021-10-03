//문제 18352번 특정 거리의 도시 찾기 -> 다익스트라
#include <vector>
#include <queue>
priority_queue<pair<int,int>>pq;
vector<pair<int,int>>v[300001];
int dp[300001];
int n, m, k, x;
void dijkstra(int go){
    pq.push({0, go});
    dp[go] = 0;
    while(!pq.empty()){
        int gogo = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0; i<v[gogo].size();i++){
            int weight = cost + v[gogo][i].second;
            int next = v[gogo][i].first;
            if(dp[next] > weight){
                dp[next] = weight;
                pq.push({-weight, next});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m>> k >>x;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back({num2,1});
    }
    for(int i = 1;i<=n;i++){
        dp[i] = 987654321;
    }
    dijkstra(x);
    bool flag = false;
    for(int i = 1;i<=n;i++){
        if(dp[i] == k){
            cout << i << "\n";
            flag = true;
        }
    }
    if(!flag)
        cout << -1;
}