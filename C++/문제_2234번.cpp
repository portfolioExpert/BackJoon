#include <iostream>
#include <algorithm>
using namespace std;

//문제 2234번
#include <queue>
queue<pair<int,int>> q;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int bi[4] = {8, 4, 2, 1};
int visit[51][51];
int map[51][51];
int bigroom, n ,m, cnt = 1, k;
void bfs(int x, int y);
int main(){
    int i, j, room = 0;
    cin >> m >> n;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    //방 갯수 구하기
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(visit[i][j] == 0){
                bfs(i,j);
                room++;
            }
        }
    }
    cout << room << "\n" << bigroom << "\n";
    bigroom = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<4;k++){
                int tx, ty;
                tx = i + dx[k];
                ty = j + dy[k];
                if(tx>=0 && tx < n && ty >= 0 && ty < m && visit[i][j] != visit[tx][ty]){
                    bigroom = max(bigroom, map[i][j] + map[tx][ty]);
                }
            }
        }
    }
    cout << bigroom;
}
void bfs(int x, int y){
    q.push({x, y});
    int sum = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        visit[gox][goy] = cnt;
        q.pop();
        for(int i=0;i<4;i++){//8 ,4 ,2 ,1 순으로 빼야함
            int vx,vy;
            vx = gox + dx[i];
            vy = goy + dy[i];
            if((map[gox][goy] - bi[i] < 0) && vx>=0 && vx < n && vy>=0 && vy < m && visit[vx][vy] == 0){
                q.push({vx, vy});
                visit[vx][vy] = cnt;
                sum++;
            }
            else if((map[gox][goy] - bi[i] >= 0) && ((vx>=0 && vx < n && vy>=0 && vy < m) || (vx < 0 || vx >= n || vy < 0 || vy >= m))){
                map[gox][goy] -= bi[i];
            }
        }
    }
    bigroom = max(sum, bigroom);
    for(int i = 0; i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j] == cnt && map[i][j] == 0)
                map[i][j] = sum;
        }
    }
    cnt++;
}