//문제 10971번 외판원 순회2 -> 백트래킹
int cost[11][11];
int visit[11];
int n, result = 987654321;
void dfs(int start, int now, int sum, int cnt){
    if(cost[now][start] != 0 && cnt == n - 1){
        result = min(result, sum + cost[now][start]);
        return;
    }
    for(int i = 0;i<n;i++){
        if(i != start && cost[now][i] != 0 && visit[i] == 0){
            visit[i] = 1;
            dfs(start, i, sum + cost[now][i], cnt + 1);
            visit[i] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        dfs(i, i, 0, 0);
    }
    cout << result;
}