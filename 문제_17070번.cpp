#include <iostream>
#include <algorithm>
using namespace std;

//문제 17070번
int map[17][17], result, n;
bool visit[17][17];
//가로 대각 세로
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1 ,0};
bool check(int type, int x, int y);
bool arrive(int type, int x, int y);
void dfs(int type, int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int i ,j;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    visit[1][1] = 1;
    visit[1][2] = 1;
    dfs(1, 1, 2);
    cout << result;
}
bool arrive(int type, int x, int y){//도착인지 아닌지 확인
    if(x == n && y == n)//대각선
        return true;
    return false;
}
void dfs(int type, int x, int y){
    if(arrive(type, x, y)){//도착했을경우
        result++;
        return;
    }
    if(type == 1 && x >= 1 && x <= n && y >= 1 && y <= n){//가로일 경우
        for(int i = 0; i<2;i++){
            int gox = x + dx[i];
            int goy = y + dy[i];
            if(gox <= n && goy <= n){
                if(i == 0 && map[gox][goy] == 0){//가로로 또 갈 경우
                    visit[gox][goy] = 1;
                    dfs(1, gox, goy);
                    visit[gox][goy] = 0;
                }
                if(i == 1 && map[gox][goy] == 0 && map[gox][goy-1] == 0 && map[gox-1][goy] == 0){//대각선으로 갈 경우
                    visit[gox][goy] = 1;
                    dfs(2, gox, goy);
                    visit[gox][goy] = 0;
                }
            }
        }
    }
    else if(type == 3 && x >= 1 && x <= n && y >= 1 && y <= n){//세로일 경우
        for(int i = 1; i<3;i++){
            int gox = x + dx[i];
            int goy = y + dy[i];
            if(gox <= n && goy <= n){
                if(i == 2 && map[gox][goy] == 0){//세로로 또 갈 경우
                    visit[gox][goy] = 1;
                    dfs(3, gox, goy);
                    visit[gox][goy] = 0;
                }
                if(i == 1 && map[gox][goy] == 0 && map[gox][goy-1] == 0 && map[gox-1][goy] == 0){//대각선으로 갈 경우
                    visit[gox][goy] = 1;
                    dfs(2, gox, goy);
                    visit[gox][goy] = 0;
                }
            }
        }
    }
    else if(type == 2 && x >= 1 && x <= n && y >= 1 && y <= n){//대각선일 경우
        for(int i = 0; i<3;i++){
            int gox = x + dx[i];
            int goy = y + dy[i];
            if(gox <= n && goy <= n){
                if(i == 0 && map[gox][goy] == 0){//가로로 또 갈 경우
                    visit[gox][goy] = 1;
                    dfs(1, gox, goy);
                    visit[gox][goy] = 0;
                }
                if(i == 2 && map[gox][goy] == 0 && gox <= n && goy <= n){//세로로 갈 경우
                    visit[gox][goy] = 1;
                    dfs(3, gox, goy);
                    visit[gox][goy] = 0;
                }
                if(i == 1 && map[gox][goy] == 0 && map[gox][goy-1] == 0 && map[gox-1][goy] == 0){//대각선으로 갈 경우
                    visit[gox][goy] = 1;
                    dfs(2, gox, goy);
                    visit[gox][goy] = 0;
                }
            }
        }
    }
}