//문제 2631번 줄세우기 -> DP
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    int num[201];
    int dp[201];
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
        dp[i] = 1;
    }
    int big = 0, result = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(num[i] > num[j]){
                if(big <= dp[j])
                    big = dp[j];
            }
        }
        dp[i] = big + 1;
        big = 0;
        result = max(result, dp[i]);
    }
    cout << n - result;
}