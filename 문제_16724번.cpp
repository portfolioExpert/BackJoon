//문제 16724번 피리 부는 사나이 -> 유니온 파인드, DFS
int visit[1001][1001];
char map[1001][1001];
int n, m, cnt = 1;
void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)
        return;
    int gx = x;
    int gy = y;
    if(map[x][y] == 'D')
        gx++;
    else if(map[x][y] == 'R')
        gy++;
    else if(map[x][y] == 'U')
        gx--;
    else
        gy--;
    //이미 값이 있다면
    if(visit[gx][gy] != 0){
        //그 값이 현재 cnt와 같다면 다른 분류로 넣어주기 위해서 증가
        if(visit[gx][gy] == cnt)cnt++;
        //옮길값에 부모를 현재 위치에 넣어서 merge 시켜줌
        visit[x][y] = visit[gx][gy];
        return;
    }
    visit[x][y] = cnt;
    dfs(gx, gy);
    visit[x][y] = visit[gx][gy];
}
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
            if(visit[i][j] == 0){
                dfs(i, j);
            }
        }
    }
    cout << cnt - 1;
}