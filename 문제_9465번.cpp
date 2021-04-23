#include <iostream>
#include <algorithm>
using namespace std;

//문제 9465번
int map [2][100001];
int dp [2][100001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t, n, i, j;
    cin >> t;
    while(t--){
        int result = 0;
        cin >> n;
        for(i=0;i<2;i++){
            for(j=0;j<n;j++){
                cin >> map[i][j];
            }
        }
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = dp[1][0] + map[0][1];
        dp[1][1] = dp[0][0] + map[1][1];
        for(i=2;i<n;i++){
            dp[0][i] = max(dp[1][i-2], max(dp[1][i-1], dp[0][i-2])) + map[0][i];
            dp[1][i] = max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2])) + map[1][i];
            result = max(result, max(dp[0][i], dp[1][i]));
        }
        cout << result << "\n";
    }
    return 0;
}