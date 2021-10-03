#include <iostream>
#include <algorithm>
using namespace std;

//문제 13549번
#include <queue>
queue<int>q;
int dp[100001];
bool visit[100001];
int dx[3] = {2, 1 ,-1}, from , to;
void bfs(int from);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> from >> to;
    fill_n(dp, 100001, 987654321);
    q.push(from);
    bfs(from);
    cout << dp[to];
}
//bfs로 풀면 가중치를 못 쳐주어 dx의 인덱스를 2 1 -1로 해둬야 한다.
void bfs(int from){
    dp[from] = 0;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i = 0;i<3;i++){
            int go;
            int val;
            if(i != 0){
                go = pos + dx[i];
                val = dp[pos] + 1;
            }
            else{
                go = pos * dx[i];
                val = dp[pos];
            }
            if(go >= 0 && go <= 100000 && val < dp[go]){
                dp[go] = val;
                q.push(go);
            }
        }
    }
}