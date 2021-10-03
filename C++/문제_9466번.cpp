//문제 9466번 신유형dfs
#include <cstring>
int v[100001];
int visit[100001];
int team[100001];
int result;
void dfs(int go);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(team, 0 ,sizeof(team));
        memset(visit, -1 ,sizeof(visit));
        result = 0;
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> v[i];
        }
        for(int i =1;i<=n;i++){
            if(visit[i] == -1)
                dfs(i);
        }
        cout << n - result <<"\n";
    }
}
void dfs(int go){
    if(visit[go] == 1)
        return;
    visit[go] = 1;
    if(visit[v[go]] == -1){
        dfs(v[go]);
    }
    else{
        //팀이 있는 사람들을 세어준다
        if(team[v[go]] == 0){
            result++;
            for(int i = v[go];i != go;i = v[i]){
                result++;
            }
        }
    }
    team[go] = 1;
}