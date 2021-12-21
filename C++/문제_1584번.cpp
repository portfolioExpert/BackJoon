//문제 1584번 게임 -> BFS
#include <cstring>
#include <queue>
int map[501][501];
bool visit[501][501];
int dp[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(){
    queue<pair<int,int>>q;
    q.push({0,0});
    dp[0][0] = 0;
    visit[0][0] = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox+dx[i];
            int gy = goy+dy[i];
            if(gx >= 0 && gx < 501 && gy >= 0 && gy < 501){
                if(map[gx][gy] == 0 && dp[gx][gy] > dp[gox][goy]){
                    q.push({gx,gy});
                    dp[gx][gy] = dp[gox][goy];
                    visit[gx][gy] = 1;
                }
                else if(map[gx][gy] == 1 && dp[gx][gy] > dp[gox][goy] + 1){
                    q.push({gx,gy});
                    dp[gx][gy] = dp[gox][goy]  + 1;
                    visit[gx][gy] = 1;
                }
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n;
    for(int i = 0;i<=500;i++){
        for(int j = 0;j<=500;j++){
            dp[i][j] = 987654321;
        }
    }
    for(int i = 0 ;i<n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = min(x1, x2);i<=max(x1, x2);i++){
            for(int j = min(y1,y2);j<=max(y1,y2);j++){
                map[i][j] = 1;
            }
        }
    }
    cin >> m;
    for(int i = 0 ;i<m;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = min(x1, x2);i<=max(x1, x2);i++){
            for(int j = min(y1,y2);j<=max(y1,y2);j++){
                map[i][j] = 2;
            }
        }
    }
    bfs();
    if(dp[500][500] == 987654321)
        cout << -1;
    else
        cout << dp[500][500];
}