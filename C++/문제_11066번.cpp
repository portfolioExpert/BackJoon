//문제 11066번 파일합치기 -> DP 인덱스는 범위를 의미
int dp[501][501];
int num[501];
int sum[501];
int n;
int topdown(int from, int to){
    //이미 값이 있으면 값 리턴
    if(dp[from][to] != 987654321)
        return dp[from][to];
    //같으면 0이므로 리턴
    if(from == to)
        return dp[from][to] = 0;
    //하나 차이면 값을 저장 후 리턴
    if(from + 1 == to)
        dp[from][to] = num[from] + num[to];
    //dp[0][0] ~ dp[1][n] 값을 쭉 돌며 최솟값을 저장
    //dp[0][1] ~ dp[2][n]
    for(int i = from;i<to;i++){
        dp[from][to] = min(dp[from][to], topdown(from, i) + topdown(i+1, to));
    }
    //해당 범위에 구간합을 이용하여 비용을 더해주고 리턴
    return dp[from][to] += sum[to] - sum[from - 1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        cin >> n;
        for(int j = 0;j<=n;j++){
            fill_n(dp[j], n + 1, 987654321);
        }
        for(int j = 1;j<=n;j++){
            cin >> num[j];
            sum[j] = sum[j-1] + num[j];
        }
        cout << topdown(1, n) << "\n";
    }
}