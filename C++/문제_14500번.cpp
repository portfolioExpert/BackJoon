//문제 14500번
//테트로미노는 dfs로 풀이 된다
int map[501][501];
int visit[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dfs(int x, int y, int cnt);
int fx(int x, int y);
int val = 0, n, m;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visit[i][j] = 1;
            val = max(val, dfs(i, j, 1));
            val = max(val, fx(i, j));
            visit[i][j] = 0;
        }
    }
    cout << val;
}
int dfs(int x, int y, int cnt){
    if(cnt == 4){
        return map[x][y];
    }
    int sum = 0;
    for(int i = 0;i<4;i++){
        int gx = x + dx[i];
        int gy = y + dy[i];
        if(gx >= 0 && gx < n && gy >= 0 && gy < m && visit[gx][gy] == 0){
            visit[gx][gy] = 1;
            sum = max(sum, map[x][y] + dfs(gx, gy, cnt + 1));
            visit[gx][gy] = 0;
        }
    }
    return sum;
}
int fx(int x, int y){
    int value = 0;
    if(x-1>=0 && y-1 >=0 && y+1 < m)
        value = max(value, map[x][y] + map[x-1][y] + map[x][y-1] + map[x][y+1]);
    if(x-1>=0 && x+1 < n && y+1<m)
        value = max(value, map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y+1]);
    if(y-1>=0 && y+1 < m && x+1 < n)
        value = max(value, map[x][y] + map[x][y-1] + map[x][y+1] + map[x+1][y]);
    if(x-1>= 0 && x+1 < n && y-1 >= 0)
        value = max(value, map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y-1]);
    return value;
}