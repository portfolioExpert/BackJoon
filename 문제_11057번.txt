#include <iostream>
#include <algorithm>
using namespace std;

//문제 11057번
int dp[1001][11];
int main(){
    int n, i, j, k;
    cin >>n;
    for(i=0;i<10;i++){
        dp[1][i] = 1;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<10;j++){
            for(k=j;k<10;k++){
                dp[i][j]+=dp[i-1][k] % 10007;
            }
        }
    }
    int sum = 0;
    for(i=0;i<10;i++){
        sum+=dp[n][i];
    }
    cout << sum % 10007;
    return 0;
}