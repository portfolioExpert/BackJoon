//문제 15971번 두 로봇 -> BFS 출발지, 도착지 같은것, n이 1일때 고려 해야한다.
#include <vector>
#include <queue>
vector<pair<int,int>>v[100001];
int visit1[100001];
int visit2[100001];
int result = 987654321;
void bfs1(int go){
    queue<int>q;
    q.push(go);
    visit1[go] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto y : v[now]){
            int next = y.first;
            int cost = y.second;
            if(visit1[next] > visit1[now] + cost){
                visit1[next] = visit1[now] + cost;
                q.push(next);
            }
        }
    }
}
void bfs2(int go){
    queue<int>q;
    q.push(go);
    visit2[go] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto y : v[now]){
            int next = y.first;
            int cost = y.second;
            if(visit2[next] > visit2[now] + cost){
                visit2[next] = visit2[now] + cost;
                q.push(next);
            }
            result = min(result, visit1[next] + visit2[now]);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, robot1, robot2;
    cin >> n >> robot1 >> robot2;
    for(int i = 0;i<n-1;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    for(int i = 1;i<=n;i++){
        visit1[i] = 987654321;
        visit2[i] = 987654321;
    }
    bfs1(robot1);
    bfs2(robot2);
    if(n == 1 || robot1 == robot2)
        cout << 0;
    else
        cout << result;
}