//문제 1976번 여행 가자
#include <vector>
#include <cstring>
vector<int>v[201];
vector<int>tour;
bool visit[201];
void dfs(int from, int to){
    visit[from] = 1;
    if(from == to)
        return;
    for(int i = 0;i<v[from].size();i++){
        if(visit[v[from][i]] == 0){
            visit[v[from][i]] = 1;
            dfs(v[from][i], to);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int num;
            cin >> num;
            if(num == 1)
                v[i].push_back(j);
        }
    }
    for(int i = 0;i<m;i++){
        int num;
        cin >> num;
        tour.push_back(num);
    }
    for(int i = 0;i<tour.size() - 1;i++){
        memset(visit, 0, sizeof(visit));
        dfs(tour[i], tour[i+1]);
        if(visit[tour[i]] == 0 || visit[tour[i+1]] == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}