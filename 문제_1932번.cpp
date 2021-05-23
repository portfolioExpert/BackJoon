#include <iostream>
#include <algorithm>
using namespace std;

//문제 1932번
int dp[501][501];
int main(){
    int n, i , j, result = -1;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cin >> dp[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(j==1){
                dp[i][1]+=dp[i-1][1];
            }
            else if(j == i)
                dp[i][j]+=dp[i-1][j-1];
            else{
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
            result = max(result,dp[i][j]);
        }
    }
    cout << result;
    return 0;
}