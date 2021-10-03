#include <iostream>
#include <algorithm>
using namespace std;

//문제 1904번
int dp[1000001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[n];
}
