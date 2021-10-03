//문제 12865번 평범한 배낭
//배낭문제 기본 매커니즘
#include <vector>
int dp[101][100010];//dp는 최대 물건 갯수, 최대 무게로 만들고
int item[102][2];
int n, k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> item[i][0] >> item[i][1];
    }
    for(int i=1;i<=n;i++)
    {
        int weight = item[i][0], val=item[i][1];
        //바텀업하는 부분
        for(int j=0;j<=k;j++)
        {
            //담지 않는경우 이전값을 그대로 가져오고
            if(j<item[i][0]) dp[i][j]=dp[i-1][j];
            //담는 경우 이전값과 비교하여 이전에서 해당 무게를 뺀 dp중에 현재 무게를 더하고 비교
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+val);
        }
    }
    cout << dp[n][k];
}
