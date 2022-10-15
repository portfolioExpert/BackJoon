//문제 1405번 미친로봇 -> 백트래킹, 브루트 포스
#include <iostream>
#include <algorithm>
using namespace std;

double visit[29][29];//시작좌표는 14, 14
bool visited[29][29];
int N;
double e, w, s, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1 ,0 ,0};
double percent[4];
double sumcnt;//총 갯수
void dfs(int cnt, int x, int y){
    if(cnt == N){
        sumcnt+=visit[x][y];
        return;
    }
    for(int i = 0;i<4;i++){
        int gox = x + dx[i];
        int goy = y + dy[i];
        if(visited[gox][goy] == 0){
            visited[gox][goy] = 1;
            visit[gox][goy] = visit[x][y] * percent[i];
            dfs(cnt + 1, gox , goy);
            visit[gox][goy] = 0;
            visited[gox][goy] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;
    cin >> percent[0] >> percent[1] >> percent[2]>> percent[3];
    for(int i = 0;i<4;i++){
        percent[i]/=100;
    }
    visit[14][14] = 1;
    visited[14][14] = 1;
    dfs(0, 14, 14);
    cout.precision(10);
    cout << sumcnt;
}