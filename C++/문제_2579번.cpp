#include <iostream>
#include <algorithm>
using namespace std;

//문제 2579번
int dp[301];
int main(){
    int n, step[301], i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> step[i];
    }
    dp[0] = step[0];
    dp[1] = step[0] + step[1];
    dp[2] = max(step[0], step[1]) + step[2];
    for(i=3;i<n;i++){
        dp[i] = max(dp[i-2], dp[i-3] + step[i-1]) + step[i];
    }
    cout << dp[n-1];
    return 0;
}