#include <iostream>
#include <algorithm>
using namespace std;

//문제 1937번
//최대 길이를 이용하는 경우는 dp, dfs를 이용한다
#include <cstring>
int map[501][501];
int dp[501][501];
int n, result = -1;
int dx[4] = {1 ,-1 ,0 ,0};
int dy[4] = {0 ,0 ,1 ,-1};
int dfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            result = max(result, dfs(i,j));
        }
    }
    cout << result;
}
int dfs(int x, int y){
    if(dp[x][y] != -1)return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0;i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        if(gox>=0 && gox < n && goy>=0 && goy < n){
            if(map[x][y] < map[gox][goy]){
                dp[x][y] = max(dp[x][y], dfs(gox, goy) + 1);
            }
        }
    }
    return dp[x][y];
}
//bfs로 풀이했다가 메모리초과, 시간초과
//void bfs(int x, int y){
//    q.push({x, y});
//    //int val = dp[x][y];
//    dp[x][y] = 1;
//    while(!q.empty()){
//        int gox = q.front().first;
//        int goy = q.front().second;
//        q.pop();
//        for(int i = 0;i<4;i++){
//            int gx = gox + dx[i];
//            int gy = goy + dy[i];
//            if(gx >= 0 && gx < n && gy >= 0 && gy < n){
//                if(dp[gx][gy] > dp[gox][goy] + 1)
//                    continue;
//                //해당 칸에 있는 숫자가 더 크고, dp로 방문을 이미 하고 그 숫자가 작으면 성립
//                if(map[gox][goy] < map[gx][gy]){
//                    dp[gx][gy] = dp[gox][goy] + 1;
//                    result = max(result, dp[gx][gy]);
//                    q.push({gx, gy});
//                }
//            }
//        }
//    }
//}