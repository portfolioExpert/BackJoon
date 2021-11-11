//문제 17836번 공주님을 구해라! -> BFS
#include <queue>
int map[101][101];
int dp[101][101][2];
bool flag = false;
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0, 1, -1};
int n, m;
void bfs(){
    queue<pair<pair<int,int>,bool>>q;
    dp[1][1][0] = 0;
    q.push({{1, 1}, 0});
    while(!q.empty()){
        int gox = q.front().first.first;
        int goy = q.front().first.second;
        bool state = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 1 && gx <= n && gy >= 1 && gy<= m){
                if(dp[gx][gy][state] > dp[gox][goy][state] + 1){
                    //검이나 이미 습득 상태
                    if(state || map[gx][gy] == 2){
                        dp[gx][gy][1] = dp[gox][goy][state] + 1;
                        q.push({{gx, gy},1});
                    }
                    else if(!state && map[gx][gy] == 0){
                        dp[gx][gy][0] = dp[gox][goy][0] + 1;
                        q.push({{gx,gy},0});
                    }
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin >> n >> m >> t;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> map[i][j];
            dp[i][j][0] = 987654321;
            dp[i][j][1] = 987654321;
        }
    }
    bfs();
    if(dp[n][m][0] <= t || dp[n][m][1] <= t)
        cout << min(dp[n][m][0],dp[n][m][1]);
    else
        cout << "Fail";
}