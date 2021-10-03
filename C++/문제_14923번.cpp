//문제 14923번 미로 탈출
#include <queue>
queue<pair<pair<int,int>, int>>q;
int map[1001][1001];
int dp[1001][1001][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n ,m;
int startx, starty, endx, endy;
int bfs(int x, int y){
    q.push({{x, y}, 1});
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if(gox == endx - 1 && goy == endy - 1)return dp[gox][goy][block];
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy>=0 && gy < m){
                //블록을 못깨고 길일때
                if(map[gx][gy] == 0 && dp[gx][gy][block] == 0){
                    q.push({{gx,gy},block});
                    dp[gx][gy][block] = dp[gox][goy][block] + 1;
                }
                //블록을 깰 수 있고 벽일때
                else if(map[gx][gy] == 1 && block == 1){
                    q.push({{gx,gy}, 0});
                    dp[gx][gy][0] = dp[gox][goy][block] + 1;
                }
            }
        }
    }
    return -1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> startx >> starty >> endx >> endy;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    cout << bfs(startx - 1, starty - 1);
}