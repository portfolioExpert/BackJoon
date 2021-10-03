//문제 14925번 목장 건설하기
int dp[1001][1001];
int map[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, result = 0;
    cin >> m >> n;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                dp[i][j] = 1;
                result = 1;
            }
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(map[i][j] == 0){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + dp[i][j];
                result = max(dp[i][j], result);
            }
        }
    }
    cout << result;
}