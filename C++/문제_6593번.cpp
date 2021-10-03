#include <iostream>
#include <algorithm>
using namespace std;

//문제 6593번
#include <queue>
#include <cstring>
queue <pair<int, pair<int, int >>> q;
char map[31][31][31];
int visit[31][31][31];
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {1, -1};
int n, r, c, result;
void bfs();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i, j, k;
    while(1){
        memset(visit, -1, sizeof(visit));
        int x = 0, y = 0, z = 0;
        result = 0;
        cin >> n >> r >> c;
        if(n == 0 && r == 0 && c == 0)break;
        for(i=0;i<n;i++){
            for(j=0;j<r;j++){
                for(k=0;k<c;k++){
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S'){
                        q.push({i, {j, k}});
                        visit[i][j][k] = 1;
                    }
                    if(map[i][j][k] == 'E'){
                        x=i;
                        y=j;
                        z=k;
                    }
                }
            }
        }
        bfs();
        if(visit[x][y][z] == -1){
            cout << "Trapped!";
        }
        else
            cout << "Escaped in " << visit[x][y][z] - 1 << " minute(s).";
        cout << "\n";
    }
}
void bfs(){
    while(!q.empty()){
        int goz = q.front().first;//위아래 층 좌표
        int gox = q.front().second.first;//x축 좌표
        int goy = q.front().second.second;//축 좌표
        q.pop();
        for(int i=0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && n && gy >= 0 && gy < c && visit[goz][gx][gy] == -1 && (map[goz][gx][gy] == '.' || map[goz][gx][gy] == 'E')){
                q.push({goz, {gx, gy}});
                visit[goz][gx][gy] = visit[goz][gox][goy] + 1;
            }
        }
        for(int i = 0;i<2;i++){
            int gz = goz + dz[i];
            if(gz >= 0 && gz < n && visit[gz][gox][goy] == -1 && (map[gz][gox][goy] == '.' || map[gz][gox][goy] == 'E')){
                q.push({gz, {gox, goy}});
                visit[gz][gox][goy] = visit[goz][gox][goy] + 1;
            }
        }
    }
}