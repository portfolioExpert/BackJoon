//문제 15652번 N과 M(4) -> 백트래킹
#include <vector>
void dfs(int n, int m, vector<int>v, int now){
    if(v.size() == m){
        for(int y : v)
            cout << y << " ";
        cout << "\n";
        return;
    }
    for(int i = now;i<=n;i++){
        v.push_back(i);
        dfs(n, m, v, i);
        v.pop_back();
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n,m;
    vector<int>v;
    cin >> n >> m;
    dfs(n, m, v, 1);
}