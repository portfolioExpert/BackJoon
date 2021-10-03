#include <iostream>
#include <algorithm>
using namespace std;

//문제 1261번
#include <queue>
priority_queue <pair<int, pair<int,int>>> pq;
char map[101][101];
int dp[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n , m;
void dijkstra();
int main(){
    int i, j;
    cin >> m >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> map[i][j];
        }
        fill_n(dp[i], m + 1, 1000000000);
    }
    pq.push({0, {1,1}});
    dijkstra();
    cout << dp[n][m];
    return 0;
}
void dijkstra(){
    dp[1][1] = 0;
    while(!pq.empty()){
        int gox = pq.top().second.first;
        int goy = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();
        if(dp[gox][goy] < cost)continue;
        for(int i=0;i<4;i++){
            int gx = gox + dx[i];
            int gy = goy + dy[i];
            int wei = cost;
            if(gx>=1 && gx <= n && gy>=1 && gy <= m){
                if(map[gx][gy] == '1')
                    wei+=1;
                if(wei < dp[gx][gy]){
                    dp[gx][gy] = wei;
                    pq.push({-wei, {gx,gy}});
                }
            }
        }
    }
}