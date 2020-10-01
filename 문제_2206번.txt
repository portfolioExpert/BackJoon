#include <iostream>
#include <algorithm>
using namespace std;

//문제 2206번
#include <queue>
queue <pair<pair<int, int>, int>> q;
char map[1001][1001];
int dp[1001][1001][2];
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int bfs(int x, int y);
int n , m, vx, vy;
int main(){
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    q.push({{0, 0}, 1});
    dp[0][0][1] = 1;
    cout << bfs(0,0);
    return 0;
}
int bfs(int x, int y){
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if(gox == n - 1 && goy == m - 1)
            return dp[n-1][m-1][block];
        for(int i = 0;i < 4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < n && gy >= 0 && gy < m){
                if(map[gx][gy] == '0' && dp[gx][gy][block] == 0){
                    q.push({{gx, gy}, block});
                    dp[gx][gy][block] = dp[gox][goy][block] + 1;
                }
                else if(map[gx][gy] == '1' && block == 1){
                    q.push({{gx,gy}, block - 1});
                    dp[gx][gy][block-1] = dp[gox][goy][block] + 1;
                }
            }
        }
    }
    return -1;
}