//문제 16948번 데스 나이트 -> BFS
#include <queue>
#include <cstring>
queue<pair<int,int>>q;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int map[201][201];
int visit[201][201];
int n;
void bfs(int x, int y){
    q.push({x, y});
    visit[x][y] = 0;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<6;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < n && visit[gx][gy] == -1){
                visit[gx][gy] = visit[gox][goy] + 1;
                q.push({gx, gy});
            }
        }
    }
}
int main(){
    cin >> n;
    memset(visit, -1 , sizeof(visit));
    int startx, starty, goalx, goaly;
    cin >> startx >> starty >> goalx >> goaly;
    bfs(startx, starty);
    cout << visit[goalx][goaly];
}