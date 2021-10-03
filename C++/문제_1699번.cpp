#include <iostream>
#include <algorithm>
using namespace std;

//문제 1699번, 제곱근 dp를 확인해주면 된다.
int dp[100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, i, j;
    cin >> n;
    fill_n(dp, 100001, 987654321);
    for(i=1;i * i<=n;i++){
        dp[i * i] = 1;
    }
    for(i=2;i<=n;i++){
        for(j=1;j * j<=i;j++){
            dp[i] = min(dp[i], dp[j * j] + dp[i-j*j]);
        }
    }
    cout << dp[n];
}