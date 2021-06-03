//문제 15683번
#include <cstring>
#include <vector>
vector<pair<pair<int,int>,int>>v;
vector<pair<int,int>>five;
int map[9][9];
int visit[9][9];
//동 남 서 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, result = 987654321;
void dfs(int index);
void fills(int x, int y, int index, int i);
void unfills(int x, int y, int index, int i);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    memset(visit, -1, sizeof(visit));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                v.push_back({{i, j},map[i][j]});
                visit[i][j] = (int)v.size() - 1;
            }
            if(map[i][j] == 6)
                visit[i][j] = 9;
        }
    }
    dfs(0);
    cout << result;
}
void unfills(int x, int y, int index, int i){
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 6)return;
    if(map[x][y] == 0 && visit[x][y] == visit[x -dx[index] * i][y - dy[index] * i])
        visit[x][y] = -1;
    int gox = x + dx[index];
    int goy = y + dy[index];
    unfills(gox, goy, index, i + 1);
}
void fills(int x, int y, int index, int i){
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 6)return;
    if(map[x][y] == 0 && visit[x][y] == -1)
        visit[x][y] = visit[x -dx[index] * i][y - dy[index] * i];
    int gox = x + dx[index];
    int goy = y + dy[index];
    fills(gox, goy, index, i + 1);
}
void dfs(int index){
    if(index == v.size()){
        int cnt = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(visit[i][j] == -1 && map[i][j] == 0)
                    cnt++;
            }
        }
        result = min(result, cnt);
        return;
    }
    int gox = v[index].first.first;
    int goy = v[index].first.second;
    int num = v[index].second;
    for(int i = 0;i<4;i++){
        if(num == 1){
            fills(gox + dx[i], goy + dy[i], i % 4, 1);
        }
        else if(num == 2){
            fills(gox + dx[i], goy + dy[i], i % 4, 1);
            fills(gox + dx[(i+2) % 4], goy + dy[(i+2) % 4], (i+2) % 4, 1);
        }
        else if(num == 3){
            fills(gox + dx[i], goy + dy[i], i % 4, 1);
            fills(gox + dx[(i + 1) % 4], goy + dy[(i + 1) % 4], (i+1) % 4, 1);
        }
        else if(num == 4){
            fills(gox + dx[i], goy + dy[i], i % 4, 1);
            fills(gox + dx[(i + 1) % 4], goy + dy[(i + 1) % 4], (i + 1) % 4, 1);
            fills(gox + dx[(i + 2) % 4], goy + dy[(i + 2) % 4], (i + 2) % 4, 1);
        }
        else if(num == 5){
            fills(gox + dx[i], goy + dy[i], i % 4, 1);
            fills(gox + dx[(i + 1) % 4], goy + dy[(i + 1) % 4], (i + 1) % 4, 1);
            fills(gox + dx[(i + 2) % 4], goy + dy[(i + 2) % 4], (i + 2) % 4, 1);
            fills(gox + dx[(i + 3) % 4], goy + dy[(i + 3) % 4], (i + 3) % 4, 1);
        }
        dfs(index + 1);
        if(num == 1){
            unfills(gox + dx[i], goy + dy[i], i % 4, 1);
        }
        else if(num == 2){
            unfills(gox + dx[i], goy + dy[i], i % 4, 1);
            unfills(gox + dx[(i+2) % 4], goy + dy[(i+2) % 4], (i+2) % 4, 1);
        }
        else if(num == 3){
            unfills(gox + dx[i], goy + dy[i], i % 4, 1);
            unfills(gox + dx[(i+1) % 4], goy + dy[(i+1) % 4], (i+1) % 4, 1);
        }
        else if(num == 4){
            unfills(gox + dx[i], goy + dy[i], i % 4, 1);
            unfills(gox + dx[(i+1) % 4], goy + dy[(i+1) % 4], (i + 1) % 4, 1);
            unfills(gox + dx[(i+2) % 4], goy + dy[(i+2) % 4], (i + 2) % 4, 1);
        }
        else if(num == 5){
            unfills(gox + dx[i], goy + dy[i], i % 4, 1);
            unfills(gox + dx[(i+1) % 4], goy + dy[(i+1) % 4], (i + 1) % 4, 1);
            unfills(gox + dx[(i+2) % 4], goy + dy[(i+2) % 4], (i + 2) % 4, 1);
            unfills(gox + dx[(i+3) % 4], goy + dy[(i+3) % 4], (i + 3) % 4, 1);
        }
    }
}