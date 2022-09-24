//문제 1325번 효율적인 해킹 -> BFS
#include <vector>
#include <cstring>
#include <queue>
bool visit[10001];
int cnt[10001];
vector<int>result;
int bfs(int node, vector<int> v[]){
    int res = 1;
    visit[node] = 1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int y : v[now]){
            if(visit[y] == 0){
                visit[y] = 1;
                q.push(y);
                res++;
            }
        }
    }
    return res;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    vector<int> v[10001];
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int from, to;
        cin >> from >> to;
        v[to].push_back(from);
    }
    for(int i = 1;i<=10000;i++){
        memset(visit, 0, sizeof(visit));
        cnt[i] = bfs(i, v);
        if(result.size() == 0 || cnt[result[0]] < cnt[i]){
            result.clear();
            result.push_back(i);
        }
        else if(cnt[result[0]] == cnt[i]){
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    for(int y : result){
        cout << y << " ";
    }
}