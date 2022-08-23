//문제 11060번 점프점프
#include <queue>
int num[1001];
int dp[1001];
int n;
void bfs(){
    queue<int>q;
    q.push(0);
    dp[0] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = num[now];i>=1;i--){
            if(now + i >= n)
                continue;
            if(dp[now+i] > dp[now] + 1){
                q.push(now + i);
                dp[now+i] = dp[now] + 1;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
    }
    fill_n(dp, n ,987654321);
    bfs();
    if(dp[n-1] == 987654321)
        cout << -1;
    else
        cout << dp[n-1];
}