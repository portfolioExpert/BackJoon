//문제 1167번
#include <vector>
#include <cstring>
vector<pair<int,int>> node[100001];
bool visit[100001];
int result, endpoint;
void dfs(int now, int length);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int now, next, val;
        cin >> now;
        while(1){
            cin >> next;
            if(next == -1)break;
            cin >> val;
            node[now].push_back({next, val});
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    result = 0;
    dfs(endpoint, 0);
    cout << result;
}
void dfs(int now, int length){
    visit[now] = 1;
    if(result <= length){
        result = length;
        endpoint = now;
    }
    for(int i = 0;i<node[now].size();i++){
        //무조건 endpoint를 여기다 두면 안됨
        if(visit[node[now][i].first] == 0){
            dfs(node[now][i].first, length + node[now][i].second);
        }
    }
}