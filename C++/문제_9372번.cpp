//문제 9372 상근이의 여행 -> dfs
#include <vector>
#include <cstring>
bool visit[1001];
int result;
void dfs(int node, vector<int>v[]){
    if(visit[node])
        return;
    visit[node] = 1;
    for(int y : v[node]){
        if(visit[y] == 0){
            result++;
            dfs(y, v);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n, m;
        cin >> n >> m;
        vector<int>v[1001];
        result = 0;
        for(int j = 0;j<m;j++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        memset(visit, 0, sizeof(visit));
        dfs(1, v);
        cout << result << "\n";
    }
}