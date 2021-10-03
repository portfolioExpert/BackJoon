#include <iostream>
#include <algorithm>
using namespace std;

//문제 11051번
//이항계수 : nCr = n-1Cr-1 + n-1Cr
int dp[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        dp[i][1] = i;
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    cout << dp[n][k];
}