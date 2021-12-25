//문제 1944번 복제 로봇 -> BFS, 최소 스패닝 트리
#include <cstring>
#include <queue>
#include <vector>
vector<pair<int,int>>v;
vector<pair<int,pair<int,int>>>pq;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0 ,1, -1};
int n, m;
char map[51][51];
int numbering[51][51];
bool ablech[51][51];
int parent[255];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1,int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        parent[node2] = node1;
    }
}
//거리 측정용
void bfs(int x, int y){
    int visit[51][51];
    queue<pair<int,int>>q;
    q.push({x, y});
    memset(visit, 0, sizeof(visit));
    ablech[x][y] = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < n && visit[gx][gy] == 0 && map[gx][gy] != '1'){
                q.push({gx, gy});
                visit[gx][gy] = visit[gox][goy] + 1;
                if(map[gx][gy] == 'S' || map[gx][gy] == 'K'){
                    pq.push_back({visit[gx][gy],{numbering[x][y], numbering[gx][gy]}});
                    ablech[gx][gy] = 1;
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int result = 0;
    int cnt = 0;
    memset(numbering, -1, sizeof(numbering));
    memset(ablech, 0, sizeof(ablech));
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 'S' || map[i][j] == 'K'){
                v.push_back({i, j});
                numbering[i][j] = cnt++;
            }
        }
    }
    for(int i = 1;i<=(int)v.size();i++){
        parent[i] = i;
    }
    for(int i = 0;i<(int)v.size();i++){
        bfs(v[i].first, v[i].second);
        for(int j = 0;j<(int)v.size();j++){
            if(ablech[v[j].first][v[j].second] == 0){
                cout << -1;
                return 0;
            }
        }
    }
    sort(pq.begin(), pq.end());
    for(int i = 0;i<(int)pq.size();i++){
        int from = pq[i].second.first;
        int to = pq[i].second.second;
        int cost = pq[i].first;
        if(find(from) != find(to)){
            merge(from, to);
            result+=cost;
        }
    }
    cout << result;
}