//문제 17471번 게리맨더링 -> 백트래킹 + BFS, 브루트포스
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
int connected[11][11];
int n, result = 987654321;
int population[11];
int visit[11];
//bfs는 연결요소 확인 용
bool bfs(vector<int>v){
    queue<int>q;
    q.push(v[0]);
    bool visited[11];
    memset(visited, 0, sizeof(visited));
    visited[v[0]] = 1;
    bool flag = visit[v[0]];
    while(!q.empty()){
        int go = q.front();
        q.pop();
        for(int i = 1;i<=n;i++){
            //연결되었고, 내가 연결시킬 flag와 같은 분류인지, 방문하지 않은 곳
            if(connected[go][i] == 1 && visit[i] == flag && visited[i] == 0){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    for(int y : v){
        if(visited[y] == 0)
            return false;
    }
    return true;
}
void dfs(int index, int cnt){
    if(index == n + 1)
        return;
    if(cnt >= 1){
        //선거구 나누기
        vector<int>a, b;
        for(int i = 1;i<=n;i++){
            if(visit[i] == 1)
                a.push_back(i);
            else
                b.push_back(i);
        }
        //하나라도 0이라면 나누어진게 아님
        if(a.size() != 0 && b.size() != 0){
            //각 선거구가 연결되었는지 확인
            if(bfs(a) && bfs(b)){
                int suma = 0, sumb = 0;
                for(int i = 1;i<=n;i++){
                    if(visit[i] == 1)
                        suma+=population[i];
                    else
                        sumb+=population[i];
                }
                result = min(result, abs(suma - sumb));
            }
        }
    }
    for(int i = index;i<=n;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            dfs(i, cnt + 1);
            visit[i] = 0;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> population[i];
    }
    for(int i = 1;i<=n;i++){
        int m;
        cin >> m;
        for(int j = 0;j<m;j++){
            int num;
            cin >> num;
            connected[i][num]= 1;
            connected[num][i] = 1;
        }
    }
    dfs(1, 0);
    if(result == 987654321)
        cout << -1;
    else
        cout << result;
}