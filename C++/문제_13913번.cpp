//문제 13913번 숨바꼭질4 -> BFS
#include <queue>
int dis[3] = {-1, 1, 2};
int dp[100001];
int from[100001];
bool visit[100001];
int n ,k;
void dfs(int go){
    if(go == n){
        cout << go << " ";
        return;
    }
    dfs(from[go]);
    cout << go << " ";
}
void bfs(int go){
    queue<int>q;
    q.push(go);
    dp[go] = 0;
    visit[go] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<3;i++){
            int next = now + dis[i];
            if(i == 2)
                next = now * dis[i];
            if(next >= 0 && next <= 100000 && visit[next] == 0){
                visit[next] = 1;
                q.push(next);
                dp[next] = dp[now] + 1;
                from[next] = now;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> k;
    bfs(n);
    cout << dp[k] << "\n";
    dfs(k);
}