//문제 2157번 여행 문제 바텀업
#include <iostream>
#include <algorithm>
using namespace std;
#include <cstring>
#include <vector>
#include <queue>
vector<pair<int,int>> v[301];
int dp[301];
int n, m, k;
int dijkstra(int start){
    queue<pair<pair<int,int>,int>>q;
    dp[start] = 0;
    q.push({{0, start},1});
    while(!q.empty()){
        int go = q.front().first.second;
        int cost = q.front().first.first;
        int cnt = q.front().second;
        q.pop();
        for(int i = 0;i<v[go].size();i++){
            int dest = v[go][i].first;
            int value = v[go][i].second + cost;
            if(dp[dest] < value && cnt + 1 <= m){
                dp[dest] = value;
                q.push({{value, dest}, cnt + 1});
            }
        }
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int i;
    cin >> n >> m >> k;
    memset(dp, -1 ,sizeof(dp));
    for (i = 0; i < k; i++) {
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        if(num2 < num1)continue;
        v[num1].push_back({num2, val});
    }
    cout << dijkstra(1);
    return 0;
}