//문제 16236번
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
queue<pair<int,int>> q;
queue<pair<int, int>>moveq;
vector<pair<pair<int,int>, int>>v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[21][21];
int dp[21][21];
int n, d = 987654321, result, size = 2, cnt = 0;
int eatx = 100, eaty = 100;
void move(int x, int y);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        if(cnt == size){
            size++;
            cnt = 0;
        }
        move(gox, goy);
        cnt++;
    }
    cout << result;
}
void move(int x, int y){
    moveq.push({x, y});
    memset(dp, -1, sizeof(dp));
    eatx = 100;
    eaty = 100;
    dp[x][y] = 0;
    map[x][y] = 0;
    int d = 987654321;
    while(!moveq.empty()){
        int gox = moveq.front().first;
        int goy = moveq.front().second;
        moveq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < n && size >= map[gx][gy] && dp[gx][gy] == -1){
                moveq.push({gx, gy});
                dp[gx][gy] = dp[gox][goy] + 1;
                if(map[gx][gy] >= 1 && map[gx][gy] < size){
                    //거리가 작으면 무조건 먹는다
                    if(d > dp[gx][gy]){
                        d = dp[gx][gy];
                        eatx = gx;
                        eaty = gy;
                    }
                    //거리가 같으면
                    else if(d == dp[gx][gy]){
                        //위쪽 부터
                        if(eatx > gx){
                            eatx = gx;
                            eaty = gy;
                        }
                        //위도 같으면 제일 왼쪽
                        else if(eatx == gx && eaty > gy){
                            eatx = gx;
                            eaty = gy;
                        }
                    }
                }
            }
        }
    }
    //먹을 것을 정하고 먹는 작업
    if(eatx != 100){
        result+=d;
        map[eatx][eaty] = 0;
        q.push({eatx, eaty});
    }
}