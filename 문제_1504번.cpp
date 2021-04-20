#include <iostream>
#include <algorithm>
using namespace std;

//문제 1504번
#include <vector>
#include <queue>
typedef long long ll;
vector <pair<int,int>> v[801];
ll dp[801];
ll dijkstra(int from, int to);
int point1, point2;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    ll e, i, sum1 = 0, sum2 = 0;
    int n;
    cin >> n >> e;
    fill_n(dp, 801, 99999999999);
    for(i = 0;i<e;i++){
        int num1, num2, val;
        cin >> num1 >> num2 >> val;
        v[num1].push_back({num2, val});
        v[num2].push_back({num1, val});
    }
    cin >> point1 >> point2;
    sum1 += dijkstra(1, point1);
    sum1 += dijkstra(point1, point2);
    sum1 += dijkstra(point2, n);
    if(sum1 >= 99999999999)sum1 = 0;
    sum2+= dijkstra(1, point2);
    sum2+= dijkstra(point2, point1);
    sum2+= dijkstra(point1, n);
    if(sum2 >= 99999999999)sum2 = 0;
    if(sum1 == 0 && sum2 == 0)
        cout << -1;
    else
        cout << min(sum1,sum2);
}
ll dijkstra(int from, int to){
    fill_n(dp, 801, 99999999999);
    priority_queue<pair<ll, int>> pq;
    pq.push({0, from});
    dp[from] = 0;
    while(!pq.empty()){
        ll val = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if(dp[pos] < val)continue;
        for(int i = 0;i < v[pos].size();i++){
            int near = v[pos][i].first;
            ll cost = v[pos][i].second + val;
            if(cost < dp[near]){
                dp[near] = cost;
                pq.push({-cost, near});
            }
        }
    }
    return dp[to];
}

/*
 코너 케이스에서 100%에서 틀림 오류
 5 4
 1 2 3
 2 5 3
 3 4 1
 1 5 5
 2 3
 */
