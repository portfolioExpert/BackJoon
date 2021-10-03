//문제 10942번
#include <cstring>
int num[2001];
int dp[2001][2001];
int fx(int start, int end);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i<=n;i++){
        cin >> num[i];
        dp[i][i] = 1;
    }
    cin >> m;
    for(int i =0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        cout << fx(num1, num2) << "\n";
    }
}
int fx(int start, int end){
    //이것으로 인해 틀렸었다
    if(start >= end)return 1;
    if(dp[start][end] != -1)return dp[start][end];
    if(num[start] == num[end])
        dp[start][end] = fx(start + 1, end - 1);
    else{
        dp[start][end] = 0;
        //이것이 있어야 시간 절약이된다
        dp[start+1][end] = fx(start + 1, end);
        dp[start][end-1] = fx(start, end - 1);
    }
    return dp[start][end];
}