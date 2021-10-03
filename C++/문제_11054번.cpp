#include <iostream>
#include <algorithm>
using namespace std;

//문제 11054번
int num[1001];
int dp[1001][2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, i, j, result = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for(i=0;i<n;i++){
        int right = 0;
        for(j = 0;j<i;j++){
            if(num[i] > num[j])
                right = max(right, dp[j][0]);
        }
        dp[i][0] = right + 1;
    }
    for(i = n - 1; i>=0;i--){
        int left = 0;
        for(j=n - 1;j>=i;j--){
            if(num[i] > num[j])
                left = max(left, dp[j][1]);
        }
        dp[i][1] = left + 1;
    }
    for(i=0;i<n;i++){
        result = max(result, dp[i][0] + dp[i][1]);
    }
    cout << result - 1;
    return 0;
}