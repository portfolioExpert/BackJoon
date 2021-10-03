//문제 7579번 앱 ->배낭 문제 응용
int dp[10100];//dp 인덱스는 코스트로 코스트로 최대 만들수있는 메모리이다.
int item[102][2];
int n, m;
int result = 1111111111;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> item[i][0];
    }
    for(int i=1;i<=n;i++){
        cin >> item[i][1];
        sum+=item[i][1];
    }
    for(int i=1;i<=n;i++){
        int memory = item[i][0], cost = item[i][1];
        for(int j=sum;j>=item[i][1];j--){
            //cost를 인덱스로 두어 메모리 초과를 방지 하고 값은 배열 안에 저장
            dp[j]=max(dp[j],dp[j-cost]+memory);
        }
    }
    for(int i = 1;i<=sum;i++){
        if(dp[i]>=m){
            result = i;
            break;
        }
    }
    cout << result;
}