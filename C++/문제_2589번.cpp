#include <iostream>
#include <algorithm>
using namespace std;

//문제 2589번
#include <queue>
#include <cstring>
queue <pair<int,int>> q;
char map[51][51];
int dp[51][51], n, m;
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
int bfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j, val = 0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j] == 'L'){
                val = max(val,bfs(i, j));
                memset(dp, 0, sizeof(dp));
            }
        }
    }
    cout << val;
    return 0;
}
int bfs(int x, int y){
    int result = 0;
    q.push({x, y});
    dp[x][y] = 1;//0으로 하면 두번째 방문할 때 다시 방문을 하게 되므로 방지하기 위해서
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >=0 && gx < n && gy>= 0 && gy < m && dp[gx][gy] == 0 && map[gx][gy] == 'L'){
                q.push({gx, gy});
                dp[gx][gy] = dp[gox][goy] + 1;
                result = max(result, dp[gx][gy]);
            }
        }
    }
    return result - 1;
}