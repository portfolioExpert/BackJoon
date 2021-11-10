//문제 9470번 Strahler 순서 -> 위상정렬
#include <vector>
#include <queue>
#include <cstring>
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int k, m, p;
        cin >> k >> m >> p;
        vector<int>v[1001];//노드
        vector<int>value[1001];//큰 값
        queue<pair<int,int>>q;
        int cnt[1001];
        memset(cnt, 0, sizeof(cnt));
        int result = 0;
        for(int j = 0;j<p;j++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            cnt[to]++;
        }
        for(int j = 1;j<=m;j++){
            if(cnt[j] == 0){
                q.push({j,1});
                value[j].push_back(1);
            }
        }
        while(!q.empty()){
            int now = q.front().first;
            int cost = q.front().second;
            q.pop();
            result = max(result, cost);
            for(int i = 0;i<v[now].size();i++){
                cnt[v[now][i]]--;
                value[v[now][i]].push_back(cost);
                if(cnt[v[now][i]] == 0){
                    sort(value[v[now][i]].begin(), value[v[now][i]].end());
                    int maxval = value[v[now][i]][value[v[now][i]].size() - 1];
                    int index = (int)value[v[now][i]].size() - 1;
                    if(index > 0 && value[v[now][i]][index] == maxval && value[v[now][i]][index-1] == maxval)
                        q.push({v[now][i], maxval + 1});
                    else
                        q.push({v[now][i], cost});
                }
            }
        }
        cout << k << " " << result << "\n";
    }
}