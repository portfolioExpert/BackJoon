//문제 1915번
//dp인데 해당범위를 고려해야한다 신 유 형
char map[1001][1001];
int dp[1001][1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            dp[i][j] = map[i][j] - '0';
            result = max(result, dp[i][j]);
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(map[i][j] == '1'){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + dp[i][j];
                result = max(result, dp[i][j]);
            }
        }
    }
    cout << result * result;
}