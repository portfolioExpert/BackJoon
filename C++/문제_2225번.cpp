#include <iostream>
#include <algorithm>
using namespace std;

//2225번 합분해 문제 해결
typedef long long ll;
ll dp[201][201];
int main(){
    ll n,c, i, j;
    cin >> n >> c;
    for(i=1;i<=200;i++){
        dp[i][1] = 1;
        dp[1][i] = i;
    }
    for(i=2;i<=n;i++){
        for(j=2;j<=c;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }
    cout << dp[n][c];
    return 0;
}