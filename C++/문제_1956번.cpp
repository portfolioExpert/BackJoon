//문제 1956번 운동 -> 플로이드 와샬 문제
int dp[401][401];
int sum = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int village, road;
    cin >> village >> road;
    int result = 987654321;
    for(int i = 1;i<=village;i++){
        fill_n(dp[i], village + 1, 987654321);
    }
    for(int i = 0; i<road;i++){
        int a , b ,c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }
    for(int i = 1;i<=village;i++){
        for(int j = 1;j<=village;j++){
            for(int k = 1;k<=village;k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    for(int i = 1;i<=village;i++){
        result = min(result, dp[i][i]);
    }
    if(result == 987654321)
        cout << -1;
    else
        cout << result;
    return 0;
}