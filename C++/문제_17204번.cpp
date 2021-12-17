//문제 17204번 죽음의 게임-> BFS
#include <queue>
#include <vector>
vector<int>v[201];
int result[201];
int n, k;
void bfs(int go, int cnt){
    result[go] = 0;
    queue<int>q;
    q.push(go);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i<(int)v[now].size();i++){
            int next = v[now][i];
            if(result[next] > result[now] + 1){
                result[next] = result[now] + 1;
                q.push(next);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v[i].push_back(num);
        result[i] = 987654321;
    }
    bfs(0,0);
    if(result[k] == 987654321)
        cout << -1;
    else
        cout << result[k];
}