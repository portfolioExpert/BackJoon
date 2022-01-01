//문제 2610번 회의준비 -> 플로이드 와샬
//플로이드 테이블에서 한 정점에서 다른 정점까지 거리가 최소인 것을 사이클 내에서 찾아야한다.
#include <vector>
vector<int>v[101];
bool visit[101];
int dp[101][101];
int sum[101];
int maxval;
int ind;
void dfs(int go){
    if(maxval > sum[go]){
        maxval = sum[go];
        ind = go;
    }
    for(int y : v[go]){
        if(visit[y] == 0){
            visit[y] = 1;
            dfs(y);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<int>result;
    int n, m;
    cin >> n >> m;
    int cycle = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = 987654321;
        }
        dp[i][i] = 0;
    }
    for(int i = 0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(dp[i][j] != 987654321)
                sum[i] = max(sum[i], dp[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            maxval = sum[i];
            ind = i;
            dfs(i);
            cycle++;
            result.push_back(ind);
        }
    }
    cout << cycle << "\n";
    sort(result.begin(), result.end());
    for(int i = 0;i<cycle;i++){
        cout << result[i] << "\n";
    }
}