//문제 14267번 회사 문화1 -> DP, DFS
#include <vector>
int n, m;
int dp[100001];
int cost[100001];
int parent[100001];
int dfs(int node){
    if(parent[node] == -1)
        return dp[node] = 0;
    if(dp[node] != -1)
        return dp[node];
    return dp[node] = cost[node] + dfs(parent[node]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i<=n;i++){
        int num;
        cin >> num;
        parent[i] = num;
    }
    for(int j = 0;j<m;j++){
        int node, weight;
        cin >> node >> weight;
        cost[node]=weight;
    }
    for(int i = 1;i<=n;i++){
        dfs(i);
    }
    for(int i = 1;i<=n;i++){
        cout << dp[i] << " ";
    }
}