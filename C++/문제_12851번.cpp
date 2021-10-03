//문제 12851번
#include <queue>
queue <int>q;
int dp[100001];
void bfs();
int result = 1, from, to;
int dis[3] = {2, 1, -1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> from >> to;
    fill_n(dp, 100001, 987654321);
    q.push(from);
    dp[from] = 0;
    bfs();
    cout << dp[to] << "\n" << result;
}
void bfs(){
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int i = 0;i<3;i++){
            int gogo = go;
            if(i == 0)
                gogo*=dis[i];
            else
                gogo+=dis[i];
            if(gogo >= 0 && gogo <= 100000 && dp[gogo] >= dp[go] + 1){
                if(gogo == to){
                    if(dp[gogo] > dp[go] + 1)
                        result = 1;
                    else if(dp[gogo] == dp[go] + 1)
                        result++;
                }
                q.push(gogo);
                dp[gogo] = dp[go] + 1;
            }
        }
    }
}