//문제 2146번
#include <queue>
#include <cstring>
int n, cnt = 1, result = 987654321;
int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};
int map[101][101];
int dp[101][101];
int visit[101][101];
void dfs(int x, int y);
void bfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                dfs(i, j);
                cnt++;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(visit[i][j] != 0){
                bfs(i, j);
                memset(dp, 0, sizeof(dp));
            }
        }
    }
    cout << result;
}
void dfs(int x, int y){
    visit[x][y] = cnt;
    for(int i = 0;i<4;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx >= 0 && gx < n && gy >= 0 && gy < n && visit[gx][gy] == 0 && map[gx][gy] == 1){
            dfs(gx, gy);
        }
    }
}
void bfs(int x, int y){
    queue<pair<int ,int>>q;
    q.push({x, y});
    dp[x][y] = 0;
    int state = visit[x][y];
    while(!q.empty()){
        int gx = q.front().first;
        int gy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gox = gx + dx[i];
            int goy = gy + dy[i];
            if(gox >= 0 && gox < n && goy >= 0 && goy < n){
                if(map[gox][goy] == 0 && dp[gox][goy] == 0){
                    q.push({gox, goy});
                    dp[gox][goy] = dp[gx][gy] + 1;
                }
                if(visit[gox][goy] != 0 && state != visit[gox][goy]){
                    result = min(result, dp[gx][gy]);
                    return;
                }
            }
        }
    }
}