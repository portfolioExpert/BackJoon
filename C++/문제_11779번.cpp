//문제 11779번 최소비용 구하기 2 -> dijkstra
#include <vector>
#include <queue>
priority_queue<pair<int ,int>>pq;
vector <pair<int, int>> v[1001];
int dp[1001];
vector<int>result[1001];
void dijkstra(int from);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m, i;
    cin >> n >> m;
    fill_n(dp, 1001, 1000000000);
    for(i=0;i<m;i++){
        int num1, num2, weight;
        cin >> num1 >> num2 >> weight;
        v[num1].push_back({num2,weight});
    }
    int from, to;
    cin >> from >> to;
    result[from].push_back(from);
    pq.push({0, from});
    dijkstra(from);
    cout << dp[to] << "\n";
    cout << result[to].size() << "\n";
    for(int i = 0;i<result[to].size();i++){
        cout << result[to][i] << " ";
    }
    return 0;
}
void dijkstra(int from){
    dp[from] = 0;
    while(!pq.empty()){
        int pos = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        if(dp[pos] < val)continue;
        for(int i=0;i<v[pos].size();i++){
            int near = v[pos][i].first;
            int wei = v[pos][i].second + val;
            if(wei < dp[near]){
                dp[near] = wei;
                pq.push({-wei, near});
                result[near].clear();
                result[near] = result[pos];
                result[near].push_back(near);
            }
        }
    }
}