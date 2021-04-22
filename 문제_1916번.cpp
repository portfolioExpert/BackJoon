#include <iostream>
#include <algorithm>
using namespace std;

//문제 1916번
#include <vector>
#include <queue>
priority_queue<pair<int ,int>>pq;
vector <pair<int, int>> v[1001];
int dp[1001];
void dijkstra(int from);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    cin >> n >> m;
    fill_n(dp, 1001, 1000000000);
    for(i=0;i<m;i++){
        int num1, num2, weight;
        cin >> num1 >> num2 >> weight;
        v[num1].push_back({num2,weight});
    }
    int from, to;
    cin >> from >> to;
    pq.push({0, from});
    dijkstra(from);
    cout << dp[to];
    return 0;
}
void dijkstra(int from){
    dp[from] = 0;
    while(!pq.empty()){
        int pos = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        if(dp[pos] < val)continue;
        for(int i=0;i<v[pos].size();i++){
            int near = v[pos][i].first;
            int wei = v[pos][i].second + val;
            if(wei < dp[near]){
                dp[near] = wei;
                pq.push({-wei, near});
            }
        }
    }
}