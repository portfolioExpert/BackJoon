//문제 1535번 안녕 -> 백트래킹
int n;
int l[21];
int j[21];
bool visit[21];
int result;
void dfs(int now, int health, int happy){
    if(health <= 0 || now == n){
        if(health > 0){
            result = max(result , happy);
        }
        else
            result = max(result, happy - j[now]);
        return;
    }
    for(int i = now + 1;i<=n;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(i, health - l[i], happy + j[i]);
            visit[i] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> l[i];
    }
    for(int i = 1;i<=n;i++){
        cin >> j[i];
    }
    for(int i = 1;i<=n;i++){
        visit[i] = 1;
        dfs(i, 100 - l[i], j[i]);
        visit[i] = 0;
    }
    cout << result;
}
