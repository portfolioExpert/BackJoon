#include <iostream>
#include <algorithm>
using namespace std;

//문제 11052번
int dp[1001];
int main(){
    int n, i,j, price[1001];
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> price[i];
    }
    dp[1] = price[1];
    dp[2] = max(price[2], dp[1] + price[1]);
    for(i=3;i<=n;i++){
        for(j=1;j<i;j++){
            dp[i] = max(dp[i-j] + dp[j], dp[i]);
        }
        dp[i] = max(dp[i], price[i]);
    }
    cout << dp[n];
    return 0;
}