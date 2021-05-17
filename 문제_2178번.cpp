#include <iostream>
#include <algorithm>
using namespace std;

//문제 2178번
#include <queue>
queue <pair<int,int>> q;
char way[101][101];
bool visit[101][101];
int dp[101][101];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
void BFS(int to1, int to2);
int main(){
    int n, m, i, j;
    cin >> n >> m;
    dp[1][1] = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> way[i][j];
            way[i][j]-=0;
        }
    }
    q.push({1,1});
    BFS(n,m);
    cout << dp[n][m];
    return 0;
}
void BFS(int to1, int to2){
    while(!q.empty()){
        int x, y;
        x = q.front().first;
        y = q.front().second;
        visit[x][y] = 1;
        q.pop();
        for(int i = 0;i<4;i++){
            int xs, ys;
            xs = x + dx[i];
            ys = y + dy[i];
            if(xs >= 1 && to1>=xs && ys>=1 && ys<=to2 && way[xs][ys] == '1' && visit[xs][ys] == 0){
                visit[xs][ys] = 1;
                dp[xs][ys] = dp[x][y] + 1;
                q.push({xs,ys});
            }
        }
    }
}