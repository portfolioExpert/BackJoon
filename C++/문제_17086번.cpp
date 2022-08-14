//문제 17086번 아기 상어 2 ->BFS
#include<queue>
#include <cstring>
queue<pair<int,int>>q;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0 ,0, 1, -1, 1, -1, 1, -1};
int map[51][51];
int dp[51][51];
int result = 0, n, m;
void bfs(){
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<8;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < m && map[gx][gy] == 0 && dp[gx][gy] == -1){
                dp[gx][gy] = dp[gox][goy] + 1;
                q.push({gx,gy});
                result = max(result, dp[gx][gy]);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<n;i++){
        for(int j = 0 ;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push({i, j});
                dp[i][j] = 0;
            }
        }
    }
    bfs();
    cout << result;
}