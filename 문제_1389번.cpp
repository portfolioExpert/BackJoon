//문제 1389번
#include <vector>
#include <queue>
#include <cstring>
queue<int>q;
vector<int>v[101];
int visit[101];
int result = 987654321, n, val = 0;
int bfs(int go);
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    for(int i = 1;i<=n;i++){
        memset(visit, -1 , sizeof(visit));
        q.push(i);
        int value = bfs(i);
        if(result > value){
            val = i;
            result = value;
        }
    }
    cout << val;
}
int bfs(int go){
    int val = 0;
    visit[go] = 0;
    while(!q.empty()){
        int gogo = q.front();
        q.pop();
        for(int y : v[gogo]){
            if(visit[y] == -1){
                visit[y] = visit[gogo] + 1;
                q.push(y);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        val+=visit[i];
    }
    return val;
}