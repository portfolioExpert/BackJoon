//문제 2665번
#include <queue>
queue<pair<int,int>>q;
char map[51][51];
int dp[51][51];
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dijkstra();
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
        fill_n(dp[i], n, 987654321);
    }
    q.push({0, 0});
    dp[0][0] = 0;
    dijkstra();
    cout << dp[n-1][n-1];
}
void dijkstra(){
    while(!q.empty()){
        int gox = q.front().first;
        int goy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int gx = gox+dx[i];
            int gy = goy+dy[i];
            if(gx>=0 && gx < n && gy >= 0 && gy < n){
                if(map[gx][gy] == '0' && dp[gx][gy] > dp[gox][goy] + 1){
                    q.push({gx, gy});
                    dp[gx][gy] = dp[gox][goy] + 1;
                }
                else if(map[gx][gy] == '1' && dp[gx][gy] > dp[gox][goy]){
                    q.push({gx, gy});
                    dp[gx][gy] = dp[gox][goy];
                }
            }
        }
    }
}