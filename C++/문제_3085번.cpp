//문제 3085번 사탕 게임 -> 브루트포스, 백트래킹
int n;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[51][51];
char map[51][51];
int result = 0;
int rowdfs(int x, int y, char ch){
    if(x < 0 || x >= n || y < 0 || y >= n || ch != map[x][y] || visit[x][y])
        return 0;
    visit[x][y] = 1;
    //세로
    int row = 0;
    row += rowdfs(x+dx[0], y, ch) + rowdfs(x+dx[1], y, ch) + 1;
    visit[x][y] = 0;
    return row;
}
int coldfs(int x, int y, char ch){
    if(x < 0 || x >= n || y < 0 || y >= n || ch != map[x][y] || visit[x][y])
        return 0;
    visit[x][y] = 1;
    //가로
    int col = 0;
    col += coldfs(x, y+dy[2], ch) + coldfs(x, y+dy[3], ch) + 1;
    visit[x][y] = 0;
    return col;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            for(int k = 0;k<4;k++){
                if(i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < n){
                    char save = map[i][j];
                    map[i][j] = map[i+dx[k]][j+dy[k]];
                    map[i+dx[k]][j+dy[k]] = save;
                    result = max(result, rowdfs(i, j, map[i][j]));
                    result = max(result, coldfs(i, j, map[i][j]));
                    map[i+dx[k]][j+dy[k]] = map[i][j];
                    map[i][j] = save;
                }
            }
        }
    }
    cout << result;
}