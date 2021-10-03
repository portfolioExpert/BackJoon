//문제 14938번 서강그라운드 -> 플로이드 와샬
int cost[101];
int dp[101][101];
int n, m, r;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    cin >> n >> m >> r;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = 987654321;
        }
    }
    for(int i = 1;i<=n;i++){
        cin >> cost[i];
        dp[i][i] = 0;
    }
    for(int i = 0;i<r;i++){
        int a, b ,c;
        cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 1;j<=n;j++){
            if(dp[i][j] <= m)
                sum+=cost[j];
        }
        result = max(result, sum);
    }
    cout << result;
}