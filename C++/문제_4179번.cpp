//문제 4179번
#include <queue>
#define INF 987654321
queue<pair<int,int>>fq;
queue<pair<int,int>>hq;
char map[1001][1001];
int fvisit[1001][1001];
int hvisit[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c, result = INF;
void fbfs();
void hbfs();
int bfs();
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j] == 'F'){
                fq.push({i, j});
                fvisit[i][j] = 1;
            }
            if(map[i][j] == 'J'){
                hq.push({i, j});
                hvisit[i][j] = 1;
            }
        }
    }
    fbfs();
    hbfs();
    if(result == INF)
        cout << "IMPOSSIBLE";
    else
        cout << result;
}
void fbfs(){
    while(!fq.empty()){
        int gox = fq.front().first;
        int goy = fq.front().second;
        fq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < r && gy >= 0 && gy < c && fvisit[gx][gy] == 0 && map[gx][gy] == '.'){
                fq.push({gx, gy});
                fvisit[gx][gy] = fvisit[gox][goy] + 1;
            }
        }
    }
}
void hbfs(){
    while(!hq.empty()){
        int gox = hq.front().first;
        int goy = hq.front().second;
        hq.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx < 0 || gx >= r || gy < 0 || gy >= c){
                result = hvisit[gox][goy];
                return;
            }
            if(gx >= 0 && gx < r && gy >= 0 && gy < c && hvisit[gx][gy] == 0 && map[gx][gy] == '.' && (fvisit[gx][gy] > hvisit[gox][goy] + 1 || fvisit[gx][gy] == 0)){
                hq.push({gx, gy});
                hvisit[gx][gy] = hvisit[gox][goy] + 1;
            }
        }
    }
}