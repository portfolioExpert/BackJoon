//문제 1965번
int num[1001];
int dp[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, result = 0;;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
        dp[i] = 1;
    }
    for(int i = 0;i<n;i++){
        int big = 0;
        for(int j = 0;j<i;j++){
            if(num[i] > num[j])
                big = max(big, dp[j]);
        }
        dp[i] = big + 1;
        result = max(result, dp[i]);
    }
    cout << result;
}