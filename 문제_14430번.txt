#include <iostream>
#include <algorithm>
using namespace std;

//문제 14430번
int dp[301][301];
int main(){
    int n, m, map[301][301], i , j;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> map[i][j];
        }
    }
    for(i=1;i<=m;i++){
        dp[1][i] = dp[1][i-1] + map[1][i];
    }
    for(i=1;i<=n;i++){
        dp[i][1] = dp[i-1][1] + map[i][1];
    }
    for(i=2;i<=n;i++){
        for(j=2;j<=m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(map[i][j] == 1)dp[i][j]++;
        }
    }
    cout << dp[n][m];
    return 0;
}