//문제 1600번 말이 되고픈 원숭이 -> bfs 이용하고 w, h 값을 확인 잘할 것
#include <cstring>
#include <queue>
queue<pair<pair<int,int>,int>>q;
int dp[201][201][31];
int map[201][201];
int w, h, k;
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0, 1, -1};
int hx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
void bfs(){
    q.push({{0, 0},k});
    dp[0][0][k] = 0;
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt >= 1){
            for(int i = 0;i<8;i++){
                int gx = gox + hx[i];
                int gy = goy + hy[i];
                if(gx >= 0 && gx < h && gy >= 0 && gy < w && map[gx][gy] == 0 && dp[gx][gy][cnt-1] == -1){
                    q.push({{gx, gy},cnt - 1});
                    dp[gx][gy][cnt-1] = dp[gox][goy][cnt] + 1;
                }
            }
        }
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < h && gy >= 0 && gy < w && map[gx][gy] == 0 && dp[gx][gy][cnt] == -1){
                dp[gx][gy][cnt] = dp[gox][goy][cnt] + 1;
                q.push({{gx, gy}, cnt});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    cin >> w >> h;
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin >> map[i][j];
        }
    }
    bfs();
    int result = 987654321;
    for(int i = 0;i<=k;i++){
        if(dp[h-1][w-1][i] != -1)
            result = min(result, dp[h-1][w-1][i]);
    }
    if(result == 987654321)
        cout << -1;
    else
        cout << result;
}