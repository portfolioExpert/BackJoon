#include <iostream>
#include <algorithm>
using namespace std;

//문제 1010번 바텀업
#include <cstring>
int dp[31][31];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t, i, j;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for(i = 1;i<=30;i++){
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for(i=2;i<=30;i++){
        for(j=2;j<=i;j++){
            if(dp[i][j] == -1){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    for(int i = 0 ;i<t;i++){
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << "\n";
    }
}