//문제 17142번 연구소3 -> bfs, 백트래킹
#include <queue>
#include <vector>
#include <cstring>
int n, m;
vector<pair<int,int>>able;
vector<pair<int,int>>virus;
vector<pair<int,int>>blank;
bool visit[11];
int map[51][51];
int visited[51][51];
int result = 987654321;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bfs(){
    int res = 0;
    memset(visited, -1, sizeof(visited));
    queue<pair<int,int>>q;
    for(int i = 0;i<able.size();i++){
        q.push({able[i].first, able[i].second});
        visited[able[i].first][able[i].second] = 0;
    }
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < n && visited[gx][gy] == -1 && (map[gx][gy] == 0 || map[gx][gy] == 2)){
                visited[gx][gy] = visited[gox][goy] + 1;
                q.push({gx,gy});
                //빈칸인 경우만 채우는걸 고려하면된다
                if(map[gx][gy] == 0)
                    res = max(res, visited[gx][gy]);
            }
        }
    }
    return res;
}
void dfs(int cnt, int index){
    if(cnt == m){
        int maxtime = bfs();
        for(int i = 0;i<blank.size();i++){
            int x = blank[i].first;
            int y = blank[i].second;
            if(visited[x][y] == -1)
                return;
        }
        result = min(result, maxtime);
        return;
    }
    for(int i = index + 1;i<virus.size();i++){
        able.push_back(virus[i]);
        dfs(cnt + 1, i);
        able.pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push_back({i, j});
            if(map[i][j] == 0)
                blank.push_back({i, j});
        }
    }
    for(int i = 0;i<virus.size();i++){
        able.push_back({virus[i]});
        dfs(1, i);
        able.pop_back();
    }
    if(result == 987654321)
        cout << -1;
    else
        cout << result;