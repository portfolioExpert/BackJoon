#include <iostream>
#include <algorithm>
using namespace std;

//문제 9507번
typedef long long ll;
ll dp[67];
int main(){
    int n, i, num;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(i=4;i<=67;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    for(i=0;i<n;i++){
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;
}