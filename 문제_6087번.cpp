//문제 6087번 레이저 통신
#include <queue>
#include <vector>
vector<pair<int,int>>v;
queue<pair<pair<int,int>,int>>q;
int visit[101][101][4];
int w, h;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[101][101];
int result = 98765421;
void bfs(){
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        int direct = q.front().second;
        q.pop();
        result = min(result, visit[v[1].first][v[1].second][direct]);
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < h && gy >= 0 && gy < w && (map[gx][gy] == '.' || map[gx][gy] == 'C')){
                if((direct + 2) % 4 == i)//180도의 경우는 제외
                    continue;
                if(direct == i && visit[gx][gy][direct] > visit[gox][goy][i]){//첫 방향, 방향이 같을경우
                    q.push({{gx,gy}, i});
                    visit[gx][gy][i] = visit[gox][goy][direct];
                }
                else if(direct != i && visit[gx][gy][i] > visit[gox][goy][direct] + 1){//방향 바뀔때
                    q.push({{gx, gy}, i});
                    visit[gx][gy][i] = visit[gox][goy][direct] + 1;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h;
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            fill_n(visit[i][j], 4, 987654321);
        }
    }
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin >> map[i][j];
            if(map[i][j] == 'C'){
                v.push_back({i,j});
            }
        }
    }
    //전방향 초기화
    q.push({{v[0].first, v[0].second}, 0});
    q.push({{v[0].first, v[0].second}, 1});
    q.push({{v[0].first, v[0].second}, 2});
    q.push({{v[0].first, v[0].second}, 3});
    for(int i = 0;i<4;i++){
        visit[v[0].first][v[0].second][i] = 0;
    }
    bfs();
    cout << result;
}
