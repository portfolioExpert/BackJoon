//문제 1743번
#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>
queue<pair<int,int>>q;
int n,m;
int map[101][101];
int visit[101][101];
int result = 0, sum = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0 ,0, 1, -1};
void bfs(int x, int y){
    q.push({x, y});
    sum = 1;
    visit[x][y] = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 1 && gx <= n && gy >= 1 && gy <= m && visit[gx][gy] == 0 && map[gx][gy] == 1){
                visit[gx][gy] = 1;
                sum++;
                q.push({gx,gy});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> n >> m >> t;
    for(int i = 0;i<t;i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                bfs(i, j);
                result = max(result, sum);
            }
        }
    }
    cout << result;
}