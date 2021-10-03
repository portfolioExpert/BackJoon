//문제 2211번 네트워크 복구 -> 다익스트라
#include<queue>
#include <vector>
vector<pair<int,int>>v[1001];
vector<int>result[1001];
priority_queue<pair<int,int>>pq;
int dp[1001];
void dijkstra(int go){
    dp[go] = 0;
    pq.push({0, go});
    while(!pq.empty()){
        int gogo = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0;i<(int)v[gogo].size();i++){
            int next = v[gogo][i].first;
            int weight = v[gogo][i].second + cost;
            if(dp[next] > weight){
                dp[next] = weight;
                pq.push({-weight,next});
                result[next].clear();
                result[next].push_back(gogo);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        dp[i] = 987654321;
    }
    for(int i = 0;i<m;i++){
        int num1, num2, cost;
        cin >> num1 >> num2 >> cost;
        v[num1].push_back({num2, cost});
        v[num2].push_back({num1, cost});
    }
    dijkstra(1);
    vector<pair<int,int>>answer;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<(int)result[i].size();j++){
            answer.push_back({i, result[i][j]});
        }
    }
    cout << answer.size() << "\n";
    for(int i = 0;i<(int)answer.size();i++){
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
    return 0;
}