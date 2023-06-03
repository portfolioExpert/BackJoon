#include <iostream>
#include <algorithm>
using namespace std;

//문제 24479번 알고리즘 수업 - 깊이 우선 탐색 1 -> DFS
#include <vector>
int visit[100001];
int cnt = 1;
void dfs(vector<int>v[], int now){
    visit[now] = cnt++;
    for(int next : v[now]){
        if(visit[next] == 0){
            dfs(v, next);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<int>v[100001];
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 0;i<m;i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for(int i = 0;i<=n;i++){
        sort(v[i].begin(), v[i].end());
    }
    dfs(v, r);
    for(int i = 1;i<=n;i++){
        if(visit[i] == 0)
            cout << "0" << "\n";
        else
            cout << visit[i] << "\n";
    }
}