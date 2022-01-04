//문제 1194번 달이 차오른다, 가자. -> BFS, 비트마스킹
#include <queue>
#include <vector>
int n, m;
char map[51][51];
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int,pair<int,int>>>q;
int dp[51][51][64];
int result = 987654321;
void bfs(){
    while(!q.empty()){
        int visit = q.front().first;
        int gox = q.front().second.first;
        int goy = q.front().second.second;
        q.pop();
        //목적지
        if(map[gox][goy] == '1')
            result = min(result, dp[gox][goy][visit]);
        for(int i = 0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            if(gx >= 0 && gx < n && gy >= 0 && gy < m && map[gx][gy] != '#' && dp[gx][gy][visit] == 0){
                //빈 곳일 때
                if(map[gx][gy] == '.' || map[gx][gy] == '1' || map[gx][gy] == '0'){
                    q.push({visit, {gx,gy}});
                    dp[gx][gy][visit] = dp[gox][goy][visit] + 1;
                }
                //열쇠
                else if(map[gx][gy] >= 'a' && map[gx][gy] <= 'f'){
                    int visited = visit | (1 << (map[gx][gy] - 'a'));
                    q.push({visited, {gx,gy}});
                    dp[gx][gy][visited] = dp[gox][goy][visit] + 1;
                }
                //문일 때
                else if(map[gx][gy] >= 'A' && map[gx][gy] <= 'F'){
                    //열쇠가 있다면
                    if(visit & (1 << (map[gx][gy] - 'A'))){
                        q.push({visit, {gx,gy}});
                        dp[gx][gy][visit] = dp[gox][goy][visit] + 1;
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
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == '0'){
                q.push({0,{i, j}});
            }
        }
    }
    bfs();
    if(result == 987654321)
        cout << -1;
    else
        cout << result;
}