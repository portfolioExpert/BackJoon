#include <iostream>
#include <algorithm>
using namespace std;

//문제 1890번 dfs로 돌면서 해당위치에서 갈 수 있는 경우의수를 dp에 저장해서 찾는다
typedef long long ll;
int n;
int map[101][101];
ll visit[101][101];
ll dfs(int x, int y);
int main(){
    int i, j;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map[i][j];
            visit[i][j] = -1;
        }
    }
    cout << dfs(0,0);
    return 0;
}
ll dfs(int x,int y){
    if(x == n-1 && y == n-1){
        return 1;
    }
    if(visit[x][y] == -1){
        visit[x][y] = 0;
        if(x + map[x][y] < n)
            visit[x][y] += dfs(x + map[x][y], y);
        if(y + map[x][y] < n)
            visit[x][y] += dfs(x, y + map[x][y]);
    }
    return visit[x][y];
}