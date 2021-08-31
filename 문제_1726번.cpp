//문제 1726번 로봇 -> BFS 응용
#include<queue>
int n, m;
int startx, starty, startdir, goalx, goaly, goaldir;
bool map[101][101];
int dp[101][101][5];
queue<pair<pair<int,int>,int>>q;
//1 동, 2 서, 3 남, 4 북
int dx[5] = {0, 0, 0, 1,-1};
int dy[5] = {0, 1, -1, 0, 0};
void bfs(){
    dp[startx][starty][startdir] = 0;
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        int left = 0 , right = 0, against = 0;
        //현재 방향에 대한 정보를 기반으로 왼쪽 오른쪽 반대 정의
        switch(dir){
            case 1 : left = 4;
                right = 3;
                against = 2;
                break;
            case 2 : left = 3;
                right = 4;
                against = 1;
                break;
            case 3 : left = 1;
                right = 2;
                against = 4;
                break;
            case 4 : left = 2;
                right = 1;
                against = 3;
                break;
        }
        int direct[4] = {dir, left, right, against};
        for(int i = 1;i<=3;i++){
            int gx = gox + dx[dir] * i;
            int gy = goy + dy[dir] * i;
            if(dp[gx][gy][dir] != 987654321)
                continue;
            if(gx >= 1 && gx <= n && gy >= 1 && gy <= m && map[gx][gy] == 0){
                dp[gx][gy][dir] = dp[gox][goy][dir] + 1;
                q.push({{gx,gy}, dir});
            }
            else
                break;
        }
        //방향바꿔서 큐에 넣기
        for(int i = 0;i<4;i++){
            //이거 추가하기전엔 66% 추가하니 AC
            if(dp[gox][goy][direct[i]] != 987654321)continue;
            if(dir != direct[i] && dp[gox][goy][direct[i]] > dp[gox][goy][dir]){
                if(i == 1 || i == 2){
                    dp[gox][goy][direct[i]] = dp[gox][goy][dir] + 1;
                    q.push({{gox, goy}, direct[i]});
                }
                else if(i == 3){
                    dp[gox][goy][direct[i]] = dp[gox][goy][dir] + 2;
                    q.push({{gox, goy}, direct[i]});
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> map[i][j];
            for(int k = 1;k<=4;k++){
                dp[i][j][k] = 987654321;
            }
        }
    }
    cin >> startx >> starty >> startdir;
    cin >> goalx >> goaly >> goaldir;
    q.push({{startx, starty}, startdir});
    bfs();
    cout << dp[goalx][goaly][goaldir];
    return 0;
}