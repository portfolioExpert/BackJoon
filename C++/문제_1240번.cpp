#include <iostream>
#include <algorithm>
using namespace std;

//문제 1240번 노드사이의 거리 ->BFS
#include <vector>
#include <cstring>
#include <queue>
bool visit[1001];
int dp[1001];
int bfs(int start, int goal, vector<pair<int,int>>v[]){
    queue<int>q;
    q.push(start);
    visit[start] = 1;
    dp[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == goal)
            break;
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i].first;
            int cost = v[now][i].second;
            if(visit[next] == 0){
                visit[next] = 1;
                q.push(next);
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
    vector<pair<int,int>>v[1001];
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n - 1;i++){
        int from, to , cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    for(int i = 0;i<m;i++){
        memset(visit, 0, sizeof(visit));
        for(int j = 0;j<=1000;j++){
            dp[j] = 0;
        }
        int from, to;
        cin >> from >> to;
        cout << bfs(from, to, v) << "\n";
    }
}