#include <iostream>
#include <algorithm>
using namespace std;

//문제 1238번
#include <vector>
#include <queue>
int dp[1001];
int go[1001];
priority_queue<pair<int ,int>> pq;
vector <pair<int,int>> v[1001];
void dijkstra(int from);
int result;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m ,x, i;
    cin >> n >> m >> x;
    for(i=0;i<m;i++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        v[num1].push_back({num2, val});
    }
    for(i=1;i<=n;i++){
        fill_n(dp, 1002, 1000000000);
        dijkstra(i);
        go[i] = dp[x];
    }
    fill_n(dp, 1002, 1000000000);
    dijkstra(x);
    for(i=1;i<=n;i++){
        result = max(result, go[i] + dp[i]);
    }
    cout << result;
    return 0;
}
void dijkstra(int from){
    dp[from] = 0;
    pq.push({0, from});
    while(!pq.empty()){
        int pos = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        if(dp[pos] < val)continue;
        for(int i=0;i<v[pos].size();i++){
            int near = v[pos][i].first;
            int cost = v[pos][i].second + val;
            if(cost < dp[near]){
                dp[near] = cost;
                pq.push({-cost, near});
            }
        }
    }
}