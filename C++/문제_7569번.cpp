#include <iostream>
#include <algorithm>
using namespace std;

//문제 7569번
#include <queue>
queue <pair<int,pair<int,int>>>q;
int box[101][101][101];
int visit[101][101][101];
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {1, -1};
int result, m, n, h;
void bfs();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i, j, k;
    cin >> m >> n >> h;
    for(i=0;i<h;i++){
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    q.push({i, {j,k}});
                    visit[i][j][k] = 1;
                }
            }
        }
    }
    bfs();
    for(i=0;i<h;i++){
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                if(box[i][j][k] == 0){
                    result = 0;
                    break;
                }
                result = max(result, visit[i][j][k]);
            }
            if(result == 0)break;
        }
        if(result == 0)break;
    }
    cout << result - 1;
    return 0;
}
void bfs(){
    while(!q.empty()){
        int goz = q.front().first;//i가 들어간다
        int gox = q.front().second.first;//j가 들어가고
        int goy = q.front().second.second;//k가 들어가고
        q.pop();
        for(int i =0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy< m && visit[goz][gx][gy] == 0 && box[goz][gx][gy] == 0){
                visit[goz][gx][gy] = visit[goz][gox][goy] + 1;
                box[goz][gx][gy] = 1;
                q.push({goz, {gx,gy}});
            }
        }
        for(int j=0;j<2;j++){
            int gz = goz + dz[j];
            if(gz >= 0 && gz < h && visit[gz][gox][goy] == 0 && box[gz][gox][goy] == 0){
                visit[gz][gox][goy] = visit[goz][gox][goy] + 1;
                box[gz][gox][goy] = 1;
                q.push({gz, {gox,goy}});
            }
        }
    }
}