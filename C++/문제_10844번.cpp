#include <iostream>
#include <algorithm>
using namespace std;

//문제 10844번
typedef long long ll;
long long dp[101][11];//앞은 자리갯수 뒤는 마지막자리 숫자
int main(){
    int n, i, j;
    cin >> n;
    for(i=1;i<=9;i++){
        dp[1][i] = 1;
    }
    for(i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        for(j=1;j<=9;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }
    ll sum = 0;
    for(i=0;i<10;i++){
        sum += dp[n][i];
    }
    cout << sum % 1000000000;
}