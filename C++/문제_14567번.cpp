//문제 14567번 선수과목(Prerequisite) -> 위상정렬
#include <queue>
#include <vector>
queue<pair<int,int>>q;
vector<int>v[1001];
int cnt[1001];
int result[1001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        cnt[to]++;
    }
    for(int i = 1;i<=n;i++){
        if(cnt[i] == 0)
            q.push({i, 1});
    }
    while(!q.empty()){
        int now = q.front().first;
        int semistar = q.front().second;
        q.pop();
        result[now] = semistar;
        for(int i = 0;i<(int)v[now].size();i++){
            int next = v[now][i];
            cnt[next]--;
            if(cnt[next] == 0)
                q.push({next, semistar + 1});
        }
    }
    for(int i = 1;i<=n;i++){
        cout << result[i] << " ";
    }
}