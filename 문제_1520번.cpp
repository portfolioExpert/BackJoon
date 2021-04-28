#include <iostream>
#include <algorithm>
using namespace std;

//문제 1520번
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
int map[501][501], n, m;
int dp[501][501];
int dfs(int x, int y);
int main(){
    int i, j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0,0);
    for(i = 0; i<n;i++){
        for(j=0;j<m;j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
int dfs(int x, int y){
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    if(x == n-1 && y == m - 1)//도착하면 1 반환
        return 1;
    dp[x][y] = 0;
    for(int i = 0; i<4;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx>=0 && gx < n && gy>=0 && gy<m && map[x][y] > map[gx][gy]){
            dp[x][y] += dfs(gx, gy);
        }
    }
    return dp[x][y];
}