//문제 14442번 벽 부수고 이동하기2
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct pos{
    int x, y, cnt;
}pos;
#include <queue>
queue <pos> q;
char map[1001][1001];
int dp[1001][1001][11];
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int bfs();
int n , m, vx, vy, k;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j;
    cin >> n >> m >> k;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    pos start;
    start.cnt = k;
    start.x = 0;
    start.y = 0;
    q.push(start);
    dp[0][0][k] = 1;
    cout << bfs();
    return 0;
}
int bfs(){
    while(!q.empty()){
        pos tmp = q.front();
        int gox = tmp.x;
        int goy = tmp.y;
        int block = tmp.cnt;
        pos save;
        if(gox == n - 1 && goy == m - 1)return dp[n-1][m-1][block];
        q.pop();
        for(int i = 0;i < 4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < n && gy >= 0 && gy < m){
                if(map[gx][gy] == '0' && map[gx][gy] == '0' && dp[gx][gy][block] == 0){
                    save.x = gx;
                    save.y = gy;
                    save.cnt = tmp.cnt;
                    q.push(save);
                    dp[gx][gy][block] = dp[gox][goy][block] + 1;
                }
                else if(map[gx][gy] == '1' && dp[gx][gy][block - 1] == 0 && block >= 1){
                    save.x = gx;
                    save.y = gy;
                    save.cnt = block - 1;
                    q.push(save);
                    dp[gx][gy][block - 1] = dp[gox][goy][block] + 1;
                }
            }
        }
    }
    return -1;
}