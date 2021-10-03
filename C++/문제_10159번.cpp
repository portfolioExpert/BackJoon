//문제 10159번 저울 -> 플로이드 와샬 약간 변형
#include <vector>
vector<int>v;
bool dp[101][101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        //알 수 있는 루트 체크
        dp[num1][num2] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                //두 곳다 길이 있다면 알 수 있음
                if(dp[j][i] && dp[i][k])dp[j][k] = 1;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 1;j<=n;j++){
            //해당 루트를 통해서 길이 있는 것을 체크
            sum += dp[i][j] + dp[j][i];
        }
        v.push_back(n - sum - 1);
    }
    for(int y : v)
        cout << y << "\n";
}