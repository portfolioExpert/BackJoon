#include <iostream>
#include <algorithm>
using namespace std;

//문제 5014번
#include <queue>
queue <int> q;
int dp[1000001];
int f, s, g ,u, d;
void bfs(int go);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    bfs(s);
    if(dp[g] == 0)
        cout << "use the stairs";
    else
        cout << dp[g] - 1;
    return 0;
}
void bfs(int go){
    dp[go] = 1;
    q.push(go);
    while(!q.empty()){
        int gogo = q.front();
        q.pop();
        if(gogo + u <= f && dp[gogo+u] == 0){
            dp[gogo + u] = dp[gogo] + 1;
            q.push(gogo+ u);
        }
        if(gogo - d >=1 && dp[gogo-d] == 0){
            dp[gogo-d] = dp[gogo] + 1;
            q.push(gogo-d);
        }
    }
}