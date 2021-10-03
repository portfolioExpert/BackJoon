//문제 5719번 거의 최단 거리 -> 다익스트라 + dfs로 경로 제거
#include <queue>
#include <vector>
#include <cstring>
int s, d;
int dp[501];
bool visit[501];
void dijkstra(int go, vector<pair<int,int>> v[], vector<pair<int, int>> trace[]);
void dfs(int go, vector<pair<int,int>> v[], vector<pair<int, int>> trace[]);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    while(1){
        int n, m;
        vector<pair<int, int>> v[501];
        vector<pair<int, int>> trace[501];
        memset(visit, 0, sizeof(visit));
        fill_n(dp, 501, 987654321);
        cin >> n >> m;
        if(n == 0 && m == 0)break;
        cin >> s >> d;
        for(int i = 0;i<m;i++){
            int from, to, val;
            cin >> from >> to >> val;
            v[from].push_back({to, val});
        }
        dijkstra(s, v, trace);
        fill_n(dp, 501, 987654321);
        dfs(d, v, trace);
        dijkstra(s, v, trace);
        if(dp[d] == 987654321)
            cout << -1 << "\n";
        else
            cout << dp[d] << "\n";
    }
}
void dijkstra(int go, vector<pair<int,int>> v[], vector<pair<int, int>> trace[]){
    priority_queue<pair<int, int>>pq;
    dp[go] = 0;
    pq.push({0 , go});
    trace[go].push_back({s,0});
    while(!pq.empty()){
        int gogo = pq.top().second;//현재 노드
        int cost = -pq.top().first;//현재까지 가중치
        pq.pop();
        if(dp[gogo] < cost)continue;
        for(int i = 0;i<v[gogo].size();i++){
            int near = v[gogo][i].first;//주변 노드
            int val = v[gogo][i].second + cost;//주변 노드로 가는 가중치
            //가중치가 -1 인것은 제외된 경로이므로 없애준다
            if(v[gogo][i].second == -1)continue;
            //최단거리가 같을경우 지우지않고 더 푸시한다
            //이 경로도 지워야하므로 더 푸시
            if(dp[near] == val){
                //거꾸로 푸시 해줘야한다
                //i는 v에 저장하기 위한 인덱스
                trace[near].push_back({gogo, i});
            }
            else if(dp[near]>val){
                //추적을 하여 1 2면 2 1위치에 지금까지 최단거리를 지우고 새로 넣는다
                trace[near].clear();
                trace[near].push_back({gogo, i});
                pq.push({-val, near});
                dp[near] = val;
            }
        }
    }
}
void dfs(int go, vector<pair<int,int>> v[], vector<pair<int, int>> trace[]){
    if(go == s)return;
    if(visit[go] == 1)
        return;
    visit[go] = 1;
    for(int i = 0;i<trace[go].size();i++){
        int a = trace[go][i].first;
        int b = trace[go][i].second;
        v[a][b].second = -1;
        dfs(a, v, trace);
    }
}