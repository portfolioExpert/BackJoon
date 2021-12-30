//문제 13908번 비밀번호 -> 백트래킹
int num[7];
int visit[10];
int result, n, m;
void dfs(int index){
    if(index == n){
        for(int i = 0;i<m;i++){
            if(visit[num[i]] == 0)
                return;
        }
        result++;
        return;
    }
    for(int i = 0;i<=9;i++){
        visit[i]++;
        dfs(index + 1);
        visit[i]--;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        cin >> num[i];
    }
    dfs(0);
    cout << result;
}