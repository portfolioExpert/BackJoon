#include <iostream>
#include <algorithm>
using namespace std;

//문제 2573번
#include <queue>
#include <cstring>
queue <pair<int, int>> q;
int map[301][301];
bool visit[301][301];
int zero[301][301];
int n ,m, result, t;
bool flag;
int dx[4] = {-1, 0, 1 , 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y);
void check(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i , j;
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        result = 0;
        flag = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(map[i][j] > 0 && visit[i][j] == 0){//bfs가 돌아가면 빙산이 존재한것
                    bfs(i, j);
                    result++;
                    flag = 1;
                }
            }
        }
        if(result>=2 || flag == 0)break;//빙산이 2개이상이거나
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(map[i][j] > 0)
                    check(i,j);//체크함수는 얼음위치에서 0이 몇개인지 갯수를 체크
            }
        }
        for(i=0;i<n;i++){//갯수 체크후 전체적으로 한번에 빼준다
            for(j=0;j<m;j++){
                if(map[i][j] - zero[i][j]> 0)
                    map[i][j] -= zero[i][j];
                else
                    map[i][j] = 0;
            }
        }
        t++;
        memset(visit, 0, sizeof(visit));//방문 초기화
    }
    if(!flag)
        cout << 0;
    else
        cout << t;
}
void check(int x, int y){//주변 0 갯수 체크 함수
    int cnt = 0;
    for(int i =0;i<4;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx>=0 && gx < n && gy >= 0 && gy < m && map[gx][gy] == 0 && map[x][y] > 0){
            cnt++;
        }
    }
    zero[x][y] = cnt;
}
void bfs(int x, int y){
    q.push({x,y});
    visit[x][y] = 1;
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0; i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < n && gy >= 0 && gy < m && map[gx][gy] != 0 && visit[gx][gy] == 0){
                visit[gx][gy] = 1;
                q.push({gx, gy});
            }
        }
    }
}