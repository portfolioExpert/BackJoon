#include <iostream>
#include <algorithm>
using namespace std;

//문제 17485번
int map[1001][1001];
int dp[1001][1001][3] , result = 987654321, n ,m;
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        fill_n(dp[i][0], m * 3, 987654321);
    }
    for(i = 0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    //초깃값
    for(i=0;i<m;i++){
        dp[0][i][0] = map[0][i];
        dp[0][i][1] = map[0][i];
        dp[0][i][2] = map[0][i];
    }
    for(i=0;i<n - 1;i++){
        for(j=0;j<m;j++){
            for(int k=0;k<3;k++){
                int gx = i + dx[k];
                int gy = j + dy[k];
                if(gx >= 0 && gx < n && gy >= 0 && gy < m){
                    if(k == 0){
                        dp[gx][gy][k] = min(dp[gx][gy][k], min(dp[i][j][1], dp[i][j][2])) + map[gx][gy];
                    }
                    if(k == 1){
                        dp[gx][gy][k] = min(dp[gx][gy][k], min(dp[i][j][0], dp[i][j][2])) + map[gx][gy];
                    }
                    if(k == 2){
                        dp[gx][gy][k] = min(dp[gx][gy][k] , min(dp[i][j][0], dp[i][j][1])) + map[gx][gy];
                    }
                }
            }
        }
    }
    for(i = 0;i<m;i++){
        for(j = 0;j<3;j++){
            result = min(result, dp[n-1][i][j]);
        }
    }
    cout << result;
}