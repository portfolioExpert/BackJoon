//문제 1018번 체스판 다시 칠하기 -> 브루트포스
#include <cstring>
#include <queue>
char map[51][51];
char maker[8][8][2];
//0은 W, 1은 B
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0, 1, -1};
int check(int startx, int starty){
    int sum1 = 0, sum2 = 0;
    int index1 = 0, index2=0;
    for(int i = startx; i<startx + 8;i++, index1++){
        index2 = 0;
        for(int j = starty; j<starty + 8;j++,index2++){
            if(map[i][j] != maker[index1][index2][0]){
                sum1++;
            }
        }
    }
    index1 = 0;
    index2 = 0;
    for(int i = startx; i<startx + 8;i++, index1++){
        index2 = 0;
        for(int j = starty; j<starty + 8;j++,index2++){
            if(map[i][j] != maker[index1][index2][1]){
                sum2++;
            }
        }
    }
    return min(sum1, sum2);
}
void bfs(){
    queue<pair<int,int>>q;
    bool visit[9][9];
    memset(visit, 0, sizeof(visit));
    q.push({0, 0});
    maker[0][0][0] = 'W';
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < 8 && gy >= 0 && gy < 8 && visit[gx][gy] == 0){
                visit[gx][gy] = 1;
                q.push({gx,gy});
                if(maker[gox][goy][0] == 'W'){
                    maker[gx][gy][0] = 'B';
                }
                else
                    maker[gx][gy][0] = 'W';
            }
        }
    }
    q.push({0, 0});
    maker[0][0][1] = 'B';
    memset(visit, 0, sizeof(visit));
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx < 8 && gy >= 0 && gy < 8 && visit[gx][gy] == 0){
                visit[gx][gy] = 1;
                q.push({gx,gy});
                if(maker[gox][goy][1] == 'W'){
                    maker[gx][gy][1] = 'B';
                }
                else
                    maker[gx][gy][1] = 'W';
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n, m;
    int result = 987654321;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    bfs();
    for(int i = 0;i<n - 7;i++){
        for(int j = 0;j<m - 7;j++){
            result = min(result, check(i, j));
        }
    }
    cout << result;
}