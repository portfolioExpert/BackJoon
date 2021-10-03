//문제 16954번 움직이는 미로 탈출 -> BFS
//움직이고 bfs를 하나의 while문에 넣어주어 시간을 관리해주도록 운영
#include <vector>
#include <queue>
#include <cstring>
queue<pair<int,int>>q;
char map[9][9];
int visit[9][9];
int wall[9][9];
bool flag = false;
int dx[9] = {1, -1 ,0 ,0 , 1, -1, 1, -1, 0};
int dy[9] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
void wallmove(){
    for(int i = 7;i>=1;i--){
        for(int j = 0;j<8;j++){
            map[i][j] = map[i-1][j];
        }
    }
    for(int i = 0;i<8;i++){
        map[0][i] = '.';
    }
}
void bfs(){
    int qsize = (int)q.size();
    for(int i = 0;i<qsize;i++){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        if(map[gox][goy] == '#')
            continue;
        if(gox == 0 && goy == 7){
            flag = true;
            return;
        }
        for(int i = 0;i<9;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < 8 && gy >= 0 && gy < 8 && map[gx][gy] == '.' && visit[gx][gy] == 0){
                visit[gx][gy] = 1;
                q.push({gx, gy});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            cin >> map[i][j];
        }
    }
    q.push({7, 0});
    while(1){
        int qsize = (int)q.size();
        if(qsize == 0 || flag)break;
        memset(visit, 0 , sizeof(visit));
        bfs();
        wallmove();
    }
    cout << flag;
}