//문제 15591번 MooTube(Silver) -> BFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
bool visit[5001];
int n;
int bfs(vector<pair<int, int>>v[], int k, int start){
    memset(visit, 0, sizeof(visit));
    visit[start] = 1;
    queue<int>q;
    q.push(start);
    int res = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<v[now].size();i++){
            int next = v[now][i].first;
            int cost = v[now][i].second;
            if(k <= cost && visit[next] == 0){
                visit[next] = 1;
                q.push(next);
                res++;
            }
        }
    }
    return res;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<pair<int, int>>v[5001];
    int q;
    cin >> n >> q;
    for(int i =0;i<n-1;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    for(int i = 0;i<q;i++){
        int k, start;
        cin >> k >> start;
        cout << bfs(v, k, start) << "\n";
    }
}