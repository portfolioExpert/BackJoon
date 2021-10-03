//문제 14889번
int visit[21];
int n;
int map[21][21];
int result = 987654321;
void dfs(int index, int cnt);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        visit[i] = 1;
        dfs(i, 1);
        visit[i] = 0;
    }
    cout << result;
}
void dfs(int index, int cnt){
    if(n / 2 == cnt){
        int start = 0, link = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(visit[i] == 1 && visit[j] == 1){
                    start+=map[i][j];
                }
                if(visit[i] == 0 && visit[j] == 0){
                    link+=map[i][j];
                }
            }
        }
        result = min(result, abs(start-link));
        return;
    }
    for(int i = index+1;i<n;i++){
        visit[i] = 1;
        dfs(i, cnt+1);
        visit[i] = 0;
    }
}