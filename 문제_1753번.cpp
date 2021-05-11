#include <iostream>
#include <algorithm>
using namespace std;

//문제 1753번
#include <vector>
#include <queue>
priority_queue<pair<int, int>> pq;//pq에 들어갈 때 짧은 거리 기준으로 방문해야하므로 순서를 가중치, 노드번호로 해준다.
vector <pair<int, int>> node[20001];
int dp[20001];//인덱스 까지 최단 거리 저장
void dijkstra(int from);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v, e, start, num1 ,num2, i, weight;
    cin >> v >> e >> start;
    fill_n(dp, 20001, 1000000000);//최단거리를 최대로 채우고 저장하여 시작
    for(i = 0; i<e;i++){
        cin >> num1 >> num2 >> weight;
        node[num1].push_back({num2, weight});
    }
    pq.push({0, start});//시작점을
    dijkstra(start);
    for(i = 1;i<=v;i++){
        if(dp[i] == 1000000000)
            cout << "INF\n";
        else{
            cout << dp[i] << "\n";
        }
    }
    return 0;
}
void dijkstra(int from){
    dp[from] = 0;//시작 노드로 가는 것은 0으로 시작
    while(!pq.empty()){
        int now = pq.top().second;//거리가 가장 짧은 노드의 최단거리
        int distance = -pq.top().first;//거리가 가장 짧은 노드 번호
        pq.pop();
        if(dp[now] < distance)continue;//dp값이 최신화 되었으면 다음 반복분
        for(int i=0;i < node[now].size(); i++){//인접 노드들을 하나씩 방문
            int next = node[now][i].first;//인접 노드를 저장
            int nextdistance = node[now][i].second + distance;//인접 노드거리 까지 저장
            if(nextdistance < dp[next]){//거리가 최신화 되지 않을 경우 최신화
                dp[next] = nextdistance;
                pq.push({-nextdistance, next});//가장 가까운 거리를 넣기위해 -를 붙여서 넣어줌
            }
        }
    }
}