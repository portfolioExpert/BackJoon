//문제 15650번 N과 M(2) -> 백트래킹
#include <vector>
vector<int>v;
bool visit[9];
void dfs(int n, int m, int cnt){
    if(m == v.size()){
        for(int y : v)
            cout << y << " ";
        cout << "\n";
        return;
    }
    for(int i = cnt + 1;i<=n;i++){
        v.push_back(i);
        dfs(n, m, i);
        v.pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n - m + 1;i++){
        v.push_back(i);
        dfs(n, m, i);
        v.pop_back();
    }
}