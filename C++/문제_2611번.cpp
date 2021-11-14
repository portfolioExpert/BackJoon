//문제 2611번 자동차경주 -> 위상정렬
#include <queue>
#include <vector>
vector<pair<int,int>>v[1001];
int cnt[1001];
int dp[1001];
int n, m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        cnt[to]++;
    }
    memset(dp, 0, sizeof(dp));
    queue<int>q;
    q.push(1);
    vector<int>result[1001];
    result[1].push_back(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<(int)v[now].size();i++){
            int next = v[now][i].first;
            int cost = v[now][i].second;
            if(dp[next] < cost + dp[now]){
                result[next] = result[now];
                result[next].push_back(next);
                dp[next] = cost + dp[now];
            }
            cnt[next]--;
            if(cnt[next] == 0)
                q.push(next);
        }
    }
    cout << dp[1] << "\n";
    for(int i = 0;i<(int)result[1].size();i++){
        cout << result[1][i] << " ";
    }
}