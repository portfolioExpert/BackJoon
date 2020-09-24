#include <iostream>
#include <algorithm>
using namespace std;

//문제 2468번
#include <queue>
queue <pair<int,int>> q;
bool visit[101][101];
bool check[101][101];
int rain[101][101];
int start = 1, value = 0, n;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int i ,j, value = 0, result = 1;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> rain[i][j];
        }
    }
    while(start<=100){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(rain[i][j] <= start)
                    check[i][j] = 1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(check[i][j] == 0 && visit[i][j] == 0){
                    bfs(i, j);
                    value++;
                }
            }
        }
        result = max(value, result);
        value = 0;
        start++;
        for(i=0;i<n;i++){
            fill_n(visit[i], n, 0);
            fill_n(check[i], n ,0);
        }
    }
    cout << result;
}
void bfs(int x, int y){
    visit[x][y] = 1;
    q.push({x, y});
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int vx = gox + dx[i];
            int vy = goy + dy[i];
            if(vx>=0 && vx < n && vy >=0 && vy < n && visit[vx][vy] == 0 && check[vx][vy] == 0){
                q.push({vx, vy});
                visit[vx][vy] = 1;
            }
        }
    }
}