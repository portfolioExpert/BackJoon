#include <iostream>
#include <algorithm>
using namespace std;

//문제 1149번
int dp[1001][3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, colar[1001][3];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> colar[i][0] >> colar[i][1] >> colar[i][2];
    }
    dp[0][0] = colar[0][0];
    dp[0][1] = colar[0][1];
    dp[0][2] = colar[0][2];
    for(i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + colar[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + colar[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + colar[i][2];
    }
    cout << min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    return 0;
}