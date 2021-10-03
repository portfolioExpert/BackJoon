//문제 2564번 경비원 -> BFS
#include <vector>
#include <queue>
int n, m;
int map[101][101];
int dp[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int x, int y){
    queue<pair<int,int>>q;
    dp[x][y] = 0;
    q.push({x, y});
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0; i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx>=0 && gx <= n && gy >= 0 && gy <= m && map[gx][gy] != -1 && dp[gx][gy] > dp[gox][goy] + 1){
                dp[gx][gy] = dp[gox][goy] + 1;
                q.push({gx, gy});
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> m >> n;
    //안에 못가도록 채우기
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            map[i][j] = -1;
        }
    }
    //dp값 큰 수로
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            dp[i][j] = 987654321;
        }
    }
    int cnt;
    cin >> cnt;
    for(int i = 1;i<=cnt;i++){
        int num1 ,num2;
        cin >> num1 >> num2;
        switch(num1){
            case 1:
                map[0][num2] = i;
                break;
            case 2:
                map[n][num2] = i;
                break;
            case 3:
                map[num2][0] = i;
                break;
            case 4:
                map[num2][m] = i;
                break;
            default :
                break;
        }
    }
    int nowx, nowy;
    cin >> nowx >> nowy;
    switch(nowx){
        case 1:
            nowx = 0;
            break;
        case 2:
            nowx = n;
            break;
        case 3:
            nowx = nowy;
            nowy = 0;
            break;
        case 4:
            nowx = nowy;
            nowy = m;
            break;
        default :
            break;
    }
    bfs(nowx, nowy);
    int sum = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0 ;j<=m;j++){
            if(dp[i][j] != 987654321 && map[i][j] != 0)
                sum+=dp[i][j];
        }
    }
    cout << sum;
}