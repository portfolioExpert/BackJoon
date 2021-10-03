#include <iostream>
#include <algorithm>
using namespace std;

//문제 11048번
int map[1001][1001];
int dp[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i, j;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> map[i][j];
            dp[i][j] = map[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j] + map[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + map[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1] + map[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}