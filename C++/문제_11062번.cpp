//문제 11062번 카드게임 -> DP
#include <cstring>
int num[1001];
int dp[1001][1001];
int topdown(bool turn, int left, int right){
    if(left > right){
        return 0;
    }
    if(dp[left][right] != -1)
        return dp[left][right];
    //근우
    if(turn)
        dp[left][right] = max(num[left] + topdown(!turn,left + 1, right), num[right] + topdown(!turn, left, right - 1));
    //명우
    else
        dp[left][right] = min(topdown(!turn, left + 1, right), topdown(!turn , left, right - 1));
    return dp[left][right];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> num[i];
        }
        memset(dp, -1 ,sizeof(dp));
        cout << topdown(1, 0, n - 1) << "\n";
    }
}